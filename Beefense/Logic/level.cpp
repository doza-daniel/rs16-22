#include "level.h"
#include "levelreader.h"

Level::Level()
    : mMap(0),
      mGold(0),
      mWaves(0)
{
}

QVector<Level *> Level::getLevels(const QString &path)
{
    LevelReader r(path);
    return r.getLoadedLevels();
}

Level &Level::operator =(const Level &other)
{
    mMap = other.getMap();
    mGold = other.getGold();
    mWaves = other.getWaves();
    mNumber = other.getNumber();
    mWaveSpawnTime = other.getWaveSpawnTime();
    return *this;
}

Map* Level::getMap() const
{
    return mMap;
}

void Level::setMap(Map *m)
{
    mMap = m;
}

int Level::getNumber() const
{
    return mNumber;
}

void Level::setNumber(int num)
{
    mNumber = num;
}

int Level::getGold() const
{
   return mGold;
}

void Level::setGold(int gold)
{
   mGold = gold;
}

int Level::getWaves() const
{
   return mWaves;
}

void Level::setWaves(int waves)
{
    mWaves = waves;
}

int Level::getWaveSpawnTime() const
{
    return mWaveSpawnTime;
}

void Level::setWaveSpawnTime(int spawntime)
{
    mWaveSpawnTime = spawntime;
}
