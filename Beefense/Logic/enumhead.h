#ifndef ENUMHEAD_H
#define ENUMHEAD_H


enum class EnemyType
{
    Bee, AngryBee
};

enum class RoadTileType {
    Tunnel, Corner
};

enum class Direction {
    None, Up, Down, Left, Right
};

enum class TileType {
    Grass = 0,
    Road = 1,
    Tower = 2,
    Start = 3,
    End = 4
};
#endif // ENUMHEAD_H
