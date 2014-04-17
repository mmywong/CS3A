TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
QT += core gui widgets opengl

SOURCES += main.cpp \
    mygui.cpp \
    glwidget.cpp \
    coord.cpp \
    polygon.cpp

HEADERS += \
    mygui.h \
    glwidget.h \
    coord.h \
    polygon.h

