#ifndef GAMESCENE_H
#define GAMESCENE_H
#include"global.h"
#include"cube.h"
#include"figuremate.h"

class GameScene : public QWidget
{
    Q_OBJECT
public:
    explicit GameScene(QWidget *parent = nullptr);
private:

signals:

};

#endif // GAMESCENE_H
