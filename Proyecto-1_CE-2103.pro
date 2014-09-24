#-------------------------------------------------
#
# Project created by QtCreator 2014-09-23T13:21:24
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Proyecto-1_CE-2103
TEMPLATE = app


INCLUDEPATH += $(OPENCVINSTAL)
LIBS += $(OPENCVLIBS)

SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
