#pragma once

#include <QObject>
#include <QEventLoop>
#include <QMutex>
#include <QThread>
#include "MyTableView.h"
#include "TableModel.h"
#include "Console.h"
#include "Config.h"
#include "Compress.h"
#include <QElapsedTimer>


class Dispatcher : public QObject
{
	Q_OBJECT

public:
	Console* console;
	MyTableView* tableview;
	TableModel* model;
	configItem config;
	int offsetRow;
	int runThreadNum;
	int finishNum;
	int failedNum;
	int totalRowNum;
	float totalsize; //原大小
	float totalLessSize; //压缩总大小
	QElapsedTimer* elapsedTimer;
	QEventLoop* loop;
	QMutex* mutex;
	QList<Compress*> workers;
	QThread* thread;


	Dispatcher(QThread* thread, Console* console, MyTableView* tableview);

	void nextTask(Compress* thread);
	~Dispatcher();
	void quit();
private:
	int getUnhandleNum();


signals:
	void started();

public slots:
	void run();
	void doneTask(QVariant);
	void finished();
};
