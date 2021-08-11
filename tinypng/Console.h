#pragma once

#include <QTextBrowser>


class Console : public QTextBrowser
{
	Q_OBJECT

public:
	Console(QWidget* parent = Q_NULLPTR);
	~Console();
	void append(const QString& text, const QColor& color = Qt::white);
private:
	bool atBottom;
public slots:
	void textChangedSlot();
	void error(QString);
	void info(const QString& text);
	void tip(const QString& text);
	void clickLink(const QUrl&);
signals:
	void errorSignal(QString);
	void tipSignal(QString);
	void infoSignal(QString);
};
