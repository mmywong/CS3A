TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    map.cpp \
    coord.cpp \
    terrorist.cpp \
    counterterrorist.cpp

HEADERS += \
    player.h \
    map.h \
    coord.h \
    terrorist.h \
    counterterrorist.h \
    constants.h

