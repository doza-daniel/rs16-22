#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    mGame(nullptr),
    mGameStarted(false),
    mLevelNum(1)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::startGame()
{
    if(mGameStarted)
        return;
    mGame = new Game(0, 0, 1000, 800, mLevelNum);
    mGameStarted = true;
    mGame->show();
}

void Dialog::selectLevel()
{
    if(ui->rb1->isChecked())
        mLevelNum = 1;
    else if(ui->rb2->isChecked())
        mLevelNum = 2;
    else
        mLevelNum = 3;
}
