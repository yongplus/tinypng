#include "SingleApplication.h"
#include <QStyleFactory>
#include <QTranslator>
#include <QLibraryInfo>
#include "MainWindow.h"



int main(int argc, char* argv[])
{
	SingleApplication a(argc, argv);
	if (a.isRunning()) {
		return 0;
	}
	QTranslator qtTranslator;

	QTranslator* pTranslator = new QTranslator();
	pTranslator->load(":/res/qt_zh_CN.qm");
	a.installTranslator(pTranslator);

	QFont f("Helvetica", 9);
	a.setFont(f);

	MainWindow w;
	a.setSingleMainWindow(&w);
	w.show();
	return a.exec();
}
