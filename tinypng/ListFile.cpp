#include "ListFile.h"
#include <QDirIterator>
#include <QDebug>
#include <QFileInfo>

ListFile::ListFile(QObject* parent) :
	QThread(parent),
	minsize(0),
	model(nullptr)
{
	suffiexs = QStringList();
	suffiexs << "*.jpg";
	suffiexs << "*.png";
	suffiexs << "*.jpeg";
}

void ListFile::start(const QString p, int ms) {
	//QThread::msleep(50);
	QFileInfo fileinfo(p);
	if (fileinfo.isFile()) {
		qDebug() << "the src is a file~!";
		this->add(p);
		return;
	}
	this->path = p;
	this->stopped = false;
	this->minsize = ms;
	QThread::start();
}

void ListFile::stop() {
	this->stopped = true;
}

void ListFile::setModel(QStandardItemModel* m) {
	this->model = (TableModel*)m;
}

bool ListFile::isCompressible(const QString& name) {
	QString suffix = name.split(".").last().toLower();
	if (this->suffiexs.indexOf("*." + suffix) != -1) {
		return true;
	}
	else {
		return false;
	}
}

void ListFile::run() {


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
		this->add(path, filepath, it.fileInfo().size());



	}
}

void ListFile::add(const QString& root, const QString& filepath, int size) {
	_TableModelRow item;

	item.root = root;
	item.path = filepath;
	item.size = size;
	item.status = 0;
	item.thin_size = 0;
	model->addRow(item);
}

void ListFile::add(const QString& filepath) {
	QFileInfo fileinfo(filepath);
	if (!fileinfo.exists()) {
		return;
	}
	_TableModelRow item;
	model->removeAll();
	this->add("", filepath, fileinfo.size());
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
