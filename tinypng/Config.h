#pragma once

#include <QObject>
#include <QSettings>

enum OutputMode {
	NewDir,
	Replace
};

struct configItem {
	QString mail;
	QString key;
	QString proxy;
	OutputMode outputMode;
};


class Config : public QObject
{
	Q_OBJECT

public:
	QSettings* qset;
	Config(QObject* parent);
	~Config();
	void set(configItem item);
	configItem get();
private:
	configItem randDefault();
};
