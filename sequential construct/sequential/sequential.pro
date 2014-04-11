TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    list.cpp \
    iterator.cpp \
    sortedlist.cpp \
    cursoredlist.cpp

HEADERS += \
    list.h \
    iterator.h \
    node.h \
    sortedlist.h \
    cursoredlist.h

