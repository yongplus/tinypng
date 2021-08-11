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
	/* load the system translations provided by Qt */
	QTranslator qtTranslator;

	QTranslator* pTranslator = new QTranslator();
	pTranslator->load(":/res/qt_zh_CN.qm");
	a.installTranslator(pTranslator);

	//QApplication::setStyle(QStyleFactory::create("Fusion"));
	MainWindow w;
	a.setSingleMainWindow(&w);
	w.show();
	return a.exec();
}
