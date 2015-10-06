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
    destino.cpp \
    menudestinos.cpp \
    menuempleados.cpp \
    empleado.cpp \
    menuvuelos.cpp \
    modpeso.cpp \
    funciones.cpp \
    hotel.cpp \
    indicehotel.cpp \
    menuhoteles2.cpp \
    listasimple.cpp \
    nododoble.cpp \
    nodosecundario.cpp \
    secundario.cpp

HEADERS  += menu.h \
    destino.h \
    menudestinos.h \
    menuempleados.h \
    empleado.h \
    menuvuelos.h \
    modpeso.h \
    funciones.h \
    hotel.h \
    indicehotel.h \
    menuhoteles2.h \
    listasimple.h \
    nododoble.h \
    nodosecundario.h \
    secundario.h

FORMS    += menu.ui \
    menudestinos.ui \
    menuempleados.ui \
    menuvuelos.ui \
    modpeso.ui \
    menuhoteles2.ui

CONFIG += mobility
MOBILITY = 

