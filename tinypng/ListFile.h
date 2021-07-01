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
	explicit  ListFile(QObject* parent);
	~ListFile();
	void start(const QString path);
	void stop();
	void setModel(QStandardItemModel*);

protected:
	void run();
private:
	bool stopped = false;
	QString size_human(float);

};
