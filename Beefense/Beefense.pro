#-------------------------------------------------
#
# Project created by QtCreator 2016-05-05T23:11:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BeefenseTD
TEMPLATE = app


SOURCES += \
    Logic/enemy.cpp \
    Logic/game.cpp \
    Logic/map.cpp \
    Logic/spawner.cpp \
    Menu/dialog.cpp \
    Menu/mainwindow.cpp \
    Tiles/Towers/attackarea.cpp \
    Tiles/Towers/projectile.cpp \
    Tiles/Towers/toweractive.cpp \
    Tiles/Towers/towertile.cpp \
    Tiles/endtile.cpp \
    Tiles/grasstile.cpp \
    Tiles/roadtile.cpp \
    Tiles/starttile.cpp \
    Tiles/tile.cpp \
    main.cpp \
    Tiles/Towers/greaterattacktower.cpp \
    Tiles/Towers/greaterrangetower.cpp \
    Menu/createtower.cpp \
    Logic/levelreader.cpp \
    Logic/level.cpp \
    Menu/destroytower.cpp \
    Logic/enumhead.cpp

HEADERS  += \
    Logic/enemy.h \
    Logic/game.h \
    Logic/map.h \
    Logic/spawner.h \
    Menu/dialog.h \
    Menu/mainwindow.h \
    Tiles/Towers/attackarea.h \
    Tiles/Towers/projectile.h \
    Tiles/Towers/toweractive.h \
    Tiles/Towers/towertile.h \
    Tiles/endtile.h \
    Tiles/grasstile.h \
    Tiles/roadtile.h \
    Tiles/starttile.h \
    Tiles/tile.h \
    Tiles/Towers/greaterattacktower.h \
    Tiles/Towers/greaterrangetower.h \
    Menu/createtower.h \
    Logic/levelreader.h \
    Logic/level.h \
    Menu/destroytower.h \
    Logic/enumhead.h

FORMS    += \
    Menu/dialog.ui \
    Menu/mainwindow.ui \
    Menu/createtower.ui \
    Menu/destroytower.ui

RESOURCES += \
    Data/resources.qrc
