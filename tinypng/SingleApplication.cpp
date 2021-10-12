#include "SingleApplication.h"
#include <QLocalSocket>
#include <QLocalServer>
#include <QFile>
#include <QTextStream>
#include <QWidget>
#include <QDebug>


SingleApplication::SingleApplication(int& argc, char** argv) :
	QApplication(argc, argv),
	m_bRunning(false),
	m_pServer(Q_NULLPTR),
	m_widget(Q_NULLPTR)
{
	setOrganizationName(QStringLiteral("yongplus"));
	setApplicationName(QLatin1String("tinypng"));


	QString strServerName = QString("%1%2")
		.arg(QCoreApplication::organizationName())
		.arg(QCoreApplication::applicationName());

	QLocalSocket socket;
	socket.connectToServer(strServerName);

	if (socket.waitForConnected(500)) {
		QTextStream stream(&socket);
		QStringList args = QCoreApplication::arguments();
		QString strArg = (args.count() > 1) ? args.last() : "";
		stream << strArg;
		stream.flush();

		qDebug() << "Have already connected to server.";
		socket.waitForBytesWritten();
		m_bRunning = true;
	}
	else {
		// 如果不能连接到服务器,则创建
		m_pServer = new QLocalServer(this);

		connect(m_pServer, SIGNAL(newConnection()), this, SLOT(newLocalConnection()));

		if (m_pServer->listen(strServerName)) {
			// 防止程序崩溃,残留进程服务,直接移除
			if ((m_pServer->serverError() == QAbstractSocket::AddressInUseError)
				&& QFile::exists(m_pServer->serverName())) {
				QFile::remove(m_pServer->serverName());
				m_pServer->listen(strServerName);
			}
		}
	}

}

SingleApplication::~SingleApplication()
{

}

bool SingleApplication::isRunning()
{
	return m_bRunning;
}


void SingleApplication::setSingleMainWindow(QWidget* w)
{
	m_widget = w;
}


void SingleApplication::newLocalConnection()
{
	QLocalSocket* pSocket = m_pServer->nextPendingConnection();
	if (pSocket != Q_NULLPTR) {
		pSocket->waitForReadyRead(1000);

		QTextStream in(pSocket);
		QString strValue;
		in >> strValue;
		delete pSocket;
		pSocket = Q_NULLPTR;

		//如果窗口不为空,则前端显示
		//核心代码
		if (m_widget) {
			this->setActiveWindow(m_widget);
			m_widget->raise();
			if (m_widget->windowState().testFlag(Qt::WindowMaximized) == true) {
				m_widget->showMaximized();
			}
			else {
				m_widget->showNormal();
			}

			m_widget->activateWindow();
		}
	}
}
