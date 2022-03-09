#include "SettingWindow.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QDebug>

SettingWindow::SettingWindow(QWidget* parent)
	: QWidget(parent),
	ui(new Ui::SettingWindow)
{
	ui->setupUi(this);
	this->setWindowFlags(Qt::Dialog);
	this->setAttribute(Qt::WA_DeleteOnClose);
	this->setWindowFlag(Qt::WindowContextHelpButtonHint, false);
	this->setFixedSize(this->width(), this->height() - ui->widget->height());
	connect(ui->savebtn, SIGNAL(clicked()), this, SLOT(onClickSaveBtn()));
	connect(ui->askbtn, SIGNAL(clicked()), this, SLOT(onShowSizeExplain()));
	ui->sizeInput->setValidator(new QIntValidator(0, 200000, this));
	ui->sizeInput_2->setValidator(new QIntValidator(0, 200000, this));
	this->setValues();

}

void SettingWindow::setValues() {
	configItem item = Config(this).get();
	if (item.tinyReqMode == TinyReqMode::Web) {
		ui->radioButtonWeb->setChecked(true);
		ui->widget->hide();
	}
	else {
		ui->radioButtonKey->setChecked(true);
		ui->label_8->hide();
	}
	ui->mailinput->setText(item.mail);
	ui->keyInput->setText(item.key);
	ui->proxyInput->setText(item.proxy);
	ui->sizeInput->setText(QString("%1").arg(item.minsize / 1024));
	ui->sizeInput_2->setText(QString("%1").arg(item.maxsize / 1024));
	if (item.outputMode == OutputMode::NewDir) {
		ui->newdirCheckBox->setChecked(true);
	}
	else {
		ui->replaceCheckBox->setChecked(true);
	}
	ui->checkBoxAutoStart->setChecked(item.autoStart);
}
void SettingWindow::keyPressEvent(QKeyEvent* event) {
	if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter) {
		this->onClickSaveBtn();
	}
	else if (event->key() == Qt::Key_Escape) {
		this->close();
	}
}

void SettingWindow::onClickSaveBtn() {
	configItem item;
	item.mail = ui->mailinput->text();
	item.key = ui->keyInput->text();
	item.tinyReqMode = ui->radioButtonWeb->isChecked() ? TinyReqMode::Web : TinyReqMode::Key;

	if ((item.mail.length() == 0 || item.key.length() == 0) && item.tinyReqMode == TinyReqMode::Key) {
		QMessageBox::warning(this, "提  示", "Mail和Key不能为空", QMessageBox::Ok);
		return;
	}
	item.proxy = ui->proxyInput->text();
	item.minsize = ui->sizeInput->text().toInt() * 1024;
	item.maxsize = ui->sizeInput_2->text().toInt() * 1024;
	item.outputMode = ui->newdirCheckBox->isChecked() ? OutputMode::NewDir : OutputMode::Replace;
	item.autoStart = ui->checkBoxAutoStart->isChecked();
	Config(this).set(item);
	QMessageBox::information(this, "提  示", "保存成功", QMessageBox::Ok);
	this->close();
}

void SettingWindow::onShowSizeExplain() {
	QPoint pos = ui->askbtn->mapToGlobal(QPoint(0, 0));
	QToolTip::showText(pos, "仅压缩设定大小范围内的图片");
}



SettingWindow::~SettingWindow()
{
	delete ui;
}
