#include <QApplication>
#include <QStyleFactory>
#include "MainWindow.h"



int main(int argc, char* argv[])
{

	QApplication a(argc, argv);
	//QApplication::setStyle(QStyleFactory::create("Fusion"));
	MainWindow w;
	w.show();
	return a.exec();
}
