/********************************************************************************
** Form generated from reading UI file 'SettingWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *mailInput;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *keyInput;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *proxyInput;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_6;
    QLineEdit *sizeInput;
    QPushButton *askbtn;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout;
    QCheckBox *newdirCheckBox;
    QCheckBox *replaceCheckBox;
    QPushButton *savebtn;
    QLabel *label_5;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName(QString::fromUtf8("SettingWindow"));
        SettingWindow->setWindowModality(Qt::ApplicationModal);
        SettingWindow->resize(395, 339);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SettingWindow->sizePolicy().hasHeightForWidth());
        SettingWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("\346\226\260\345\256\213\344\275\223"));
        SettingWindow->setFont(font);
        gridLayout = new QGridLayout(SettingWindow);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(10, 30, 10, 10);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 10, -1);
        label = new QLabel(SettingWindow);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(80, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(9);
        label->setFont(font1);
        label->setLineWidth(1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        mailInput = new QLineEdit(SettingWindow);
        mailInput->setObjectName(QString::fromUtf8("mailInput"));
        mailInput->setMinimumSize(QSize(0, 30));
        mailInput->setFont(font1);

        horizontalLayout_2->addWidget(mailInput);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 10, -1);
        label_2 = new QLabel(SettingWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(80, 0));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);

        keyInput = new QLineEdit(SettingWindow);
        keyInput->setObjectName(QString::fromUtf8("keyInput"));
        keyInput->setMinimumSize(QSize(0, 30));
        keyInput->setFont(font1);

        horizontalLayout_3->addWidget(keyInput);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 10, -1);
        label_3 = new QLabel(SettingWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(80, 0));
        label_3->setFont(font1);
        label_3->setLayoutDirection(Qt::LeftToRight);
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(label_3);

        proxyInput = new QLineEdit(SettingWindow);
        proxyInput->setObjectName(QString::fromUtf8("proxyInput"));
        proxyInput->setMinimumSize(QSize(0, 30));
        proxyInput->setFont(font1);

        horizontalLayout_4->addWidget(proxyInput);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, 10, -1);
        label_6 = new QLabel(SettingWindow);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(80, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_6);

        sizeInput = new QLineEdit(SettingWindow);
        sizeInput->setObjectName(QString::fromUtf8("sizeInput"));
        sizeInput->setMinimumSize(QSize(0, 30));
        sizeInput->setFont(font2);

        horizontalLayout_6->addWidget(sizeInput);

        askbtn = new QPushButton(SettingWindow);
        askbtn->setObjectName(QString::fromUtf8("askbtn"));
        sizePolicy.setHeightForWidth(askbtn->sizePolicy().hasHeightForWidth());
        askbtn->setSizePolicy(sizePolicy);
        askbtn->setMaximumSize(QSize(15, 15));
        askbtn->setStyleSheet(QString::fromUtf8("image: url(:/res/icons/ask.png);\n"
"background:none;\n"
"border:none;"));

        horizontalLayout_6->addWidget(askbtn);


        verticalLayout->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 10, -1, 10);
        label_4 = new QLabel(SettingWindow);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(80, 0));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newdirCheckBox = new QCheckBox(SettingWindow);
        buttonGroup = new QButtonGroup(SettingWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(newdirCheckBox);
        newdirCheckBox->setObjectName(QString::fromUtf8("newdirCheckBox"));
        newdirCheckBox->setFont(font1);

        horizontalLayout->addWidget(newdirCheckBox);

        replaceCheckBox = new QCheckBox(SettingWindow);
        buttonGroup->addButton(replaceCheckBox);
        replaceCheckBox->setObjectName(QString::fromUtf8("replaceCheckBox"));
        replaceCheckBox->setFont(font1);

        horizontalLayout->addWidget(replaceCheckBox);


        horizontalLayout_5->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_5);

        savebtn = new QPushButton(SettingWindow);
        savebtn->setObjectName(QString::fromUtf8("savebtn"));
        sizePolicy.setHeightForWidth(savebtn->sizePolicy().hasHeightForWidth());
        savebtn->setSizePolicy(sizePolicy);
        savebtn->setMinimumSize(QSize(150, 40));
        savebtn->setFont(font2);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/res/icons/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        savebtn->setIcon(icon);
#if QT_CONFIG(shortcut)
        savebtn->setShortcut(QString::fromUtf8(""));
#endif // QT_CONFIG(shortcut)

        verticalLayout->addWidget(savebtn, 0, Qt::AlignHCenter);

        label_5 = new QLabel(SettingWindow);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setLayoutDirection(Qt::RightToLeft);
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_5->setOpenExternalLinks(true);

        verticalLayout->addWidget(label_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(SettingWindow);

        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingWindow)
    {
        SettingWindow->setWindowTitle(QCoreApplication::translate("SettingWindow", "\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("SettingWindow", "Mail:", nullptr));
        label_2->setText(QCoreApplication::translate("SettingWindow", "Key:", nullptr));
        label_3->setText(QCoreApplication::translate("SettingWindow", "\344\273\243\347\220\206:", nullptr));
#if QT_CONFIG(tooltip)
        label_6->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_6->setText(QCoreApplication::translate("SettingWindow", "\346\234\200\344\275\216\345\244\247\345\260\217(KB):", nullptr));
        sizeInput->setInputMask(QString());
        sizeInput->setPlaceholderText(QString());
        askbtn->setText(QString());
#if QT_CONFIG(tooltip)
        label_4->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_4->setText(QCoreApplication::translate("SettingWindow", "\350\276\223\345\207\272\346\250\241\345\274\217:", nullptr));
        newdirCheckBox->setText(QCoreApplication::translate("SettingWindow", "\346\226\260\347\233\256\345\275\225", nullptr));
        replaceCheckBox->setText(QCoreApplication::translate("SettingWindow", "\350\246\206\347\233\226", nullptr));
        savebtn->setText(QCoreApplication::translate("SettingWindow", "\344\277\235 \345\255\230", nullptr));
        label_5->setText(QCoreApplication::translate("SettingWindow", "<html><head/><body><p><a href=\"https://tinypng.com/developers\"><span style=\" text-decoration: underline; color:#0000ff;\">Go Applying Key</span></a></p></body></html>", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingWindow: public Ui_SettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
