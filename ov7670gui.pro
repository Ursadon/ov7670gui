#-------------------------------------------------
#
# Project created by QtCreator 2013-04-13T10:36:24
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ov7670gui
TEMPLATE = app


SOURCES += main.cpp\
        ov7670.cpp \
    camerashow.cpp \
    optionsui.cpp

HEADERS  += ov7670.h \
    camerashow.h \
    optionsui.h

FORMS    += ov7670.ui \
    camerashow.ui \
    optionsui.ui
