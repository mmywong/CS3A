TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
QT+= core gui widgets opengl

SOURCES += main.cpp \
    mygui.cpp \
    glwidget.cpp

HEADERS += \
    mygui.h \
    glwidget.h

