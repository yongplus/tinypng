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

	label->setStyleSheet("#overlaylabel{color:#FFFFFF;background-color:rgba(0,0,0,0);letter-spacing:10px;}");
	label->setAttribute(Qt::WA_TransparentForMouseEvents, true);
	label->setText("松开读取目录资源");

	QImage* img = new QImage();
	img->load(":/res/read.png");


	QLabel* label2 = new QLabel();
	label2->setPixmap(QPixmap::fromImage(*img));
	QVBoxLayout* layout = new QVBoxLayout();
	layout->addStretch(1);
	layout->addWidget(label2, 0, Qt::AlignHCenter);
	layout->addWidget(label, 0, Qt::AlignHCenter);
	layout->addStretch(1);
	setAttribute(Qt::WA_TransparentForMouseEvents, true);
	setLayout(layout);
	hide();
}



MyOverlay::~MyOverlay()
{
}
