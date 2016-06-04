#ifndef MAP_H
#define MAP_H

#include "Tiles/tile.h"

#include <QStringList>
#include <QVector>
#include <QString>
#include <QPointF>
#include <QGraphicsScene>

class Map
{
public:
    Map(int rows, int cols, QStringList csv);
    QVector<QPointF *> getPath() const;
    QVector< QVector<Tile *> > getMap() const;
    QVector<Tile *> getTowers() const;
    Tile *getStart() const;
    Tile *getEnd() const;
    int getRows() const;
    int getCols() const;

private:
    int mRows;
    int mCols;
    Tile *mStart;
    Tile *mEnd;
    QVector< QVector<Tile *> > mMap;
    QVector<QPointF *> mPath;
    QVector<Tile *> mTowers;


    enum class Direction {
        None, Up, Down, Left, Right
    };

    void loadMap(QStringList csv);
    void generatePath();
    Direction nextDirection(int i, int j, Direction curr) const;
    QVector< QVector<TileType> > readCSVMap(QStringList csv);


};

#endif // MAP_H
