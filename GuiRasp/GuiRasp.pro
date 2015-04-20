#-------------------------------------------------
#
# Project created by QtCreator 2015-03-29T02:30:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets


TARGET = GuiRasp
TEMPLATE = app

LIBS += \
       -lboost_system\
       -lboost_filesystem\

SOURCES += main.cpp\
        mainwindow.cpp \
    sett.cpp \
    usr.cpp \
    memory.cpp \
    cpu.cpp

HEADERS  += mainwindow.h \
    sett.h \
    usr.h \
    memory.h \
    cpu.h

FORMS    += mainwindow.ui \
    sett.ui \
    usr.ui \
    memory.ui \
    cpu.ui

RESOURCES += \
    images.qrc
