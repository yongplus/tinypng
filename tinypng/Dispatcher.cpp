﻿#include "Dispatcher.h"
#include <QListIterator>
#include <QTimer>

Dispatcher::Dispatcher(QThread* td, Console* c, MyTableView* t)
{
	console = c;
	tableview = t;
	model = (TableModel*)t->selectionModel()->model();
	loop = nullptr;
	finishNum = 0;
	offsetRow = 0;
	runThreadNum = 0;
	this->mutex = new QMutex();
	workers = QList<Compress*>();
	thread = td;
	elapsedTimer = new QElapsedTimer();

}

void Dispatcher::run() {
	config = Config(this).get();
	offsetRow = 0;
	finishNum = 0;
	totalsize = 0;
	failedNum = 0;
	totalLessSize = 0;
	totalRowNum = this->getUnhandleNum();
	if (totalRowNum == 0) {
		this->console->errorSignal("没有可压缩的文件");
		this->thread->quit();
		return;
	}

	runThreadNum = qMin(QThread::idealThreadCount() * 2, 12); //避免官方服务器出问题，最大12个线程

	elapsedTimer->start();
	qDebug() << "total row:" << totalRowNum << runThreadNum << qMin(runThreadNum, totalRowNum);

	runThreadNum = qMin(runThreadNum, totalRowNum);

	this->console->tipSignal("\n开始压缩");
	QString outputRoot = this->model->getRow(0).root;
	if (config.outputMode == OutputMode::NewDir && this->model->getRow(0).root != "") {
		outputRoot.append("_tiny");
		emit this->console->tipSignal(QString("输出目录：<a href=\"file:///%1\" style=\"color:#FFFFFF\">%2</a>\n").arg(outputRoot).arg(outputRoot));
	}
	for (int i = 0; i < runThreadNum; i++) {

		QThread* wokrer_thread = new QThread(this);

		Compress* worker = new Compress(wokrer_thread, config, outputRoot);
		connect(worker, SIGNAL(finished(QVariant)), this, SLOT(doneTask(QVariant)));
		connect(wokrer_thread, SIGNAL(started()), worker, SLOT(run()));
		connect(wokrer_thread, SIGNAL(finished()), worker, SLOT(deleteLater()));
		this->nextTask(worker);
		worker->moveToThread(wokrer_thread);
		wokrer_thread->start();

		workers << worker;
	}

	emit started();
	if (loop == nullptr) {
		loop = new QEventLoop();
	}
	loop->exec();

}

void Dispatcher::nextTask(Compress* worker) {

	if (this->loop != nullptr && !this->loop->isRunning()) {
		qDebug() << "-------------------------->the progress was paused~！";
		return;
	}
	qDebug() << "nextTask" << offsetRow << model->rowCount() << runThreadNum;
	if (offsetRow >= model->rowCount()) {
		runThreadNum--;
		if (runThreadNum <= 0) {
			this->quit();
			this->thread->quit();
		}
		return;
	}

	TableModelRow item = model->getRow(offsetRow);
	if (item.thin_size > 0) {
		offsetRow += 1;
		this->nextTask(worker);
		return;
	}
	qDebug() << "addTask" << item.root << item.path;
	worker->addTask(offsetRow, item.root, item.path);
	this->model->updateStatus(offsetRow, 1);
	this->tableview->update(this->model->index(offsetRow, 4));
	offsetRow += 1;


}



void Dispatcher::doneTask(QVariant variant) {
	this->mutex->lock();

	finishNum++;
	CompressResult result = variant.value<CompressResult>();
	qDebug() << "收到结果:" << result.errcode << result.errmsg << result.size << result.path << result.row;


	if (result.row >= this->model->rowCount()) {
		return;
	}
	TableModelRow row = this->model->getRow(result.row);

	if (result.errcode == 0) {
		row.status = 2;
		row.thin_size = result.size;
		this->totalsize += row.size;
		this->totalLessSize += (row.size - row.thin_size);
		QBrush brush(QColor(23, 168, 26, 255));
		QString rate = QString().sprintf("%.2f", (float(row.size) - float(row.thin_size)) / float(row.size) * 100);
		qDebug() << row.size << row.thin_size << rate;
		QString size = QLocale(QLocale::English, QLocale::UnitedStates).formattedDataSize(row.thin_size, 2, QLocale::DataSizeTraditionalFormat);
		QString text = QString("%1/%2压缩成功:%3(%4),%5%").arg(finishNum).arg(totalRowNum).arg(row.path).arg(size).arg(rate);
		emit this->console->infoSignal(text);
		this->model->setData(this->model->index(result.row, 3), QVariant(brush), 9);
	}
	else {
		failedNum += 1;
		QString text = QString("%1/%2压缩失败:%3,%4").arg(finishNum).arg(totalRowNum).arg(row.path).arg(result.errmsg);
		emit this->console->errorSignal(text);
		row.status = -1;
	}
	this->model->replaceRow(result.row, row);

	this->tableview->update(this->model->index(result.row, 3));
	this->tableview->update(this->model->index(result.row, 2));
	this->tableview->update(this->model->index(result.row, 4));

	//this->tableview->dataChanged(rowLeftIndex, rowRightIndex);
	Compress* worker = (Compress*)sender();
	this->nextTask(worker);
	this->mutex->unlock();


}

void Dispatcher::quit() {
	qDebug() << "退出";


	loop->quit();
	QListIterator<Compress*> it(workers);
	while (it.hasNext()) {
		Compress* worker = it.next();
		if (worker->thread->isRunning()) {
			disconnect(worker, SIGNAL(finished(QVariant)), this, SLOT(doneTask(QVariant)));
			worker->quit();
			worker->thread->terminate();
			worker->thread->wait();
		}
	}
	for (int i = 0; i < this->model->rowCount(); i++) {
		TableModelRow row = this->model->getRow(i);
		if (row.status == 1) {
			row.status = 0;
			this->model->replaceRow(i, row);
			this->tableview->update(this->model->index(i, 4));
		}
	}
	loop->deleteLater();
	loop = nullptr;
	qDebug() << "exit2";

	workers.clear();
}

void Dispatcher::finished() {

	if (finishNum > 0) {
		QString spentime = QString().sprintf("%.3f", float(this->elapsedTimer->elapsed()) / 1000);
		QString lessrate = failedNum == finishNum ? "0" : QString().sprintf("%.2f", this->totalLessSize / this->totalsize * 100);
		QString text = QString("压缩完成,共压缩%1个图片,失败%2个,耗时：%3s，压缩率: %4%").arg(finishNum).arg(failedNum).arg(spentime).arg(lessrate);
		emit this->console->infoSignal(text);
	}



}

int Dispatcher::getUnhandleNum() {
	int total = this->model->rowCount();
	int num = 0;
	for (int i = 0; i < total; i++) {
		TableModelRow	item = this->model->getRow(i);
		if (item.status != 2) {
			num++;
		}
	}
	return num;
}

Dispatcher::~Dispatcher()
{
	delete elapsedTimer;

}
