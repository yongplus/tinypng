#pragma once

#include <QThread>
#include <QStandardItemModel>
#include <QEventLoop>
#include "TableModel.h"

class Scanner : public QThread
{
	Q_OBJECT

public:

	TableModel* model;
	//CompressThreadDispatcher* dispatcher;
	int minsize;
	explicit  Scanner(QObject* parent);
	~Scanner();
	void start(const QStringList&, int);
	void stop();
	void setModel(QStandardItemModel*);
	void add(const QString&, const QString&, int);
	void batch(const QStringList&);
	//void setDispatcher(CompressThreadDispatcher*);
protected:
	void run();
private:
	QStringList files;
	bool stopped;
};
