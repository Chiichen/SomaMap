#ifndef FIGUREMATE_H
#define FIGUREMATE_H
#include"global.h"
class FigureMate : public QObject,public QGraphicsPixmapItem
{
     Q_OBJECT
public:
    FigureMate();
    void updateMate();
    void setRowAndCol(int xx,int yy){x=xx;y=yy;}
    void SetEditable(bool m){Editable = m;updateMate();}
    void SetState(int n){state = n;updateMate();}//0为空方块，1为蓝色实心，
    int GetState(){return state;}
    void SetpreState(int k){prestate=k;updateMate();}
    int GetpreState(){return prestate;}
protected:

    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    int x;
    int y;
    bool Editable = true;
    int state = 0;
    int prestate;
signals:
    void clicked(int x,int y);
};



#endif // FIGUREMATE_H
