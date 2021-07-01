#pragma once

#include <QObject>
#include <QEventLoop>
#include <QMutex>
#include <QThread>
#include "MyTableView.h"
#include "TableModel.h"
#include "Console.h"
#include "Config.h"
#include "CompressThread.h"
#include <QElapsedTimer>


class CompressThreadDispatcher : public QObject
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
	float totalsize; //原大小
	float totalLessSize; //压缩总大小
	QElapsedTimer* elapsedTimer;
	QEventLoop* loop;
	QMutex* mutex;
	QList<CompressThread*> workers;
	QThread* thread;


	CompressThreadDispatcher(QThread* thread, Console* console, MyTableView* tableview);

	void nextTask(CompressThread* thread);
	~CompressThreadDispatcher();
	void quit();



public slots:
	void run();
	void doneTask(QVariant);
	void finished();
};
