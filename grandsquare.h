#ifndef GRANDSQUARE_H
#define GRANDSQUARE_H

#include"global.h"
#include"cube.h"
#include"figuremate.h"

QVector<QVector<int>> bfssquare(int n, int k);
class GrandSquare : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit GrandSquare(QObject *parent = nullptr);
    void Updatesquare();
    void Initialize();




private:
    int width;
    int height;
    QVector<QVector<QVector<QVector<FigureMate*>>>> Mmates;
    QVector<QVector<int>>StatesofMmates;//0表示未被选中干扰项，1表示是展开图的一部分且未被选中，2表示已选中的干扰项，3表示已选中的展开图，4表示已被确定的答案展开图
    QVector<Cube*> cubelist;
    int count;
    int cubenum;
private slots:
    void select(int x,int y);
signals:
    void win();
};



#endif // GRANDSQUARE_H
