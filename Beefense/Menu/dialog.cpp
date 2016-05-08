#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"

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
    this->close();
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

void Dialog::back()
{
    MainWindow *w = new MainWindow();
    w->show();
    this->close();
}
