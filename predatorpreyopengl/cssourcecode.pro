#-------------------------------------------------
#
# Project created by QtCreator 2013-12-04T13:38:25
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = GoL2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mypanelopengl.cpp \
    coord.cpp \
    counterterrorist.cpp \
    player.cpp \
    terrorist.cpp \
    csmap.cpp

HEADERS  += mainwindow.h \
    mypanelopengl.h \
    GameofLife.h \
    constants.h \
    coord.h \
    counterterrorist.h \
    player.h \
    terrorist.h \
    csmap.h

FORMS    += mainwindow.ui
