#pragma once

#include <QWidget>
#include <QKeyEvent>
#include <QToolTip>
#include "ui_SettingWindow.h"
#include "Config.h"

class SettingWindow : public QWidget
{
	Q_OBJECT

public:
	SettingWindow(QWidget* parent = Q_NULLPTR);
	~SettingWindow();
	void setValues();
	void keyPressEvent(QKeyEvent* event);

public slots:
	void onClickSaveBtn();
	void onShowSizeExplain();

private:
	Ui::SettingWindow* ui;
	QToolTip* tooltip;
};
