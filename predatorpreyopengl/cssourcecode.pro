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
    map.cpp \
    player.cpp \
    terrorist.cpp

HEADERS  += mainwindow.h \
    mypanelopengl.h \
    GameofLife.h \
    constants.h \
    coord.h \
    counterterrorist.h \
    map.h \
    player.h \
    terrorist.h

FORMS    += mainwindow.ui
