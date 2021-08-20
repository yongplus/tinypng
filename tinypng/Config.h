#pragma once

#include <QObject>
#include <QSettings>

enum class  OutputMode {
	NewDir,
	Replace
};

enum class TinyReqMode {
	Web,  //模拟用户操作web
	Key   //使用api key 
};




struct configItem {
	QString mail;
	QString key;
	QString proxy;
	OutputMode outputMode;
	TinyReqMode tinyReqMode;
	bool autoStart; //添加资源后自动开始压缩
	int minsize;
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
