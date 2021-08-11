#pragma once

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantMap>
#include <QEventLoop>
#include "Config.h"

struct CompressThreadResult {
	int errcode;
	QString errmsg;
	int size;
	int row;
	QString path;
};


Q_DECLARE_METATYPE(CompressThreadResult);

class CompressThread : public QObject
{
	Q_OBJECT

public:
	int row;
	QString root;
	QString outputRoot;
	QString path;
	configItem config;
	QThread* thread;
	int state; // 0 新任务待处理 -1 退出 
	QEventLoop* eventloop;
	QNetworkAccessManager* mgr;
	CompressThread(QThread* thread, const configItem& config, QString);
	~CompressThread();

	void addTask(int row, const QString& root, QString& path);
	void quit();

private:
	void download(const QByteArray&, const QString&);
	void emitError(const QString& msg, const int& errcode = 1);
	QString generateIp();

public slots:
	void run();
	void setAuthentication(QNetworkReply*, QAuthenticator*);


signals:

	void finished(QVariant);

};
