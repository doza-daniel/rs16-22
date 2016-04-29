#include "tower.h"
#include <QVector>
#include <QPointF>
#include <QPolygonF>
#include <QGraphicsPolygonItem>
#include <QLineF>

Tower::Tower(int x,int y):TowerTile(TILE_DIM,x,y)
{
    mAttackArea =  createPolygon();

    centerPolygon();
}
/*Paints the tower tile according to this function*/
void Tower::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)
{
    QColor grass(51, 204, 51);
    QColor tower(255, 255, 0);

    painter->setBrush(grass);
    painter->setPen(Qt::NoPen);

    painter->drawRect(mTile);

    painter->setBrush(tower);
    painter->drawEllipse(mCenter, TILE_DIM - 35, TILE_DIM - 35);
}

/*Poitns for attack area (1,0) (2,0) (3,1) (3,2) (1,3) (0,2) (0,1)*/
/*Points are used in order to create a polygon that represents the tower range*/
QGraphicsPolygonItem* Tower::createPolygon(){

    QVector<QPointF> polyPts;
    polyPts << QPoint(1,0)<< QPoint(2,0)<< QPoint(3,1)<< QPoint(3,2)<< QPoint(2,3)<< QPoint(1,3)
            << QPoint(0,2)<< QPoint(0,1);

    //sacale to tile
    for(auto &p:polyPts){
        p = p*TILE_DIM;
    }

    //create scaled polygon
    QPolygonF polygon(polyPts);

    //this <- represents the parent so that polygon knows where to draw itself
    return new QGraphicsPolygonItem(polygon,this);
}

/*1.5 is the center of previously defined polygon*/
void Tower::centerPolygon(){
    QPointF polyCenter(1.5,1.5);

    //scale the center point to fit the tile
    polyCenter *= TILE_DIM;

    //get the coordinates to be determined by the scene
    polyCenter = mapToScene(polyCenter);

    //create a line on which to move
    QLineF movingLine(polyCenter,mCenter);

    //finally set the attackArea coordinates accordingly
    mAttackArea->setPos(x()+movingLine.dx(),y()+movingLine.dy());
}
