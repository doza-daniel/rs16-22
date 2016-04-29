#include "game.h"
#include <QTimer>
#include <QPainter>
#include <iostream>


Game::Game(const QRectF &sceneRect, QObject *parent)
    : QGraphicsScene(sceneRect, parent),
      mView(this),
      mMap(this->height() / TILE_DIM, this->width() / TILE_DIM)
{
    initView();
    showMap();
}

Game::Game(qreal x, qreal y, qreal width, qreal height, QObject *parent)
    : QGraphicsScene(x, y, width, height, parent),
      mView(this),
      mMap(this->height() / TILE_DIM, this->width() / TILE_DIM)
{
    initView();
    showMap();

    Enemy *e = new Enemy(mMap.getStart()->x(), mMap.getStart()->y(), mMap.getPath());
    addItem(e);

    QTimer *t = new QTimer();
    QObject::connect(t, SIGNAL(timeout()), this, SLOT(advance()));
    t->start(50);
}

Map Game::getMap() const
{
    return mMap;
}

void Game::showMap()
{
    QVector< QVector<Tile *> > m = mMap.getMap();
    for(int i = 0; i < m.size(); ++i) {
        for(int j = 0; j < m[i].size(); ++j) {
            addItem(m[i][j]);
        }
    }
}

void Game::show()
{
    mView.show();
}

void Game::initView()
{
    // mView.setRenderHint(QPainter::Antialiasing);
    mView.setFixedHeight(this->height());
    mView.setFixedWidth(this->width());
    mView.setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    mView.setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}
