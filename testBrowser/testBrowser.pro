#-------------------------------------------------
#
# Project created by QtCreator 2015-12-15T09:35:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets webkitwidgets

TARGET = testBrowser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcgaugewidget.cpp \
    qcustomgauge.cpp \
    aboutteamevo.cpp \
    aboutelectromobility.cpp

HEADERS  += mainwindow.h \
    qcgaugewidget.h \
    qcustomgauge.h \
    aboutteamevo.h \
    aboutelectromobility.h

FORMS    += mainwindow.ui \
    aboutteamevo.ui \
    aboutelectromobility.ui

RESOURCES += \
    imgs.qrc
