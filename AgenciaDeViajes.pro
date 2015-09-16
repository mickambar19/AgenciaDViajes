#-------------------------------------------------
#
# Project created by QtCreator 2015-09-16T13:50:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = AgenciaDeViajes
TEMPLATE = app


SOURCES += main.cpp\
        menu.cpp \
    destino.cpp

HEADERS  += menu.h \
    destino.h

FORMS    += menu.ui

CONFIG += mobility
MOBILITY = 

