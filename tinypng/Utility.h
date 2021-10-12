#pragma once
#include <qobject.h>
class Utility :
	public QObject
{
public:
	//验证文件后缀是否符合压缩格式
	static bool checkFileFormat(const QString&);
	static QStringList getFormatList();
};
