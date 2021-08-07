#if _MSC_VER >= 1600 
#pragma execution_character_set("utf-8") 
#endif

#include "MainWindow.h"
#include "MyTableView.h"
#include "TableModel.h"
#include <QPushButton>
#include <QMessageBox>
#include <qDebug>
#include <QSplitter>
#include <QFileDialog>





MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent)
{
	layout = new QVBoxLayout();
	_buildTopBtns();
	_buildBody();
	widget = new QWidget();
	setCentralWidget(this->widget);
	widget->setLayout(this->layout);
	resize(850, 550);
	QIcon icon(":/logo.ico");
	QGuiApplication::setWindowIcon(icon);
	setWindowTitle("图片压缩");

	QThread* dispatcherThread = new QThread();

	dispatcher = new CompressThreadDispatcher(dispatcherThread, this->console, this->table);
	connect(dispatcherThread, SIGNAL(started()), dispatcher, SLOT(run()));
	connect(dispatcherThread, SIGNAL(finished()), dispatcher, SLOT(finished()));
	connect(dispatcherThread, SIGNAL(finished()), this, SLOT(showStartBtn()));

	dispatcher->moveToThread(dispatcherThread);

}

void MainWindow::show() {
	QMainWindow::show();
	connect(table->listFileThread, SIGNAL(started()), this, SLOT(scanDirStateChange()));
	connect(table->listFileThread, SIGNAL(finished()), this, SLOT(scanDirStateChange()));
}

void MainWindow::_buildTopBtns() {
	QPushButton* add = new QPushButton(QString("添加路径"), this);
	add->setFixedSize(90, 45);
	add->setIcon(QIcon(":/res/icons/folder.png"));

	startbtn = new QPushButton(QString("开始压缩"), this);
	startbtn->setFixedSize(90, 45);
	startbtn->setIcon(QIcon(":/res/icons/compress.png"));


	pausebtn = new QPushButton(QString("暂停压缩"), this);
	pausebtn->setFixedSize(90, 45);
	pausebtn->setIcon(QIcon(":/res/icons/pause.png"));
	pausebtn->hide();


	QPushButton* config = new QPushButton(QString("配置KEY"), this);
	config->setFixedSize(90, 45);
	config->setIcon(QIcon(":/res/icons/setting.png"));


	connect(add, SIGNAL(clicked()), this, SLOT(onClickEditBtn()));
	connect(startbtn, SIGNAL(clicked()), this, SLOT(onClickStartBtn()));
	connect(pausebtn, SIGNAL(clicked()), this, SLOT(onClickPauseBtn()));
	connect(config, SIGNAL(clicked()), this, SLOT(onOpenSettingWindow()));

	QHBoxLayout* topLayout = new QHBoxLayout();
	topLayout->addWidget(add);
	topLayout->addWidget(startbtn);
	topLayout->addWidget(pausebtn);
	topLayout->addWidget(config);
	topLayout->addStretch(1);
	this->layout->addLayout(topLayout);


}

void MainWindow::_buildBody() {

	table = new MyTableView(this);
	TableModel* model = new TableModel(this);
	table->setModel(model);

	this->console = new Console(this);

	QSplitter* splitter = new QSplitter(Qt::Vertical);
	splitter->addWidget(table);
	splitter->addWidget(console);
	splitter->setStretchFactor(0, 6);
	splitter->setStretchFactor(1, 2);
	splitter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->layout->addWidget(splitter, 1);


}


void MainWindow::onClickEditBtn() {

	QPushButton* btn = (QPushButton*)sender();
	qDebug() << "Click the btn" << btn->objectName();

	QFileDialog dlg(this, Qt::Dialog);
	dlg.setWindowTitle("选择压缩目录");
	dlg.setOptions(QFileDialog::DontUseNativeDialog | QFileDialog::ReadOnly);

	dlg.setNameFilter("Image (*.jpg *.png *.jpeg)");
	dlg.setFileMode(QFileDialog::Directory);

	connect(&dlg, &QFileDialog::currentChanged, this, [&](const QString& str)
		{
			QFileInfo info(str);
			if (info.isFile())
				dlg.setFileMode(QFileDialog::ExistingFile);
			else if (info.isDir())
				dlg.setFileMode(QFileDialog::Directory);
		});


	if (dlg.exec() == 1) {
		this->table->readDir(dlg.selectedFiles()[0]);
	}
	disconnect(&dlg);
}

void MainWindow::onOpenSettingWindow() {
	SettingWindow* win = new SettingWindow(this);
	win->show();
}

void MainWindow::onClickStartBtn() {


	if (this->table->selectionModel()->model()->rowCount() == 0) {
		this->console->error("没有可压缩的文件");
		return;
	}

	//int count = this->table->model()->rowCount();
	//this->table->model()->removeRows(0, count);
	dispatcher->thread->start();
	this->startbtn->hide();
	this->pausebtn->show();
}

void MainWindow::onClickPauseBtn() {
	if (dispatcher->thread->isRunning()) {
		dispatcher->quit();
		dispatcher->thread->quit();
		dispatcher->thread->wait();
		qDebug() << "退出";
	}
	this->showStartBtn();
}

void MainWindow::showStartBtn() {

	this->startbtn->show();
	this->pausebtn->hide();
}

void MainWindow::resizeEvent(QResizeEvent* event) {


}

void MainWindow::scanDirStateChange() {
	bool state = true;
	if (table->listFileThread->isRunning()) {

		if (dispatcher->thread->isRunning()) {
			dispatcher->quit();
			dispatcher->thread->quit();

		}

		this->startbtn->setEnabled(false);
		this->startbtn->setToolTip("目录读取中,请稍等~！");
	}
	else {
		this->startbtn->setToolTip("");
		this->startbtn->setEnabled(true);
	}

}

MainWindow::~MainWindow() {
}
