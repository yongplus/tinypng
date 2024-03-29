﻿#pragma once

#include <QTableView>
#include <QResizeEvent>
#include "MyOverlay.h"
#include "TableModel.h"
#include "GridTableHeaderView.h"


class MyTableView : public QTableView
{
	Q_OBJECT

public:

	MyTableView(QWidget* parent, QAbstractItemModel*);
	~MyTableView();
	void init();
	void setModel(QAbstractItemModel*) override;
	virtual void dragEnterEvent(QDragEnterEvent*) override;
	virtual void dragMoveEvent(QDragMoveEvent*) override;
	virtual void dragLeaveEvent(QDragLeaveEvent*) override;
	virtual void dropEvent(QDropEvent*) override;
	virtual void resizeEvent(QResizeEvent*) override;
	void keyPressEvent(QKeyEvent*) override;
	void openSelectedRowFolder(int flag);

	void setGridHeaderview();
protected:
	void paintEvent(QPaintEvent*) override;
private:
	MyOverlay* overlay;
	bool checkMimeIsDir(const QMimeData* minedata);


public slots:
	void clickDelete();
	void onDoubleClickRow(const QModelIndex& index);
	void customContextMenuResposne(const QPoint& pos);

signals:
	void readResource(QStringList);


};
