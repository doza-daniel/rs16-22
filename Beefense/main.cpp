#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>

#include "Menu/mainwindow.h"
#include "Logic/level.h"

int main(int argc, char *argv[])
{
   /*
    QApplication a(argc, argv);

    MainWindow w;
    w.show();


    return a.exec();
    */
    Level::getLevels(":/levels/levels.xml");

    return 0;
}
