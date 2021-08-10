#pragma once

#include <QThread>
#include <QStandardItemModel>
#include <QEventLoop>
#include "TableModel.h"

class ListFile : public QThread
{
	Q_OBJECT

public:

	TableModel* model;

	int minsize;
	explicit  ListFile(QObject* parent);
	~ListFile();
	void start(const QStringList&, int);
	void stop();
	void setModel(QStandardItemModel*);
	bool isCompressible(const QString&); //根据文件名检查是否可压缩
	void add(const QString&, const QString&, int);
	void batch(const QStringList&);

protected:
	void run();
private:
	QStringList files;
	bool stopped;
	QStringList suffiexs;

};
