#-------------------------------------------------
#
# Project created by QtCreator 2015-12-15T09:35:42
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

TARGET = testBrowser
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcgaugewidget.cpp \
    qcustomgauge.cpp \
    aboutteamevo.cpp \
    aboutelectromobility.cpp \
    preferences.cpp

HEADERS  += mainwindow.h \
    qcgaugewidget.h \
    qcustomgauge.h \
    aboutteamevo.h \
    aboutelectromobility.h \
    preferences.h

FORMS    += mainwindow.ui \
    aboutteamevo.ui \
    aboutelectromobility.ui \
    preferences.ui

RESOURCES += \
    imgs.qrc
