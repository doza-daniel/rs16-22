#include "levelreader.h"

#include <iostream>
#include <QVector>
#include <QFile>
#include <cstdlib>
#include <QDebug>

LevelReader::LevelReader(const QString &path)
    : mXml(),
      loadedLevels()
{
    load(path);
}

QVector<Level *> LevelReader::getLoadedLevels() const
{
    return loadedLevels;
}


void LevelReader::load(const QString &path)
{
    QFile file(path);
    if(!file.open(QFile::ReadOnly | QFile::Text)) {
       qDebug() << "Cannot open file " << path << " for reading!";
       exit(EXIT_FAILURE);
   }
   if(!read(&file)) {
       qDebug() << "Bad xml format!";
       exit(EXIT_FAILURE);
   }
}

bool LevelReader::read(QIODevice *device)
{
    mXml.setDevice(device);
    if(mXml.readNextStartElement()) {
        if(mXml.name() == "levels")
            readAllLevels();
        else
            mXml.raiseError("Not valid levels.xml struture!");
    }
    return !mXml.error();
}

void LevelReader::readAllLevels()
{
    Q_ASSERT(mXml.isStartElement() && mXml.name() == "levels");

    while(mXml.readNextStartElement()) {
        if(mXml.name() == "level")
            readLevel();
        else
            mXml.skipCurrentElement();
    }
}

void LevelReader::readLevel()
{
    Q_ASSERT(mXml.isStartElement() && mXml.name() == "level");
    Level *currLevel = new Level();

    bool ok;
    int num = mXml.attributes().value("num").toInt(&ok);
    if(!ok) {
        qDebug() << "Invalid value for level number!";
        exit(EXIT_FAILURE);
    }
    currLevel->setNumber(num);

    while(mXml.readNextStartElement()) {
        if(mXml.name() == "level")
            readLevel();
        else if(mXml.name() == "map")
            readMap(currLevel);
        else if(mXml.name() == "gold")
            readGold(currLevel);
        else if(mXml.name() == "waves")
            readWaves(currLevel);
        else if(mXml.name() == "enemyHP")
            readEnemyHP(currLevel);
        else if(mXml.name() == "wavespawntime")
            readWaveSpawnTime(currLevel);
        else
            mXml.skipCurrentElement();
    }

    loadedLevels.push_back(currLevel);
}

void LevelReader::readGold(Level *currLevel)
{
    Q_ASSERT(mXml.isStartElement() && mXml.name() == "gold");

    QString tmp(mXml.readElementText().trimmed());

    bool ok;
    int g = tmp.toInt(&ok);

    if(!ok) {
        qDebug() << "Ivalid value for gold!";
        exit(EXIT_FAILURE);
    }

    currLevel->setGold(g);
}

void LevelReader::readWaves(Level *currLevel)
{
    Q_ASSERT(mXml.isStartElement() && mXml.name() == "waves");

    QString tmp(mXml.readElementText().trimmed());

    bool ok;
    int w = tmp.toInt(&ok);

    if(!ok) {
        qDebug() << "Ivalid value for waves!";
        exit(EXIT_FAILURE);
    }

    currLevel->setWaves(w);

}

void LevelReader::readEnemyHP(Level *currLevel)
{
    Q_ASSERT(mXml.isStartElement() && mXml.name() == "enemyHP");

    QString tmp(mXml.readElementText().trimmed());

    bool ok;
    int hp = tmp.toInt(&ok);

    if(!ok) {
        qDebug() << "Ivalid value for enemyHP!";
        exit(EXIT_FAILURE);
    }

    currLevel->setWaves(hp);
}

void LevelReader::readMap(Level *currLevel)
{
    Q_ASSERT(mXml.isStartElement() && mXml.name() == "map");

    bool colsOk, rowsOk;
    int cols = mXml.attributes().value("width").toInt(&colsOk);
    int rows = mXml.attributes().value("height").toInt(&rowsOk);

    if(!rowsOk || !colsOk) {
        qDebug() << "Invalid height or width values for map!";
        exit(EXIT_FAILURE);
    }
    QString str = mXml.readElementText();
    auto lines = str.split('\n');

    Map *m = new Map(rows, cols, lines);
    currLevel->setMap(m);
}

void LevelReader::readWaveSpawnTime(Level *currLevel)
{
    Q_ASSERT(mXml.isStartElement() && mXml.name() == "wavespawntime");

    QString tmp(mXml.readElementText().trimmed());

    bool ok;
    int spawntime = tmp.toInt(&ok);

    if(!ok) {
        qDebug() << "Ivalid value for wavespawntime!";
        exit(EXIT_FAILURE);
    }

    currLevel->setWaveSpawnTime(spawntime);
}




