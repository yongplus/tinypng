#include "ListFile.h"
#include <QDirIterator>
#include <QDebug>
#include <QFileInfo>

ListFile::ListFile(QObject* parent) :
	QThread(parent)
{

}

void ListFile::start(const QString p, int ms) {
	QThread::msleep(50);
	this->path = p;
	this->stopped = false;
	this->minsize = ms;
	qDebug() << "开始线程" << p << this->path;
	QThread::start();
}

void ListFile::stop() {
	this->stopped = true;
}

void ListFile::setModel(QStandardItemModel* m) {
	this->model = (TableModel*)m;
}

void ListFile::run() {
	qDebug() << "xxxxx";
	QStringList suffiexs = QStringList();
	suffiexs << "*.jpg";
	suffiexs << "*.png";
	suffiexs << "*.jpeg";

	model->removeAll();

	QDirIterator it(path, suffiexs, QDir::Files, QDirIterator::Subdirectories);
	QList<TableModelRow> list;
	while (it.hasNext()) {
		if (this->stopped) {
			break;
		}
		QString filepath = it.next();

		filepath = filepath.right(filepath.length() - this->path.length());
		qDebug() << filepath;
		if (it.fileInfo().size() < this->minsize) {
			continue;
		}
		/*
		QList<QStandardItem*> items;


		items << new QStandardItem(this->path)
			<< new QStandardItem(filepath)
			<< new QStandardItem("xx")
			<< new QStandardItem("待压缩");
		*/
		//row->appendColumn(items);
		_TableModelRow item;

		item.root = path;
		item.path = filepath;
		item.size = it.fileInfo().size();
		item.status = 0;
		item.thin_size = 0;
		model->addRow(item);

	}


}

QString ListFile::size_human(float num)
{

	QStringList list;
	list << "KB" << "MB" << "GB" << "TB";

	QStringListIterator i(list);
	QString unit("bytes");

	while (num >= 1024.0 && i.hasNext())
	{
		unit = i.next();
		num /= 1024.0;
	}
	return QString().setNum(num, 'f', 2) + " " + unit;
}


ListFile::~ListFile()
{
}
