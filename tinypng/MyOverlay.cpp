#include "MyOverlay.h"
#include <QLabel>
#include <QVBoxLayout>

MyOverlay::MyOverlay(QWidget* parent)
	: QWidget(parent)
{

	setObjectName("overlay");
	setAttribute(Qt::WA_StyledBackground, true);
	setStyleSheet("#overlay{background-color:rgba(0,0,0,0.3);}");

	QLabel* label = new QLabel();
	label->setObjectName("overlaylabel");

	label->setStyleSheet("#overlaylabel{color:#FFFFFF;background-color:rgba(0,0,0,0);}");
	label->setAttribute(Qt::WA_TransparentForMouseEvents, true);
	label->setText("松开读取目录资源");

	QVBoxLayout* layout = new QVBoxLayout();
	layout->addWidget(label, 1, Qt::AlignHCenter);
	setAttribute(Qt::WA_TransparentForMouseEvents, true);
	setLayout(layout);
	hide();
}



MyOverlay::~MyOverlay()
{
}
