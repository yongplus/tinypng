/********************************************************************************
** Form generated from reading UI file 'Console.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONSOLE_H
#define UI_CONSOLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_Console
{
public:

    void setupUi(QTextBrowser *Console)
    {
        if (Console->objectName().isEmpty())
            Console->setObjectName(QString::fromUtf8("Console"));
        Console->resize(400, 300);

        retranslateUi(Console);

        QMetaObject::connectSlotsByName(Console);
    } // setupUi

    void retranslateUi(QTextBrowser *Console)
    {
        Console->setWindowTitle(QCoreApplication::translate("Console", "Console", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Console: public Ui_Console {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONSOLE_H
