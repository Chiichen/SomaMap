#ifndef SQUARE_H
#define SQUARE_H

#include"global.h"
#include"figuremate.h"
#include"cube.h"
class Square : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Square(QObject *parent = nullptr);
    ~Square();
    void UpdateSquare();
    void SetLength(int l){length = l;}
    void SetCubevec(QVector<QVector<int>> vec){Cubevec = vec;}
    void initialize();
    void SetCube(Cube c){cube = c;}
    void DisplayExpand();
    void DisplayThreeviews();
    void SetViewchoice(int k){viewchoice = k;}
    Cube OutputCube();
private:
    QVector<QVector<int>> Cubevec;
    int length=0;
    bool state = true;
    int viewchoice = 0;
    Cube cube;
    QVector<QVector<Point2>> offset;
    QVector<QVector<QVector<FigureMate*>>> Mmates;//六向视图
    QVector<QVector<QVector<FigureMate*>>> three_views;//可操作三视图
    Cube outputcube;

signals:
};




#endif // SQUARE_H
