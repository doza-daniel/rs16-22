#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include "game.h"

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private slots:
    void startGame();
    void selectLevel();

private:
    Ui::Dialog *ui;
    Game *mGame;
    bool mGameStarted;
    int mLevelNum;
};

#endif // DIALOG_H
