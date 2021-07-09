#pragma once

#include <QApplication>
#include <QApplication>
#include <QWidget>

#include <QLocalServer>


class SingleApplication : public QApplication
{
	Q_OBJECT

public:
	SingleApplication(int& argc, char** argv);
	~SingleApplication();

public:
	bool isRunning();

	//保存主窗口指针
	void setSingleMainWindow(QWidget* w);

private slots:
	void newLocalConnection();

private:
	bool m_bRunning;
	QLocalServer* m_pServer;
	QWidget* m_widget;
};
