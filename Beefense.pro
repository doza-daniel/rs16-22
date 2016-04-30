#-------------------------------------------------
#
# Project created by QtCreator 2016-04-25T21:26:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MapTD
TEMPLATE = app


SOURCES += main.cpp \
    tile.cpp \
    roadtile.cpp \
    grasstile.cpp \
    towertile.cpp \
    starttile.cpp \
    endtile.cpp \
    game.cpp \
    map.cpp \
    enemy.cpp \
    tower.cpp \
    projectile.cpp \
    spawner.cpp

HEADERS  += \
    tile.h \
    roadtile.h \
    grasstile.h \
    towertile.h \
    starttile.h \
    endtile.h \
    game.h \
    enemy.h \
    map.h \
    tower.h \
    projectile.h \
    spawner.h

RESOURCES += \
    resources.qrc
