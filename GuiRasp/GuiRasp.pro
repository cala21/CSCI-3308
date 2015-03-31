#-------------------------------------------------
#
# Project created by QtCreator 2015-03-29T02:30:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GuiRasp
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    sett.cpp \
    datetime.cpp \
    usr.cpp \
    memory.cpp

HEADERS  += mainwindow.h \
    sett.h \
    datetime.h \
    usr.h \
    memory.h

FORMS    += mainwindow.ui \
    sett.ui \
    datetime.ui \
    usr.ui \
    memory.ui

RESOURCES += \
    images.qrc
