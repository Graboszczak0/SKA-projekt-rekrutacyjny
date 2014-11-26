#-------------------------------------------------
#
# Project created by QtCreator 2014-11-08T21:49:55
#
#-------------------------------------------------

QT       += core
QT       += network
QT       += serialport

QT       -= gui

TARGET = Serwer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    myserver.cpp \
    mycommands.cpp \
    myserial.cpp

HEADERS += \
    myserver.h \
    mycommands.h \
    myserial.h
