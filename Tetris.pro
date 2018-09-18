#QMAKE_CXXFLAGS_DEBUG +=-gdwarf-3
#-------------------------------------------------
#
# Project created by QtCreator 2018-08-21T17:06:30
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Tetris
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    rect.cpp \
    figure1.cpp \
    rect_figure.cpp \
    figure2.cpp \
    figure3.cpp \
    figure4.cpp \
    figure5.cpp \
    figure6.cpp

HEADERS  += mainwindow.h \
    rect.h \
    figure1.h \
    rect_figure.h \
    figure2.h \
    figure3.h \
    figure4.h \
    figure5.h \
    figure6.h

FORMS    += mainwindow.ui
