#ifndef DIALOG_H
#define DIALOG_H

#include "Logic/game.h"
#include <QDialog>


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
    void back();
private:
    Ui::Dialog *ui;
    Game *mGame;
    bool mGameStarted;
    int mLevelNum;
};

#endif // DIALOG_H
