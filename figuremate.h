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
    void SetState(bool n){state = n;}//true为实心，false为空心
    bool GetState(){return state;}
protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
private:
    int x;
    int y;
    bool Editable = true;
    int state = 0;
};



#endif // FIGUREMATE_H
