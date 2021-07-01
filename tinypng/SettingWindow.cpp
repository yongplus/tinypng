#include "SettingWindow.h"
#include <QMessageBox>

SettingWindow::SettingWindow(QWidget* parent)
	: QWidget(parent)
{
	ui.setupUi(this);
	this->setWindowFlags(Qt::Dialog);
	this->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
	this->setFixedSize(this->width(), this->height());
	connect(ui.savebtn, SIGNAL(clicked()), this, SLOT(onClickSaveBtn()));
	this->setValues();
}

void SettingWindow::setValues() {
	configItem item = Config(this).get();
	ui.mailInput->setText(item.mail);
	ui.keyInput->setText(item.key);
	ui.proxyInput->setText(item.proxy);

	if (item.outputMode == 0) {
		ui.newdirCheckBox->setChecked(true);
	}
	else {
		ui.replaceCheckBox->setChecked(true);
	}
}

void SettingWindow::onClickSaveBtn() {
	configItem item;
	item.mail = ui.mailInput->text();
	item.key = ui.keyInput->text();

	if (item.mail.length() == 0 || item.key.length() == 0) {
		QMessageBox::warning(this, "提  示", "Mail和Key不能为空", QMessageBox::Ok);
		return;
	}
	item.proxy = ui.proxyInput->text();
	item.outputMode = ui.newdirCheckBox->isChecked() ? OutputMode::NewDir : OutputMode::Replace;
	Config(this).set(item);
	QMessageBox::information(this, "提  示", "保存成功", QMessageBox::Ok);
	this->close();
}

SettingWindow::~SettingWindow()
{
}
