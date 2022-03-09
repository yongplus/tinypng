#include "Console.h"
#include <QScrollBar>
#include <qDebug>
#include <QDesktopServices>
#include <QMenu>
#include <QContextMenuEvent>

Console::Console(QWidget* parent)
	: QTextBrowser(parent)
{
	setMinimumHeight(100);
	setTextBackgroundColor(QColor(0, 0, 0, 0));
	setStyleSheet("QTextBrowser { \
		background-color: #000000; \
color:#FFFFFF; \
	font-size:15px;\
	font-family:\"sans-serif\", \
}");
	append("The image compression software that is available for png/jpg/jpeg is developed based on the apis offered by tinypng.png.");
	append("GitHub: <a href=\"https://github.com/yongplus/tinypng\" style=\"color:#ffffff\">yongplus/TinyPNG</a>");
	this->setOpenLinks(false);
	this->atBottom = true;
	connect(this, SIGNAL(textChanged()), this, SLOT(textChangedSlot()));
	connect(this, SIGNAL(infoSignal(QString)), this, SLOT(info(QString)));
	connect(this, SIGNAL(tipSignal(QString)), this, SLOT(tip(QString)));
	connect(this, SIGNAL(errorSignal(QString)), this, SLOT(error(QString)));
	connect(this, SIGNAL(anchorClicked(QUrl)), this, SLOT(clickLink(QUrl)));


}

void Console::contextMenuEvent(QContextMenuEvent* event) {
	QMenu* menu = createStandardContextMenu();
	menu->removeAction(menu->actions()[1]);
	menu->actions()[0]->setText("复 制");
	menu->actions()[2]->setText("全 选（Ctrl+A）");

	menu->addAction("清  空", [&]() {this->clear(); });
	if (this->toPlainText().isEmpty()) {
		menu->actions()[3]->setDisabled(true);
	}
	menu->exec(event->globalPos());
	delete menu;
}
void Console::textChangedSlot() {
	if (atBottom) {
		verticalScrollBar()->setValue(verticalScrollBar()->maximum());
	}

}
void Console::append(const QString& text) {
	//setTextColor(color);
	atBottom = false;
	if (verticalScrollBar()->maximum() - verticalScrollBar()->value() < 30) {
		atBottom = true;
	}
	//qDebug() << verticalScrollBar()->maximum() << verticalScrollBar()->value() + verticalScrollBar()->pageStep();

	QTextBrowser::append(text);


}
void Console::info(const QString& text) {

	append(QString("<span style=\"color:#17a81a\">%1</a>").arg(text));
}

void Console::tip(const QString& text) {
	append(QString("<span style=\"color:#ffffff\">%1</a>").arg(text));
}

void Console::error(QString text) {
	append(QString("<span style=\"color:#ff0000\">%1</a>").arg(text));
}

void Console::clickLink(const QUrl& link) {
	QDesktopServices::openUrl(link);
}


Console::~Console()
{
}
