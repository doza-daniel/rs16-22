#-------------------------------------------------
#
# Project created by QtCreator 2016-04-25T21:26:58
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BeefenseTD
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
    projectile.cpp \
    spawner.cpp \
    mainwindow.cpp \
    dialog.cpp \
    toweractive.cpp \
    attackarea.cpp

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
    projectile.h \
    spawner.h \
    mainwindow.h \
    dialog.h \
    toweractive.h \
    attackarea.h

RESOURCES += \
    resources.qrc

FORMS += \
    mainwindow.ui \
    dialog.ui
