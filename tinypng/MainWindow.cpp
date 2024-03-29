﻿#if _MSC_VER >= 1600 
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
#include "Utility.h"





MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent)
{

	QFont font("NSimSun");
    font.setPixelSize(10);
	QApplication::setFont(font);

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

	dispatcher = new Dispatcher(dispatcherThread, this->console, this->table);
	connect(dispatcher, SIGNAL(started()), this, SLOT(showPauseBtn()));
	connect(dispatcherThread, SIGNAL(started()), dispatcher, SLOT(run()));
	connect(dispatcherThread, SIGNAL(finished()), dispatcher, SLOT(finished()));
	connect(dispatcherThread, SIGNAL(finished()), this, SLOT(showStartBtn()));
	connect(this->table, SIGNAL(readResource(QStringList)), this, SLOT(createScannner(QStringList)));

	dispatcher->moveToThread(dispatcherThread);
	scanner = NULL;

}

void MainWindow::show() {
	QMainWindow::show();

}

void MainWindow::_buildTopBtns() {
	QPushButton* add = new QPushButton(QString("添加资源(O)"), this);
	add->setFixedSize(100, 45);
	add->setIcon(QIcon(":/res/icons/folder.png"));
	add->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));

	startbtn = new QPushButton(QString("开始压缩(S)"), this);
	startbtn->setFixedSize(100, 45);
	startbtn->setIcon(QIcon(":/res/icons/compress.png"));

	startbtn->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));

	pausebtn = new QPushButton(QString("暂停压缩(P)"), this);
	pausebtn->setFixedSize(100, 45);
	pausebtn->setIcon(QIcon(":/res/icons/pause.png"));
	pausebtn->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_P));
	pausebtn->hide();




	QPushButton* config = new QPushButton(QString("配置KEY(C)"), this);
	config->setFixedSize(100, 45);
	config->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
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
	topLayout->setSpacing(10);
	topLayout->addStretch(1);


	this->layout->addLayout(topLayout);


}

void MainWindow::_buildBody() {

	TableModel* model = new TableModel(this);
	this->table = new MyTableView(this, model);

	this->console = new Console(this);

	QSplitter* splitter = new QSplitter(Qt::Vertical);
	splitter->addWidget(table);
	splitter->addWidget(console);
	splitter->setStretchFactor(0, 6);
	splitter->setStretchFactor(1, 2);
	splitter->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	this->layout->addWidget(splitter, 1);

}


void MainWindow::closeEvent(QCloseEvent* event) {
	if (scanner != NULL) {
		scanner->stop();
	}
	this->onClickPauseBtn();
	event->accept();
}

void MainWindow::onClickEditBtn() {

	QPushButton* btn = (QPushButton*)sender();
	qDebug() << "Click the btn" << btn->objectName();

	QFileDialog dlg(this, Qt::Dialog);

	dlg.setWindowTitle("选择压缩目录");
	dlg.setOptions(QFileDialog::DontUseNativeDialog | QFileDialog::ReadOnly);

	QString suffix = Utility::getFormatList().join(" ");
	dlg.setNameFilter("Image (" + suffix + ")");
	dlg.setLabelText(QFileDialog::Reject, "取 消");
	dlg.setFileMode(QFileDialog::Directory);
	dlg.setWindowFlag(Qt::WindowContextHelpButtonHint, false);
	connect(&dlg, &QFileDialog::currentChanged, this, [&](const QString& str)
		{
			QFileInfo info(str);
			if (info.isFile())
				dlg.setFileMode(QFileDialog::ExistingFiles);
			else if (info.isDir())
				dlg.setFileMode(QFileDialog::Directory);
		});


	if (dlg.exec() == 1) {      
		createScannner(dlg.selectedFiles());
	}
	disconnect(&dlg);
	dlg.deleteLater();
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
	this->startbtn->setDisabled(true);
	if (dispatcher->thread->isRunning()) {
		return;
	}
	dispatcher->thread->start();
}

void MainWindow::onClickPauseBtn() {
	if (!dispatcher->thread->isRunning()) {
		return;
	}
	dispatcher->quit();
	dispatcher->thread->quit();
	dispatcher->thread->wait();
	emit this->console->infoSignal("暂停压缩");

}

void MainWindow::showStartBtn() {

	this->startbtn->setEnabled(true);
	this->startbtn->show();
	this->pausebtn->hide();
}

void MainWindow::showPauseBtn() {

	this->startbtn->hide();
	this->pausebtn->show();
	this->pausebtn->setEnabled(true);

}

void MainWindow::resizeEvent(QResizeEvent* event) {


}

void MainWindow::createScannner(const QStringList& files) {

	if (files.count() == 0) {
		return;
	}

	if (scanner != NULL) {
		scanner->stop();
		delete scanner;
		scanner = NULL;
	}


	//if the compression is doing,firstly stop it.
	this->onClickPauseBtn();

	scanner = new Scanner(this);

	connect(scanner, &Scanner::finished, this, [&]() {
		this->startbtn->setToolTip("");
		this->startbtn->setEnabled(true);
		if (this->table->model()->rowCount() > 0 && Config(this).get().autoStart) {
			this->onClickStartBtn();
		}
		});
	scanner->setModel((QStandardItemModel*)this->table->model());

	int minsize = Config(this).get().minsize;
	int maxsize = Config(this).get().maxsize;

	scanner->start(files, minsize, maxsize);

	this->startbtn->setEnabled(false);
	this->startbtn->setToolTip("目录读取中,请稍等~！");
}



MainWindow::~MainWindow() {

}
