#include "Scanner.h"
#include <QDirIterator>
#include <QDebug>
#include <QFileInfo>

Scanner::Scanner(QObject* parent) :
	QThread(parent),
	minsize(0),
	model(nullptr)
{
	suffiexs = QStringList();
	suffiexs << "*.jpg";
	suffiexs << "*.png";
	suffiexs << "*.jpeg";
	stopped = false;
}

void Scanner::start(const QStringList& files, int ms) {
	if (files.count() == 0) {
		return;
	}
	this->stop();
	this->stopped = false;
	this->files = files;
	this->minsize = ms;
	QThread::start();
}

void Scanner::stop() {
	if (this->isRunning()) {
		this->stopped = true;
		this->wait();
	}
}

void Scanner::setModel(QStandardItemModel* m) {
	this->model = (TableModel*)m;
}

bool Scanner::isCompressible(const QString& name) {
	QString suffix = name.split(".").last().toLower();
	if (this->suffiexs.indexOf("*." + suffix) != -1) {
		return true;
	}
	else {
		return false;
	}
}

void Scanner::run() {
	model->removeAll();
	QFileInfo fileinfo(files[0]);
	if (fileinfo.isFile()) {
		qDebug() << "the src are files~!";
		this->batch(files);
		return;
	}
	QString path = files[0];

	QDirIterator it(path, suffiexs, QDir::Files, QDirIterator::Subdirectories);
	QList<TableModelRow> list;
	while (it.hasNext()) {
		if (this->stopped) {
			this->exit();
			break;
		}
		QString filepath = it.next();

		filepath = filepath.right(filepath.length() - path.length());
		int filesize = it.fileInfo().size();
		if (filesize < this->minsize || filesize>(1024 * 1024 * 5)) {
			continue;
		}
		this->add(path, filepath, it.fileInfo().size());
	}
}

void Scanner::add(const QString& root, const QString& filepath, int size) {
	_TableModelRow item;

	item.root = root;
	item.path = filepath;
	item.size = size;
	item.status = 0;
	item.thin_size = 0;
	model->addRow(item);
}

void Scanner::batch(const QStringList& files) {
	if (files.count() == 0) {
		return;
	}

	for (int i = 0; i < files.count(); i++) {
		if (this->stopped) {
			this->exit();
			break;
		}
		QFileInfo fileinfo(files[i]);
		if (!fileinfo.exists()) {
			return;
		}
		this->add("", files[i], fileinfo.size());
	}
}



Scanner::~Scanner()
{
}
