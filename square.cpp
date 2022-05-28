#include "square.h"

Square::~Square()
{

}
Square::Square(QObject *parent)
    :QGraphicsScene(parent),
      offset(offsets)
{
    initialize();
}

void Square::initialize()
{
    this->clear();
    length = N;
    Mmates.clear();
    Mmates.resize(6);
    for(auto& e:Mmates)
    {
        e.resize(length);
        for(auto &h:e)
        {
            h.resize(length);
        }
    }
    three_views.clear();
    three_views.resize(3);
    for(auto& e:three_views)
    {
        e.resize(length);
        for(auto &h:e)
        {
            h.resize(length);
        }
    }
}

void Square::UpdateSquare()
{
    for(auto &q:Mmates)
        for(auto &e:q)
            for(auto &h:e)
               if(h!=nullptr) h->updateMate();

    for(auto &q:three_views)
        for(auto &e:q)
            for(auto &h:e)
               if(h!=nullptr) h->updateMate();
}

void Square::DisplayExpand()

{
    initialize();
    for(size_t k =0;k<6;k++)
        for(int x=0;x<N;x++)
            for(int y = 0; y<N; y++)
            {
                this->Mmates[k][x][y] = new FigureMate();
                this->Mmates[k][x][y]->setPos(QPointF(x*squaresize+offset[viewchoice][k].x,y*squaresize+offset[viewchoice][k].y));
                this->Mmates[k][x][y]->setRowAndCol(x,y);
                this->addItem(this->Mmates[k][x][y]);
            }


    for(size_t k=0;k<6;k++)
        for(int x=0;x<length;x++)
            for(int y=0;y<length;y++)
            {
                this->Mmates[k][x][y]->SetEditable(false);
                this->Mmates[k][x][y]->SetState(cube.GetAllView()[k][x][length-y-1]);
            }

    UpdateSquare();

}

void Square::DisplayThreeviews()

{
    initialize();
    for(size_t k =0;k<3;k++)
        for(int x=0;x<N;x++)
            for(int y = 0; y<N; y++)
            {
                this->three_views[k][x][y] = new FigureMate();
                this->three_views[k][x][y]->setPos(QPointF(x*squaresize+(k==1?N*squaresize:0),y*squaresize+(k==2?N*squaresize:0)));
                this->three_views[k][x][y]->setRowAndCol(x,y);
                this->addItem(this->three_views[k][x][y]);
            }

    for(size_t k=0;k<3;k++)
        for(int x=0;x<length;x++)

            for(int y=0;y<length;y++)
            {
                this->three_views[k][x][y]->SetEditable(true);
            }
    UpdateSquare();
}

Cube Square::OutputCube()
{
//    std::vector<std::vector<int>> front;
//    front.resize(length);
//    for(auto &e:front) e.resize(length);
//    std::vector<std::vector<int>> left;
//    left.resize(length);
//    for(auto &e:left) e.resize(length);
//    std::vector<std::vector<int>> up;
//    up.resize(length);
//    for(auto &e:up) e.resize(length);
    std::vector<std::vector<std::vector<int>>> vec;
    vec.resize(length);
    for(auto &e:vec)
    {
        e.resize(length);
        for(auto &h:e)
        {
            h.resize(length,0);
        }
    }
//    for(size_t x=0;x<length;x++)
//    {
//        for(size_t y=0; y<length; y++)
//        {
//            front[x][y]=three_views[0][x][y]->GetState();
//        }
//    }
//    for(size_t x=0;x<length;x++)
//    {
//        for(size_t y=0; y<length; y++)
//        {
//            left[x][y]=three_views[1][x][y]->GetState();
//        }
//    }
//    for(size_t x=0;x<length;x++)
//    {
//        for(size_t y=0; y<length; y++)
//        {
//            up[x][y]=three_views[2][x][y]->GetState();
//        }
//    }
    for(int z=0;z<length;z++)
        for(int y=0;y<length;y++)
            for(int x=0;x<length;x++)
                vec[x][y][z]+=three_views[0][x][y]->GetState();
    for(int y=0;y<length;y++)
        for(int z=0;z<length;z++)
            for(int x=0;x<length;x++)
                vec[x][y][z]+=three_views[2][x][z]->GetState();
    for(int x=0;x<length;x++)
        for(int y=0;y<length;y++)
            for(int z=0;z<length;z++)
                vec[x][y][z]+=three_views[1][z][y]->GetState();

    for(auto &e:vec)
        for(auto &q:e)
            for(auto &h:q)
                if(h==3) h=1;
                else h=0;
    outputcube.SetCubevec(vec);
    return outputcube;
}

