#-------------------------------------------------
#
# Project created by QtCreator 2014-01-22T00:25:08
#
#-------------------------------------------------

QT       += core gui
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = predator_prey
TEMPLATE = app


SOURCES += main.cpp\
    mainwindow.cpp \
    qcustomplot.cpp \
    dialog.cpp \
    mainwindow_konk.cpp \
    mainwindow_kryj.cpp

HEADERS  += \
    mainwindow.h \
    qcustomplot.h \
    dialog.h \
    mainwindow_konk.h \
    mainwindow_kryj.h

FORMS    += \
    mainwindow.ui \
    dialog.ui \
    mainwindow_kryj.ui \
    mainwindow_konk.ui

RESOURCES += \
    obrazek.qrc
