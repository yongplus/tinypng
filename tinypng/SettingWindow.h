#pragma once

#include <QWidget>
#include "ui_SettingWindow.h"
#include "Config.h"

class SettingWindow : public QWidget
{
	Q_OBJECT

public:
	SettingWindow(QWidget* parent = Q_NULLPTR);
	~SettingWindow();
	void setValues();

public slots:
	void onClickSaveBtn();

private:
	Ui::SettingWindow ui;
};
