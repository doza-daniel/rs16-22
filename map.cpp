#include "map.h"
#include <QFile>
#include <QDebug>
#include <QStringList>
#include <iostream>
#include <cstdlib>

#include "grasstile.h"
#include "roadtile.h"
#include "starttile.h"
#include "endtile.h"
#include "towertile.h"

QVector<QString> levelList = {
    QString(":/map/levels/01.txt")
};

Map::Map(int rows, int cols, int level)
    : mRows(rows),
      mCols(cols),
      mLevel(level),
      mMap(rows, QVector<Tile *>(cols)),
      mPath(),
      mTowers()
{
    mStart = nullptr;
    mEnd = nullptr;
    loadMap();
    generatePath();
}

void Map::loadMap()
{
    QVector< QVector<TileType> > typeMap = readCSVMap();
    if(typeMap.size() != mRows || typeMap[0].size() != mCols) {
        qDebug() << "Invalid map size!";
    }

    for(int i = 0; i < mRows; ++i) {
        for(int j = 0; j < mCols; ++j) {
            Tile *newTile;
            bool up     = false;
            bool down   = false;
            bool left   = false;
            bool right  = false;

            switch(typeMap[i][j]) {
            case TileType::Grass:
                newTile = new GrassTile(TILE_DIM, j * TILE_DIM, i * TILE_DIM);
                break;
            case TileType::Tower:
                newTile = new TowerTile(TILE_DIM, j * TILE_DIM, i * TILE_DIM);
                mTowers.push_back(newTile);
                break;
            case TileType::Start:
                newTile = new StartTile(TILE_DIM, j * TILE_DIM, i * TILE_DIM);
                mStart = newTile;
                break;
            case TileType::End:
                newTile = new EndTile(TILE_DIM, j * TILE_DIM, i * TILE_DIM);
                mEnd = newTile;
                break;
            case TileType::Road:
                up = typeMap[i - 1][j] == TileType::End || typeMap[i - 1][j] == TileType::Start
                        || typeMap[i - 1][j] == TileType::Road;
                down = typeMap[i + 1][j] == TileType::End || typeMap[i + 1][j] == TileType::Start
                        || typeMap[i + 1][j] == TileType::Road;
                left = typeMap[i][j - 1] == TileType::End || typeMap[i][j - 1] == TileType::Start
                        || typeMap[i][j - 1] == TileType::Road;
                right = typeMap[i][j + 1] == TileType::End || typeMap[i][j + 1] == TileType::Start
                        || typeMap[i][j + 1] == TileType::Road;

                if(left && right) {
                    newTile = new RoadTile(RoadTileType::Tunnel, TILE_DIM, j * TILE_DIM, i * TILE_DIM);
                } else if(up && down) {
                    newTile = new RoadTile(RoadTileType::Tunnel, TILE_DIM, j * TILE_DIM, i * TILE_DIM);
                    newTile->rotate(90);
                } else if(left && down) {
                    newTile = new RoadTile(RoadTileType::Corner, TILE_DIM, j * TILE_DIM, i * TILE_DIM);
                } else if(up && left) {
                    newTile = new RoadTile(RoadTileType::Corner, TILE_DIM, j * TILE_DIM, i * TILE_DIM);
                    newTile->rotate(90);
                } else if(up && right) {
                    newTile = new RoadTile(RoadTileType::Corner, TILE_DIM, j * TILE_DIM, i * TILE_DIM);
                    newTile->rotate(180);
                } else if(right && down) {
                    newTile = new RoadTile(RoadTileType::Corner, TILE_DIM, j * TILE_DIM, i * TILE_DIM);
                    newTile->rotate(270);
                } else {
                    qDebug() << "Invalid map layout!";
                    exit(1);
                }
                break;
            }

            mMap[i][j] = newTile;
        }
    }
}



