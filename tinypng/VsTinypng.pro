# Created by and for Qt Creator This file was created for editing the project sources only.
# You may attempt to use it for building too, by modifying this file here.

#TARGET = VsTinypng

QT = core gui widgets network

CONFIG += c++11

HEADERS = \
   $$PWD/Compress.h \
   $$PWD/Dispatcher.h \
   $$PWD/Config.h \
   $$PWD/Console.h \
   $$PWD/GridTableHeaderModel.h \
   $$PWD/GridTableHeaderView.h \
   $$PWD/MainWindow.h \
   $$PWD/MyOverlay.h \
   $$PWD/MyTableView.h \
   $$PWD/resource.h \
   $$PWD/Scanner.h \
   $$PWD/SettingWindow.h \
   $$PWD/SingleApplication.h \
   $$PWD/TableHeaderItem.h \
   $$PWD/TableModel.h \
   $$PWD/Utility.h \

SOURCES = \
   $$PWD/Compress.cpp \
   $$PWD/Dispatcher.cpp \
   $$PWD/Config.cpp \
   $$PWD/Console.cpp \
   $$PWD/GridTableHeaderModel.cpp \
   $$PWD/GridTableHeaderView.cpp \
   $$PWD/main.cpp \
   $$PWD/MainWindow.cpp \
   $$PWD/MyOverlay.cpp \
   $$PWD/MyTableView.cpp \
   $$PWD/Scanner.cpp \
   $$PWD/SettingWindow.cpp \
   $$PWD/SingleApplication.cpp \
   $$PWD/TableHeaderItem.cpp \
   $$PWD/TableModel.cpp \
   $$PWD/Utility.cpp \

INCLUDEPATH = \
    $$PWD/.
FORMS += \
    SettingWindow.ui

RC_ICONS = logo.ico
ICON = icon.icns
RESOURCES += \
    Resource.qrc

#DEFINES = 

