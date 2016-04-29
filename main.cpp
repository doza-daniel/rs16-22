#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "tile.h"
#include "roadtile.h"
#include "grasstile.h"
#include "towertile.h"
#include "starttile.h"
#include "endtile.h"
#include "game.h"
#include "map.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    Game game(0, 0, 1000, 800);

    //game.loadMap();

    Map m(16, 20);

    game.show();



    return a.exec();
}
