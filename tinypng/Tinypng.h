#pragma once

#include <QThread>

class Tinypng : public QThread
{
	Q_OBJECT

public:
	Tinypng(QObject *parent);
	~Tinypng();
};
