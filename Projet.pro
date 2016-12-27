#-------------------------------------------------
#
# Project created by QtCreator 2016-12-24T20:39:48
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Projet
TEMPLATE = app

#CONFIG += c++11
QMAKE_CXXFLAGS += -std=c++11
SOURCES += main.cpp\
        mainwindow.cpp \
    NFederation.cpp \
    Democratie.cpp \
    Federation.cpp \
    Parti.cpp \
    Pays.cpp \
    Tyrannie.cpp

HEADERS  += mainwindow.hh \
    Democratie.hh \
    Federation.hh \
    NFederation.hh \
    Parti.hh \
    Pays.hh \
    Tyrannie.hh

FORMS    += mainwindow.ui

DISTFILES += \
    nom_pays.txt
