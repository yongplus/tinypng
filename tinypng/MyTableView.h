#pragma once

#include <QTableView>
#include <QResizeEvent>
#include "ListFile.h"
#include "MyOverlay.h"

class MyTableView : public QTableView
{
	Q_OBJECT

public:
	ListFile* listFileThread;
	MyTableView(QWidget* parent = Q_NULLPTR);
	~MyTableView();
	void init();
	void setModel(QAbstractItemModel*) override;
	virtual void dragEnterEvent(QDragEnterEvent*) override;
	virtual void dragMoveEvent(QDragMoveEvent*) override;
	virtual void dragLeaveEvent(QDragLeaveEvent*) override;
	virtual void dropEvent(QDropEvent*) override;
	virtual void resizeEvent(QResizeEvent*) override;
	void readDir(const QString&);
	void keyPressEvent(QKeyEvent*);

private:
	MyOverlay* overlay;
	bool checkMimeIsDir(const QMimeData* minedata);


public slots:
	void clickDelete();
	void onDoubleClickRow(const QModelIndex& index);
	void customContextMenuResposne(const QPoint& pos);

};
