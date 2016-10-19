#-------------------------------------------------
#
# Project created by QtCreator 2016-10-17T11:03:41
#
#-------------------------------------------------

QT       += core gui multimedia multimediawidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = WebCamera
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp

HEADERS  += widget.h

FORMS    += widget.ui

QMAKE_CXXFLAGS += -std=gnu++14
