#include "Utility.h"


bool Utility::checkFileFormat(const QString& name) {
	QString suffix = name.split(".").last().toLower();
	if (Utility::getFormatList().indexOf("*." + suffix) != -1) {
		return true;
	}
	else {
		return false;
	}
}


QStringList Utility::getFormatList() {
	QStringList suffiexs = QStringList();

	suffiexs << "*.jpg";
	suffiexs << "*.png";
	suffiexs << "*.jpeg";
	return suffiexs;
}
