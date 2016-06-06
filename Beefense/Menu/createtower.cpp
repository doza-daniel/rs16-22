#include "createtower.h"
#include "ui_createtower.h"
#include "../Tiles/Towers/attackarea.h"
#include "../Tiles/Towers/greaterattacktower.h"
#include "../Tiles/Towers/greaterrangetower.h"
#include "../Tiles/Towers/slowtower.h"

CreateTower::CreateTower(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::CreateTower)
{
    ui->setupUi(this);
    ui->label->setVisible(false);
}

void CreateTower::setParameters(QPointF point, Game *game,TowerTile *pasive)
{
    mGame = game;
    mPos = point;
    mTilePlace = pasive;
}

CreateTower::~CreateTower()
{
    delete ui;
}
//TODO: HARDCODED 35 AS GOLD PRICE
void CreateTower::buy()
{
    int type = ui->createList->currentRow();
    TowerActive *twr = nullptr;
    switch(type){
        case 3:
        if(mGame->getGold() >= SlowTower::getCost())
            twr = new SlowTower(mPos.x(),mPos.y(),mGame);
        break;
        case 2:
        if(mGame->getGold() >= TowerActive::getCost())
            twr = new TowerActive(mPos.x(),mPos.y(),mGame);
        break;
        case 1:
        if(mGame->getGold() >= GreaterRangeTower::getCost())
             twr = new GreaterRangeTower(mPos.x(), mPos.y(), mGame);
        break;
        case 0:
            if(mGame->getGold() >= GreaterAttackTower::getCost())
                 twr = new GreaterAttackTower(mPos.x(), mPos.y(), mGame);
        break;

    }
    if(twr){
        mGame->setGold(mGame->getGold()-twr->getCost());
        mGame->addItem(twr);
        delete mTilePlace;
        ui->cancelButton->click();
    }
    else
       ui->label->setVisible(true);

}

void CreateTower::cancel()
{
    this->close();
}
