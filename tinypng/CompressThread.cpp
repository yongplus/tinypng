#include "CompressThread.h"
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

CompressThread::CompressThread(QThread* td, const configItem& cfg, QString ort)
	: QObject(NULL)
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

void CompressThread::addTask(const int r, const QString& rt, QString& ph) {
	row = r;
	root = rt;
	path = ph;
	state = 1;
	this->eventloop->quit();
}

void CompressThread::quit() {
	state = -1;
	this->eventloop->quit();
	this->thread->quit();
}

void CompressThread::run() {


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


		QUrl url("https://api.tinify.com/shrink");


		QNetworkRequest req(url);
		req.setHeader(QNetworkRequest::ContentTypeHeader, "application/octet-stream");

		req.setRawHeader("Authorization", "Basic " + QString("%1:%2").arg(config.mail, config.key).toLocal8Bit().toBase64());
		QFile file(this->root + this->path);
		if (!file.open(QIODevice::ReadWrite)) {
			this->emitError("打开文件出错");
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
		timer.start(15000);
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
				this->download(bytes);
			}
			reply->close();
		}
		else {
			disconnect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
			reply->abort();
			this->emitError(QString("请求压缩接口超时"));
		}
	}


}

void CompressThread::download(const QByteArray& bytes) {

	QJsonDocument doc = QJsonDocument::fromJson(bytes);
	QJsonObject jsonobj = doc.object();
	QVariantMap mainMap = jsonobj.toVariantMap();
	if (!mainMap.contains("output")) {
		this->emitError(QString("返回结果错误:%1").arg(QString(bytes)));
		return;
	}
	qDebug() << mainMap["output"].toMap()["url"].toString();
	QString url = mainMap["output"].toMap()["url"].toString();

	QTimer timer;
	timer.setSingleShot(true);

	QEventLoop loop;


	QNetworkRequest req(url);
	QNetworkReply* reply = mgr->get(req);

	connect(&timer, SIGNAL(timeout()), &loop, SLOT(quit()));
	connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));

	timer.start(15000);
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

			reply->deleteLater();

			if (file.open(QIODevice::ReadWrite)) {
				file.write(binary);
				file.close();
			}
			else {

				this->emitError(QString("创建文件失败:" + file.errorString()));
				return;
			}

			CompressThreadResult result;
			result.errcode = 0;
			result.size = binary.length();
			result.path = outputPath;
			result.row = row;
			QVariant variant;
			variant.setValue(result);
			emit finished(variant);

		}
		else {
			QByteArray binary = reply->readAll();
			this->emitError(QString("下载图片返回CODE：%1,Body:%2").arg(code).arg(QString(binary)));
		}
		reply->close();

	}
	else {
		// timeout
		disconnect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
		reply->abort();
		this->emitError("下载压缩图片超时");
	}
}

void CompressThread::setAuthentication(QNetworkReply* reply, QAuthenticator* authenticator) {
	qDebug() << "to set auth info";
}

void CompressThread::emitError(const QString& msg, const int& errcode) {
	CompressThreadResult result;
	result.errcode = errcode;
	result.errmsg = msg;
	result.row = this->row;

	QVariant variant;
	variant.setValue(result);
	if (state != -1) {
		emit finished(variant);
	}
}


CompressThread::~CompressThread()
{
	delete eventloop;
	delete mgr;
	qDebug() << "子线程析构函数执行";
}
