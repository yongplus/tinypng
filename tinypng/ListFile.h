#pragma once

#include <QThread>
#include <QStandardItemModel>
#include "TableModel.h"

class ListFile : public QThread
{
	Q_OBJECT

public:

	TableModel* model;
	QString path;
	int minsize;
	explicit  ListFile(QObject* parent);
	~ListFile();
	void start(const QString path, int minsize);
	void stop();
	void setModel(QStandardItemModel*);
	bool isCompressible(const QString&); //根据文件名检查是否可压缩
	void add(const QString& root, const QString& filepath, int size);
	void add(const QString&);

protected:
	void run();
private:
	bool stopped = false;
	QString size_human(float);
	QStringList suffiexs;

};
