#include "MyTableView.h"
#include <QHeaderView>
#include <QDebug>
#include <QMimeData>
#include <QDir>
#include <QMenu>
#include <QDesktopServices>
#include <QApplication>
#include <QPainter>
#include <QFileInfo>
#include "config.h"

MyTableView::MyTableView(QWidget* parent, QAbstractItemModel* model)
{
	init();
	this->setModel(model);
}

void MyTableView::init() {
	setStyleSheet("QTableView { \
		selection-background-color: #8EDE21;\
color: black \
}");

	setSelectionBehavior(QAbstractItemView::SelectRows);
	horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	setColumnWidth(5, 100);
	setColumnWidth(4, 100);
	setColumnWidth(3, 100);
	setColumnWidth(2, 100);

	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setColumnHidden(0, true);
	setAcceptDrops(true);
	setContextMenuPolicy(Qt::CustomContextMenu);
	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(customContextMenuResposne(const QPoint&)));
	connect(this, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onDoubleClickRow(QModelIndex)));
	scanner = new Scanner(this);
	overlay = new MyOverlay(this);

}

void MyTableView::setModel(QAbstractItemModel* m) {
	QTableView::setModel(m);
	this->scanner->setModel((QStandardItemModel*)m);
}


void MyTableView::dragEnterEvent(QDragEnterEvent* event) {
	QTableView::dragEnterEvent(event);

	if (!checkMimeIsDir(event->mimeData())) {
		return;
	}
	overlay->show();
	event->acceptProposedAction();
}


void MyTableView::dragMoveEvent(QDragMoveEvent* event) {
	QTableView::dragMoveEvent(event);

	if (!checkMimeIsDir(event->mimeData())) {
		return;
	}
	event->acceptProposedAction();
}

void MyTableView::dragLeaveEvent(QDragLeaveEvent* event) {
	overlay->hide();
}

void MyTableView::dropEvent(QDropEvent* event) {
	QTableView::dropEvent(event);
	const QMimeData* mimedata = event->mimeData();
	if (!mimedata->hasUrls()) {
		return;
	}
	QList<QUrl> urls = mimedata->urls();
	QStringList files = QStringList();
	for (int i = 0; i < urls.count(); i++) {
		QString path = urls.at(i).toLocalFile();
		QFileInfo file(path);
		if (file.isFile() && !this->scanner->isCompressible(path)) {
			continue;
		}
		files << path;
	}

	overlay->hide();
	this->readDir(files);
}

void MyTableView::readDir(const QStringList& files) {
	if (files.count() == 0) {
		return;
	}

	int minsize = Config(this).get().minsize;
	scanner->start(files, minsize);
}

void MyTableView::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key_Delete) {
		this->clickDelete();
	}
	else if (event->key() == Qt::Key_A && QApplication::keyboardModifiers() && Qt::ControlModifier) {
		TableModel* model = (TableModel*)this->model();
		this->selectAll();
	}
}

void MyTableView::openSelectedRowFolder(int flag) {
	int rowIdx = this->selectionModel()->selectedRows()[0].row();
	TableModel* model = (TableModel*)this->model();
	TableModelRow row = model->getRow(rowIdx);

	QString dir = "";
	if (flag == 1) { //输出目录
		dir = QFileInfo(row.root + "_tiny" + row.path).absoluteDir().absolutePath();
	}
	else { //源目录
		dir = QFileInfo(row.root + row.path).absoluteDir().absolutePath();
	}

	QDesktopServices::openUrl(QUrl::fromLocalFile(QString("file:///%1").arg(dir)));
}


void MyTableView::paintEvent(QPaintEvent* event) {
	QTableView::paintEvent(event); // draw original content

	TableModel* model = (TableModel*)this->selectionModel()->model();
	if (model->rowCount() == 0 && this->overlay->isHidden()) {
		QPainter painter(this->viewport());
		painter.setPen(QColor("#aaaaaa"));
		painter.drawText(this->viewport()->rect(), Qt::AlignCenter, "拖拽要压缩的目录或图片到此区域");
	}

}

bool MyTableView::checkMimeIsDir(const QMimeData* mimedata) {

	if (mimedata->hasUrls() == false) {
		return false;
	}

	if (mimedata->urls().length() == 0) {
		return false;
	}
	int dirNum = 0;
	int fileNum = 0;
	for (int i = 0; i < mimedata->urls().length(); i++) {
		QString path = mimedata->urls().at(i).toLocalFile();

		if (QDir(path).exists()) {
			dirNum += 1;
		}
		else if (this->scanner->isCompressible(path)) {
			fileNum += 1;
		}
	}
	//不能是多个文件夹 不能文件夹和文件混合  
	if (dirNum > 1 || (dirNum > 0 && fileNum > 0) || (fileNum + dirNum) == 0) {
		return false;
	}
	return true;
}
void MyTableView::resizeEvent(QResizeEvent* event) {
	QTableView::resizeEvent(event);
	this->setColumnWidth(1, event->size().width() - 400);
	this->setColumnHidden(0, true);

	QPoint pos = this->mapTo(this, QPoint(0, 0));
	overlay->setGeometry(pos.x(), pos.y(), this->width(), this->height());
}

void MyTableView::onDoubleClickRow(const QModelIndex& index) {
	TableModel* model = (TableModel*)this->selectionModel()->model();
	TableModelRow row = model->getRow(index.row());
	QString path = row.root + row.path;
	QDesktopServices::openUrl(QUrl::fromLocalFile(path));
}

void MyTableView::customContextMenuResposne(const QPoint& pos) {
	int num = this->selectionModel()->selectedRows().length();
	if (num == 0) {
		return;
	}

	int rowIdx = this->selectionModel()->selectedRows()[0].row();
	TableModel* model = (TableModel*)this->model();
	TableModelRow row = model->getRow(rowIdx);

	QMenu* menu = new QMenu(this);
	menu->setAttribute(Qt::WA_DeleteOnClose);
	QAction* action = new QAction("删  除", menu);
	menu->addAction(action);
	menu->addAction("打开源目录", [&]() {
		this->openSelectedRowFolder(0);
		});
	menu->addAction("打开输出目录", [&]() {
		this->openSelectedRowFolder(1);
		});
	if (num > 1) {
		menu->actions().at(1)->setDisabled(true);
		menu->actions().at(2)->setDisabled(true);
	}
	else if (row.root.isEmpty() || Config(this).get().outputMode == OutputMode::Replace || row.status != 2) {
		menu->actions().at(2)->setDisabled(true);
	}

	menu->popup(this->viewport()->mapToGlobal(pos), NULL);
	connect(action, SIGNAL(triggered()), this, SLOT(clickDelete()));

}

void MyTableView::clickDelete() {
	QModelIndexList selectedRows = this->selectionModel()->selectedRows();
	if (selectedRows.length() == 0) {
		return;
	}
	TableModel* model = (TableModel*)this->model();

	if (selectedRows.length() == this->model()->rowCount()) {
		model->removeAll();
		return;
	}
	else if (selectedRows.first().row() + selectedRows.length() == (selectedRows.last().row() + 1)) {
		model->removeRange(selectedRows.first().row(), selectedRows.last().row());
	}
	else {
		QList<QPersistentModelIndex> indexs;
		for (int i = 0; i < selectedRows.length(); i++) {
			indexs << QPersistentModelIndex(selectedRows.at(i));
		}
		QListIterator<QPersistentModelIndex> i(indexs);
		while (i.hasNext()) {
			QPersistentModelIndex item = i.next();
			model->removeRow(item.row());
		}
		indexs.clear();
	}


}



MyTableView::~MyTableView()
{

}
