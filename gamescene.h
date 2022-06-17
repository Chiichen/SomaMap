#ifndef GAMESCENE_H
#define GAMESCENE_H

#include"global.h"
#include"square.h"
#include"cube.h"


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
private:
    Ui::GameScene *ui;
    QTimer* timer1s;
    int remaintime;
};

#endif // GAMESCENE_H
