#include "square.h"

Square::~Square()
{

}
Square::Square(QObject *parent)
    :QGraphicsScene(parent)
{
    length = N;
    mates.resize(length);
    for(auto &e:mates)
    {
        e.resize(length);
    }
    initialize();
}

void Square::initialize()
{
    this->clear();
    length = N;
    mates.clear();
    mates.resize(length);
    for(auto &e:mates)
    {
        e.resize(length);
    }
    for(int x=0;x<N;x++)
    {
        for(int y = 0; y<N; y++)
        {
            this->mates[x][y] = new FigureMate();
            this->mates[x][y]->setPos(QPointF(200+x*50,y*50));
            this->mates[x][y]->setRowAndCol(x,y);
            this->addItem(this->mates[x][y]);
        }
    }
}

void Square::UpdateSquare()
{

    for(auto &e:mates)
    {
        for(auto &h:e)
        {
            h->updateMate();
        }
    }
}

void Square::SetUnEditableSquare()

{
    length = N;
    initialize();
    for(int x=0;x<length;x++)
    {
        for(int y=0;y<length;y++)
        {
            this->mates[x][y]->SetEditable(false);
            this->mates[x][y]->SetState(cube.GetFront()[x][length-y-1]);
        }
    }
    UpdateSquare();

}

