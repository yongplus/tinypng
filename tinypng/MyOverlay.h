#pragma once

#include <QWidget>

class MyOverlay : public QWidget
{
	Q_OBJECT

public:
	MyOverlay(QWidget* parent = Q_NULLPTR);
	~MyOverlay();

};
