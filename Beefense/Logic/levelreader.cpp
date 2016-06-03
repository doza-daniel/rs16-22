#include "levelreader.h"

#include <iostream>
#include <QVector>
#include <QFile>
#include <cstdlib>
#include <QDebug>

LevelReader::LevelReader() {}


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
            mXml.raiseError("blah");
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

    std::cout << mXml.name().toString().toStdString() <<
                 " " << mXml.attributes().value("num").toString().toStdString() <<
                 std::endl;
    while(mXml.readNextStartElement()) {
        if(mXml.name() == "level")
            readLevel();
        else if(mXml.name() == "map")
            readMap();
        else if(mXml.name() == "gold")
            readGold();
        else if(mXml.name() == "waves")
            readWaves();
        else if(mXml.name() == "enemyHP")
            readEnemyHP();
        else
            mXml.skipCurrentElement();
    }
}

void LevelReader::readGold()
{
    Q_ASSERT(mXml.isStartElement() && mXml.name() == "gold");
    std::cout << "Gold: " <<
                 mXml.readElementText().toStdString() << std::endl;
}

void LevelReader::readWaves()
{
    Q_ASSERT(mXml.isStartElement() && mXml.name() == "waves");
    std::cout << "Number of waves: " <<
                 mXml.readElementText().toStdString() << std::endl;
}

void LevelReader::readEnemyHP()
{
    Q_ASSERT(mXml.isStartElement() && mXml.name() == "enemyHP");
    std::cout << "Enemy health: " <<
                 mXml.readElementText().toStdString() << std::endl;
}

void LevelReader::readMap()
{
    Q_ASSERT(mXml.isStartElement() && mXml.name() == "map");
    std::cout << mXml.name().toString().toStdString() <<
                 " width = " <<
                 mXml.attributes().value("width").toString().toStdString() <<
                " height = " <<
                 mXml.attributes().value("height").toString().toStdString() <<
                 ": " << std::endl;
    QString str = mXml.readElementText();
    auto lines = str.split('\n');


    for(QString line : lines) {
        if(line.size() != 0)
            std::cout << line.trimmed().toStdString() << std::endl;
    }
}




