#pragma once

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include <QMainWindow>
#include <QHBoxLayout>
#include <QStandardItemModel>
#include "MyTableView.h"
#include "MyOverlay.h"
#include "Console.h"
#include "CompressThreadDispatcher.h"
#include "Config.h"
#include "SettingWindow.h"
#include "Scanner.h"

namespace Ui {
	class MainWindow;
}

class MainWindow :
	public QMainWindow
{
	Q_OBJECT

public:
	MyTableView* table;
	QVBoxLayout* layout;
	QWidget* widget;
	Console* console;
	Config* config;
	QPushButton* startbtn;
	QPushButton* pausebtn;
	Scanner* scanner;
	MainWindow(QWidget* parent = nullptr);
	~MainWindow();
	void show();

private:
	CompressThreadDispatcher* dispatcher;
	Ui::MainWindow* ui;

	void _buildTopBtns();
	void _buildBody();
	virtual void resizeEvent(QResizeEvent* event) override;


protected:
	virtual void closeEvent(QCloseEvent* event) override;

public slots:
	void onClickEditBtn();
	void onClickPauseBtn();
	void onClickStartBtn();
	void onOpenSettingWindow();
	void showStartBtn();
	void showPauseBtn();
	void createScannner(const QStringList&); //创建资源扫描器

};
