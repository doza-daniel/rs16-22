#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "Menu/mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


//    Game game(0, 0, 1000, 800);

    /*Pavle's test case*/
//    QVector<Tile*> towers = game.getMap().getTowers();
//    for(auto &t:towers){
//        QPointF pos = t->pos();
//        auto tmp = t;
//        t = new Tower(pos.x(),pos.y(),game);
//        game.addItem(t);
//        delete tmp;
//    }

//    game.show();

    MainWindow w;
    w.show();


    return a.exec();
}
