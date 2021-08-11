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
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SettingWindow
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *radioButtonWeb;
    QRadioButton *radioButtonKey;
    QLabel *label_8;
    QWidget *widget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *mailinput;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *keyInput;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *proxyInput;
    QGroupBox *groupBox;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_2;
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
    QButtonGroup *buttonGroup_2;

    void setupUi(QWidget *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName(QString::fromUtf8("SettingWindow"));
        SettingWindow->setWindowModality(Qt::ApplicationModal);
        SettingWindow->resize(414, 468);
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
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(10, 20, 10, 10);
        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(-1, 0, -1, 10);
        label_7 = new QLabel(SettingWindow);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        sizePolicy.setHeightForWidth(label_7->sizePolicy().hasHeightForWidth());
        label_7->setSizePolicy(sizePolicy);
        label_7->setMinimumSize(QSize(90, 0));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        font1.setPointSize(9);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(label_7);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        radioButtonWeb = new QRadioButton(SettingWindow);
        buttonGroup_2 = new QButtonGroup(SettingWindow);
        buttonGroup_2->setObjectName(QString::fromUtf8("buttonGroup_2"));
        buttonGroup_2->addButton(radioButtonWeb);
        radioButtonWeb->setObjectName(QString::fromUtf8("radioButtonWeb"));

        horizontalLayout_8->addWidget(radioButtonWeb);

        radioButtonKey = new QRadioButton(SettingWindow);
        buttonGroup_2->addButton(radioButtonKey);
        radioButtonKey->setObjectName(QString::fromUtf8("radioButtonKey"));

        horizontalLayout_8->addWidget(radioButtonKey);


        horizontalLayout_7->addLayout(horizontalLayout_8);


        verticalLayout->addLayout(horizontalLayout_7);

        label_8 = new QLabel(SettingWindow);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(label_8->sizePolicy().hasHeightForWidth());
        label_8->setSizePolicy(sizePolicy1);
        label_8->setMinimumSize(QSize(0, 80));
        label_8->setAlignment(Qt::AlignCenter);
        label_8->setWordWrap(true);

        verticalLayout->addWidget(label_8);

        widget = new QWidget(SettingWindow);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy2(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy2);
        widget->setMinimumSize(QSize(0, 80));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, -1, 371, 81));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(-1, -1, 0, -1);
        label_2 = new QLabel(layoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setMinimumSize(QSize(90, 0));
        label_2->setFont(font1);
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_2);

        mailinput = new QLineEdit(layoutWidget);
        mailinput->setObjectName(QString::fromUtf8("mailinput"));
        mailinput->setMinimumSize(QSize(0, 30));
        mailinput->setFont(font1);

        horizontalLayout_3->addWidget(mailinput);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 0, -1);
        label = new QLabel(layoutWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setMinimumSize(QSize(90, 0));
        label->setFont(font1);
        label->setLineWidth(1);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(label);

        keyInput = new QLineEdit(layoutWidget);
        keyInput->setObjectName(QString::fromUtf8("keyInput"));
        keyInput->setMinimumSize(QSize(0, 30));
        keyInput->setFont(font1);

        horizontalLayout_2->addWidget(keyInput);


        verticalLayout_3->addLayout(horizontalLayout_2);


        verticalLayout->addWidget(widget);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(-1, -1, 0, 10);
        label_3 = new QLabel(SettingWindow);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setMinimumSize(QSize(90, 0));
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

        groupBox = new QGroupBox(SettingWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        sizePolicy2.setHeightForWidth(groupBox->sizePolicy().hasHeightForWidth());
        groupBox->setSizePolicy(sizePolicy2);
        groupBox->setMinimumSize(QSize(0, 100));
        groupBox->setMaximumSize(QSize(16777215, 300));
        layoutWidget1 = new QWidget(groupBox);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(0, 20, 371, 78));
        verticalLayout_2 = new QVBoxLayout(layoutWidget1);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(-1, -1, 10, -1);
        label_6 = new QLabel(layoutWidget1);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setMinimumSize(QSize(90, 0));
        QFont font2;
        font2.setFamily(QString::fromUtf8("\345\256\213\344\275\223"));
        label_6->setFont(font2);
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(label_6);

        sizeInput = new QLineEdit(layoutWidget1);
        sizeInput->setObjectName(QString::fromUtf8("sizeInput"));
        sizeInput->setMinimumSize(QSize(0, 30));
        sizeInput->setFont(font2);

        horizontalLayout_6->addWidget(sizeInput);

        askbtn = new QPushButton(layoutWidget1);
        askbtn->setObjectName(QString::fromUtf8("askbtn"));
        sizePolicy.setHeightForWidth(askbtn->sizePolicy().hasHeightForWidth());
        askbtn->setSizePolicy(sizePolicy);
        askbtn->setMaximumSize(QSize(15, 15));
        askbtn->setStyleSheet(QString::fromUtf8("image: url(:/res/icons/ask.png);\n"
"background:none;\n"
"border:none;"));

        horizontalLayout_6->addWidget(askbtn);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(-1, 10, -1, 10);
        label_4 = new QLabel(layoutWidget1);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        sizePolicy.setHeightForWidth(label_4->sizePolicy().hasHeightForWidth());
        label_4->setSizePolicy(sizePolicy);
        label_4->setMinimumSize(QSize(90, 0));
        label_4->setFont(font1);
        label_4->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(label_4);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        newdirCheckBox = new QCheckBox(layoutWidget1);
        buttonGroup = new QButtonGroup(SettingWindow);
        buttonGroup->setObjectName(QString::fromUtf8("buttonGroup"));
        buttonGroup->addButton(newdirCheckBox);
        newdirCheckBox->setObjectName(QString::fromUtf8("newdirCheckBox"));
        newdirCheckBox->setFont(font1);

        horizontalLayout->addWidget(newdirCheckBox);

        replaceCheckBox = new QCheckBox(layoutWidget1);
        buttonGroup->addButton(replaceCheckBox);
        replaceCheckBox->setObjectName(QString::fromUtf8("replaceCheckBox"));
        replaceCheckBox->setFont(font1);

        horizontalLayout->addWidget(replaceCheckBox);


        horizontalLayout_5->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(horizontalLayout_5);


        verticalLayout->addWidget(groupBox);

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
        QObject::connect(radioButtonWeb, SIGNAL(toggled(bool)), label_8, SLOT(setVisible(bool)));
        QObject::connect(radioButtonKey, SIGNAL(toggled(bool)), widget, SLOT(setVisible(bool)));

        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QWidget *SettingWindow)
    {
        SettingWindow->setWindowTitle(QCoreApplication::translate("SettingWindow", "\350\256\276\347\275\256", nullptr));
#if QT_CONFIG(tooltip)
        label_7->setToolTip(QString());
#endif // QT_CONFIG(tooltip)
        label_7->setText(QCoreApplication::translate("SettingWindow", "\350\272\253\344\273\275\346\250\241\345\274\217:", nullptr));
        radioButtonWeb->setText(QCoreApplication::translate("SettingWindow", "\345\205\215key", nullptr));
        radioButtonKey->setText(QCoreApplication::translate("SettingWindow", "ApiKey", nullptr));
        label_8->setText(QCoreApplication::translate("SettingWindow", "<html><head/><body><p>\345\205\215Key\346\250\241\345\274\217\357\274\214\350\275\257\344\273\266\346\250\241\346\213\237\347\224\250\346\210\267\346\223\215\344\275\234Tinypng\347\275\221\347\253\231\357\274\214\346\227\240\351\234\200\347\224\263\350\257\267Api Key</p></body></html>", nullptr));
        label_2->setText(QCoreApplication::translate("SettingWindow", "Mail:", nullptr));
        label->setText(QCoreApplication::translate("SettingWindow", "Key:", nullptr));
        label_3->setText(QCoreApplication::translate("SettingWindow", "\344\273\243\347\220\206:", nullptr));
        proxyInput->setPlaceholderText(QCoreApplication::translate("SettingWindow", "http://ip:port", nullptr));
        groupBox->setTitle(QCoreApplication::translate("SettingWindow", "\344\273\245\344\270\213\351\205\215\347\275\256\344\273\205\345\257\271\347\233\256\345\275\225\346\234\211\346\225\210", nullptr));
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
