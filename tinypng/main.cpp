#include "SingleApplication.h"
#include <QStyleFactory>
#include "MainWindow.h"



int main(int argc, char* argv[])
{
	SingleApplication a(argc, argv);
	if (a.isRunning()) {
		return 0;
	}

	//QApplication::setStyle(QStyleFactory::create("Fusion"));
	MainWindow w;
	a.setSingleMainWindow(&w);
	w.show();
	return a.exec();
}