QVector< QVector<TileType> > Map::readCSVMap()
{
    QVector< QVector<TileType> > typeMap(mRows, QVector<TileType>(mCols));
    QFile mapFile(levelList[mLevel - 1]);

    if(!mapFile.open(QFile::ReadOnly | QFile::Text)) {
        qDebug() << "Cannot open " << levelList[mLevel - 1] << " for reading!";
        return typeMap;
    }

    int row = 0;
    int numOfStart = 0, numOfEnd = 0;
    while(!mapFile.atEnd()) {
        QString line = mapFile.readLine().trimmed();
        QStringList tiles;
        tiles = line.split(',');

        int col = 0;
        for(auto i = tiles.begin(); i != tiles.end(); ++i, ++col) {
            if((*i).trimmed() == "g") {
               typeMap[row][col] = TileType::Grass;
            } else if((*i).trimmed() == "r") {
               typeMap[row][col] = TileType::Road;
            } else if((*i).trimmed() == "t") {
               typeMap[row][col] = TileType::Tower;
            } else if((*i).trimmed() == "s") {
               typeMap[row][col] = TileType::Start;
               numOfStart++;
            } else if((*i).trimmed() == "e") {
               typeMap[row][col] = TileType::End;
               numOfEnd++;
            } else {
               qDebug() << "Undefined symbol " << *i;
               exit(EXIT_FAILURE);
            }
        }
        row++;
    }

    if(numOfEnd != 1 || numOfStart != 1) {
        qDebug() << "Invalid map format";
        exit(EXIT_FAILURE);
    }
    return typeMap;
}

void Map::generatePath()
{
    int i = mStart->y() / TILE_DIM;
    int j = mStart->x() / TILE_DIM;
    Direction d = Direction::None;

    while(mMap[i][j]->getTileType() != TileType::End) {
        QPointF nextPoint = mMap[i][j]->mapToScene(mMap[i][j]->getCenter());
        mPath.push_back(new QPointF(nextPoint.x(), nextPoint.y()));
        d = nextDirection(i, j, d);
        switch(d) {
        case Direction::Up:
            i--; break;
        case Direction::Down:
            i++; break;
        case Direction::Left:
            j--; break;
        case Direction::Right:
            j++; break;
        default:
            qDebug() << "Ivalid path pattern";
            exit(EXIT_FAILURE);
        }
    }
    QPointF nextPoint = mMap[i][j]->mapToScene(mMap[i][j]->getCenter());
    mPath.push_back(new QPointF(nextPoint.x(), nextPoint.y()));
}

Map::Direction Map::nextDirection(int i, int j, Map::Direction curr) const
{
    if((mMap[i][j + 1]->getTileType() == TileType::End ||
            mMap[i][j + 1]->getTileType() == TileType::Road) &&
                curr != Direction::Left) {
        return Direction::Right;
    } else if((mMap[i][j - 1]->getTileType() == TileType::End ||
                    mMap[i][j - 1]->getTileType() == TileType::Road) &&
                        curr != Direction::Right) {
        return Direction::Left;
    } else if((mMap[i + 1][j]->getTileType() == TileType::End ||
                    mMap[i + 1][j]->getTileType() == TileType::Road) &&
                        curr != Direction::Up) {
        return Direction::Down;
    } else if((mMap[i - 1][j]->getTileType() == TileType::End ||
                    mMap[i - 1][j]->getTileType() == TileType::Road) &&
                        curr != Direction::Down) {
        return Direction::Up;
    }
    return Direction::None;
}


int Map::getCols() const
{
    return mCols;
}

int Map::getRows() const
{
    return mRows;
}

Tile *Map::getEnd() const
{
    return mEnd;
}

Tile *Map::getStart() const
{
    return mStart;
}

QVector<QVector<Tile *> > Map::getMap() const
{
    return mMap;
}

QVector<Tile *> Map::getTowers() const
{
    return mTowers;
}

QVector<QPointF *> Map::getPath() const
{
    return mPath;
}
