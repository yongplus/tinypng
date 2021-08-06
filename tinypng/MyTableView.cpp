#include "MyTableView.h"
#include <QHeaderView>
#include <QDebug>
#include <QMimeData>
#include <QDir>
#include <QMenu>
#include <QDesktopServices>
#include "config.h"

MyTableView::MyTableView(QWidget* parent)

{
	init();
}

void MyTableView::init() {
	setStyleSheet("QTableView { \
		selection-background-color: #8EDE21;\
color: black \
}");

	setSelectionBehavior(QAbstractItemView::SelectRows);
	horizontalHeader()->setSectionResizeMode(QHeaderView::Fixed);
	setColumnWidth(3, 100);
	setColumnWidth(2, 100);
	setEditTriggers(QAbstractItemView::NoEditTriggers);
	setColumnHidden(0, true);
	setAcceptDrops(true);
	setContextMenuPolicy(Qt::CustomContextMenu);
	connect(this, SIGNAL(customContextMenuRequested(const QPoint&)), this, SLOT(customContextMenuResposne(const QPoint&)));
	connect(this, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(onDoubleClickRow(QModelIndex)));
	listFileThread = new ListFile(this);
	overlay = new MyOverlay(this);
}

void MyTableView::setModel(QAbstractItemModel* m) {
	QTableView::setModel(m);
	this->listFileThread->setModel((QStandardItemModel*)m);
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
	QString path = urls.at(0).toLocalFile();
	overlay->hide();
	this->readDir(path);
}

void MyTableView::readDir(const QString& path) {
	listFileThread->stop();
	int minsize = Config(this).get().minsize;
	listFileThread->start(path, minsize);
}

void MyTableView::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key_Delete) {
		this->clickDelete();
	}
}

bool MyTableView::checkMimeIsDir(const QMimeData* mimedata) {

	if (mimedata->hasUrls() == false) {
		return false;
	}

	if (mimedata->urls().length() > 1) {
		return false;
	}

	QString path = mimedata->urls().at(0).toLocalFile();

	if (QDir(path).exists() == false && !this->listFileThread->isCompressible(path)) {
		return false;
	}

	return true;
}
void MyTableView::resizeEvent(QResizeEvent* event) {
	QTableView::resizeEvent(event);
	this->setColumnWidth(1, event->size().width() - 200);
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
	if (this->selectionModel()->selectedRows().length() == 0) {
		return;
	}

	QMenu* menu = new QMenu(this);
	QAction* action = new QAction("删 除", menu);
	menu->addAction(action);
	menu->popup(this->viewport()->mapToGlobal(pos), NULL);
	connect(action, SIGNAL(triggered()), this, SLOT(clickDelete()));

}

void MyTableView::clickDelete() {
	QModelIndexList selectedRows = this->selectionModel()->selectedRows();
	if (selectedRows.length() == 0) {
		return;
	}
	QList<QPersistentModelIndex> indexs;
	for (int i = 0; i < selectedRows.length(); i++) {
		indexs << QPersistentModelIndex(selectedRows.at(i));
	}
	QListIterator<QPersistentModelIndex> i(indexs);
	TableModel* model = (TableModel*)this->selectionModel()->model();
	while (i.hasNext()) {
		QPersistentModelIndex item = i.next();
		model->removeRow(item.row());
	}

}

MyTableView::~MyTableView()
{

}
