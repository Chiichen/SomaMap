#ifndef GAMESCENE_H
#define GAMESCENE_H

#include"global.h"
#include"cube.h"
#include"grandsquare.h"

namespace Ui {
class GameScene;
}

class GameScene : public QWidget
{
    Q_OBJECT

public:
    explicit GameScene(QWidget *parent = nullptr);
    ~GameScene();
    void settime(int k) {remaintime=k;}
signals:
    void returnmenu();
    void timeout();
private slots:
    void on_commandLinkButton_clicked();
    void timer1sout();
    void win();

    void on_showans_clicked();

private:
    Ui::GameScene *ui;
    QTimer* timer1s;
    int remaintime;
    GrandSquare* grandsquare;
};

#endif // GAMESCENE_H
