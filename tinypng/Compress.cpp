#include "Compress.h"
#include <QFile>
#include <QObject>
#include <QEventLoop>
#include <QTimer>
#include <QByteArray>
#include <QThread>
#include <QVariant>
#include <QFileInfo>
#include <QDir>
#include <QNetworkProxy>
#include <QRandomGenerator>

Compress::Compress(QThread* td, const configItem& cfg, QString ort)
	: QObject(NULL),
	row(0),
	root(""),
	path(""),
	state(0)
{
	thread = td;
	config = cfg;
	outputRoot = ort;
	state = 0;
	eventloop = new QEventLoop(this);

	mgr = new QNetworkAccessManager(this);
	if (config.proxy.length() > 0) {

		QUrl url(config.proxy);
		qDebug() << config.proxy << url.host() << url.port();
		QNetworkProxy proxy;
		proxy.setType(QNetworkProxy::HttpProxy);
		proxy.setHostName(url.host());
		proxy.setPort(url.port());
		mgr->setProxy(proxy);
	}

}

void Compress::addTask(const int r, const QString& rt, QString& ph) {
	row = r;
	root = rt;
	path = ph;
	state = 1;
	this->eventloop->quit();
}

void Compress::quit() {
	state = -1;
	this->eventloop->quit();
	this->thread->quit();
}

void Compress::run() {


	while (true) {

		if (state == 0) {

			//qDebug() << "休眠中";

			//QTimer::singleShot(50, eventloop, SLOT(quit()));
			eventloop->exec();
			//QTimer::singleShot(10, eventloop, SLOT(quit()));
			//eventloop->exec();
			continue;
		}



		if (state == -1) {
			state = -2;
			break;
		}
		state = 0;


		QString ip;
		QNetworkRequest req;
		if (config.tinyReqMode == TinyReqMode::Web) {
			QUrl url("https://tinypng.com/backend/opt/shrink");
			req = QNetworkRequest(url);
			req.setHeader(QNetworkRequest::UserAgentHeader, "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.107 Safari/537.36");
			req.setHeader(QNetworkRequest::ContentTypeHeader, "application/octet-stream");
			ip = this->generateIp();
			req.setRawHeader("x-forwarded-for", ip.toUtf8());
		}
		else {
			QUrl url("https://api.tinify.com/shrink");
			req = QNetworkRequest(url);
			req.setRawHeader("Authorization", "Basic " + QString("%1:%2").arg(config.mail, config.key).toLocal8Bit().toBase64());
		}
		qDebug() << "--------------------->:" << this->root + this->path;
		QFile file(this->root + this->path);
		if (!file.open(QIODevice::ReadOnly)) {
			this->emitError("打开文件出错:" + file.errorString());
			continue;
		}
		QByteArray binary = file.readAll();
		file.close();

		QTimer timer;
		timer.setSingleShot(true);
		QEventLoop loop;


		QNetworkReply* reply = mgr->post(req, binary);

		connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
		connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
		//double timeout = 20 + double(binary.length()) * double(20) / double(1048576); //超时时间：起始时间10s + 文件大小 * (预设每byte耗时)
		int timeout = 60 * 3; //服务器响应太慢了，不适合较短超时时间
		timer.start(timeout * 1000);
		loop.exec();


		if (timer.isActive()) {
			timer.stop();
			QVariant variant = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);
			int nStatusCode = variant.toInt();
			if (reply->error() != QNetworkReply::NoError) {
				// 错误处理
				QByteArray body = reply->readAll();
				this->emitError(QString("Error String：%1,%2").arg(reply->errorString()).arg(QString(body)));
			}
			else if (nStatusCode == 0) {
				this->emitError(QString("请求压缩接口被驳回或无网络"));
			}
			else {
				// 根据状态码做进一步数据处理
				QByteArray bytes = reply->readAll();
				qDebug() << bytes << nStatusCode;

				this->download(bytes, ip);

			}
		}
		else {
			disconnect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
			reply->abort();
			this->emitError(QString("请求压缩接口超时(%1s)").arg(timeout));
		}
		reply->close();
		delete reply;
		//reply->deleteLater();
	}


}

void Compress::download(const QByteArray& bytes, const QString& ip) {

	QJsonDocument doc = QJsonDocument::fromJson(bytes);
	QJsonObject jsonobj = doc.object();
	QVariantMap mainMap = jsonobj.toVariantMap();
	if (!mainMap.contains("output")) {
		this->emitError(QString("返回结果错误:%1").arg(QString(bytes)));
		return;
	}
	qDebug() << mainMap["output"].toMap()["url"].toString();
	QString url = mainMap["output"].toMap()["url"].toString();
	if (url.isEmpty()) {
		this->emitError(QString("返回结果错误:%1").arg(QString(bytes)));
		return;
	}

	int size = mainMap["output"].toMap()["size"].toInt();
	//float timeout = 15 + size * double(10) / double(1048576); //超时时间：起始时间7s + 文件大小 * (预设每byte耗时)
	float timeout = 60 * 2; //服务器偶尔响应太慢
	QTimer timer;
	timer.setSingleShot(true);

	QEventLoop loop;


	QNetworkRequest req(url);
	if (!ip.isEmpty()) {
		req.setRawHeader("x-forwarded-for", ip.toUtf8());
	}
	QNetworkReply* reply = mgr->get(req);

	connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
	connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));

	timer.start(timeout * 1000);
	loop.exec();


	if (timer.isActive()) {
		timer.stop();
		int code = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();


		if (code == 200) {

			QByteArray binary = reply->readAll();
			QString outputPath;
			outputPath = this->outputRoot + this->path;

			QDir dir = QFileInfo(outputPath).absoluteDir();
			if (!dir.exists() && !dir.mkpath(".")) {
				this->emitError(QString("创建目录失败:" + dir.path()));
				return;
			}
			QFile file(outputPath);

			if (file.open(QIODevice::WriteOnly | QFile::Truncate)) {
				qDebug() << "wrote:" << file.write(binary);
				file.close();

				CompressResult result;
				result.errcode = 0;
				result.size = binary.length();
				result.path = outputPath;
				result.row = row;
				QVariant variant;
				variant.setValue(result);
				emit finished(variant);
			}
			else {
				this->emitError(QString("创建文件失败:" + file.errorString()));
			}
		}
		else {

			QByteArray binary = reply->readAll();
			this->emitError(QString("下载图片返回CODE：%1,Body:%2").arg(code).arg(QString(binary)));
		}
	}
	else {
		// timeout
		disconnect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
		reply->abort();
		this->emitError("下载压缩图片超时");
	}
	reply->close();
	delete reply;
}

void Compress::setAuthentication(QNetworkReply* reply, QAuthenticator* authenticator) {
	qDebug() << "to set auth info";
}

void Compress::emitError(const QString& msg, const int& errcode) {
	CompressResult result;
	result.errcode = errcode;
	result.errmsg = msg;
	result.row = this->row;

	QVariant variant;
	variant.setValue(result);
	emit finished(variant);
}


QString Compress::generateIp() {
	qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
	QStringList  seg = QStringList();
	for (int i = 0; i < 4; i++)
	{
		//int num = 1 + qrand() % 255;
		int num = QRandomGenerator::global()->bounded(1, 255);
		seg.append(QString::number(num));
	}
	return seg.join(".");
}

Compress::~Compress()
{
	delete eventloop;
	delete mgr;
	qDebug() << "子线程析构函数执行";
}
