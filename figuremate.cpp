#include "figuremate.h"

FigureMate::FigureMate()
{
    this->setFlag(QGraphicsItem::ItemIsSelectable);
    this->setAcceptedMouseButtons(Qt::AllButtons);

    updateMate();
}



void FigureMate::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)

/*painter : 此参数用于绘图;
option : 提供了item的风格，比如item的状态，曝光度以及详细的信息；
widget : 想画到哪个widget上，如果要画在缓存区上，这个参数一般填0；
*/

{
    QStyleOptionGraphicsItem op;
    op.initFrom(widget);
    op.state = QStyle::State_None;

    return QGraphicsPixmapItem::paint(painter, &op, widget);
}

void FigureMate::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit clicked(x,y);
    if(Editable)
    {
        if(event->button()==Qt::LeftButton)
        {
            state = !state;
            qDebug()<<x<<"\n"<<y;
            updateMate();
        }

    }
}

void FigureMate::updateMate()
{
if(this!=nullptr)
{
    if(state==1)
    {
        this->setPixmap(QPixmap(":/pic/BlueSolidCube.bmp").scaled(squaresize,squaresize,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    }
    else if(state==3)
    {
        this->setPixmap(QPixmap(":/pic/OringeSolidCube.bmp").scaled(squaresize,squaresize,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    }
    else if(state==0)
    {
        this->setPixmap(QPixmap(":/pic/BlackCube.bmp").scaled(squaresize,squaresize,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    }
    else if(state==4)
    {
        this->setPixmap(QPixmap(":/pic/GreenSolidCube.bmp").scaled(squaresize,squaresize,Qt::IgnoreAspectRatio, Qt::SmoothTransformation));
    }
}
}

