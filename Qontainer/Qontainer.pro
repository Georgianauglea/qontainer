#-------------------------------------------------
#
# Project created by QtCreator 2018-12-07T14:36:41
#
#-------------------------------------------------

QT       += core gui
QT += xml
QT += widgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Qontainer
TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11

SOURCES += View/main.cpp\
    ./Model/device.cpp \
    Model/portable.cpp \
    Model/tablet.cpp \
    Model/smartphone.cpp \
    Model/computer.cpp \
    Model/laptop.cpp \
    Model/desktop.cpp \
    View/mainwindow.cpp \
    xmlutility.cpp \
    View/searchelement.cpp \
    View/insertdesktop.cpp \
    View/insertlaptop.cpp \
    View/inseriscismartphone.cpp \
    View/inseriscitablet.cpp \
    View/modifyelement.cpp \
    View/deleteelement.cpp

HEADERS  += \
    ./Model/device.h \
    Model/portable.h \
    Model/tablet.h \
    Model/smartphone.h \
    Model/laptop.h \
    Model/desktop.h \
    Model/computer.h \
    Model/container.h \
    View/mainwindow.h \
    xmlutility.h \
    View/seachelement.h \
    View/insertdesktop.h \
    View/insertlaptop.h \
    View/inseriscismartphone.h \
    View/inseriscitablet.h \
    View/modifyelement.h \
    View/deleteelement.h

DISTFILES += \
    Container.xml

