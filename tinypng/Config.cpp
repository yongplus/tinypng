#include "Config.h"
#include <QDateTime>

Config::Config(QObject* parent)
	: QObject(parent)
{
	qset = new QSettings("lane", "tinypng", this);
	qset->beginGroup("Property");
	if (!qset->contains("mail")) {
		configItem one = this->randDefault();
		qset->setValue("mail", QVariant(one.mail));
		qset->setValue("key", QVariant(one.key));
		qset->setValue("outputMode", int(OutputMode::Replace));
	}
	qset->endGroup();

}

void Config::set(configItem item) {
	qset->beginGroup("Property");
	qset->setValue("mail", item.mail);
	qset->setValue("key", item.key);
	qset->setValue("proxy", item.proxy);
	qset->setValue("outputMode", int(item.outputMode));
	qset->setValue("minsize", item.minsize);
	qset->setValue("tinyReqMode", int(item.tinyReqMode));
	qset->endGroup();
}

configItem Config::get() {
	configItem item;
	qset->beginGroup("Property");
	item.mail = qset->value("mail").toString();
	item.key = qset->value("key").toString();
	item.proxy = qset->value("proxy").toString();
	item.minsize = qset->value("minsize").toInt();
	if (qset->value("outputMode").toInt() != 1) {
		item.outputMode = OutputMode::NewDir;
	}
	else {
		item.outputMode = OutputMode::Replace;
	}
	if (qset->value("tinyReqMode").toInt() == 1) {
		item.tinyReqMode = TinyReqMode::Key;
	}
	else {
		item.tinyReqMode = TinyReqMode::Web;
	}
	qset->endGroup();
	return item;
}

configItem Config::randDefault() {
	QList<configItem> list;
	list << configItem{ "294442185@qq.com","GdFgBwlrQMM9jdkzS17QlCpq3rNFpwZH" };
	list << configItem{ "517486@qq.com","jS53dfsv5wTkrlhh3MN81wS30Tb28ylb" };

	qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);
	int idx = qrand() % list.length();

	return list.at(idx);
}

Config::~Config()
{
}
