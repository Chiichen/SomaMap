#include "grandsquare.h"
QVector<QVector<int>> bfssquare(int n, int k)
{
    QVector<QVector<int>> curvec;
    curvec.resize(N);
    int looptime=0;
    for(auto &e:curvec) e.resize(N);
    int move_x[]={0,0,1,-1,0};
    int move_y[]={1,-1,0,0,0};
    Point2 p1(N/2,N/2);
    curvec[N/2][N/2]=1;
    std::queue<Point2> que;
    que.push(p1);
    int count = 0;
    while(!que.empty())
    {
        Point2 p = que.front();
        que.pop();
        for(int i=0; i<5; i++)
        {
            Point2 curp(p.x+move_x[i],p.y+move_y[i]);
            looptime++;
            if(looptime>1000) return curvec;
            if(curp.x>=0&&curp.x<N&&curp.y>=0&&curp.y<N&&curvec[curp.x][curp.y]==0&&random_unint(0,100)<=k&&count<n)
            {
                curvec[curp.x][curp.y] = 1;
                count++;
                que.push(curp);
            }
            else if(count<n-1&&que.empty())
            {
                que.push(curp);
            }
        }
    }
    return curvec;
}

bool bfscheck(QVector<QVector<int>>vec,QVector<QVector<QVector<QVector<FigureMate*>>>>&mates,int x,int y)
{
    QVector<QVector<int>>curvec=vec;
    QVector<QVector<QVector<FigureMate*>>>curmates;
    int count=0;
    int move_x[]={0,0,1,-1,0};
    int move_y[]={1,-1,0,0,0};
    Point2 p1(x,y);
    std::queue<Point2> que;
    que.push(p1);
    while(!que.empty())
    {
        Point2 p = que.front();
        que.pop();
        for(int i=0; i<5; i++)
        {
            Point2 curp(p.x+move_x[i],p.y+move_y[i]);

            if(curp.x>=0&&curp.x<curvec.size()&&curp.y>=0&&curp.y<curvec[0].size()&&curvec[curp.x][curp.y]==3&&count!=6)
            {
                curvec[curp.x][curp.y] = -1;
                count++;
                curmates.push_back(mates[curp.x][curp.y]);
                que.push(curp);
            }
        }
    }
    if(count==6)
    {
        for(auto&e:curmates)
        {
            for(auto&g:e)
            {
                for(auto&h:g)
                {
                    h->SetState(h->GetState()==3?4:h->GetState());
                }
            }
        }
        return true;
    }
    else return false;

}

GrandSquare::GrandSquare(QObject *parent)
    : QGraphicsScene{parent},
      width(10),
      height(10),
      count(0),
      cubenum(6)
{
    Initialize();
}

void GrandSquare::Initialize()
{
    width=10;
    height=10;
    count=0;
    cubenum=6;
    Mmates.resize(width);
    for(auto&e:Mmates)
    {
        e.resize(height);
        for(auto&h:e)
        {
            h.resize(N);
            for(auto&g:h)g.resize(N);
        }
    }
    StatesofMmates.resize(width);
    for(auto &e:StatesofMmates) e.resize(height);
    for(int k=0;k<cubenum;k++)
    {
        cubelist.push_back(new Cube);
    }
    for(int x=0;x<width;x++)
        for(int y=0;y<height;y++)
        {
            StatesofMmates[x][y]=0;
            int minn=N, maxx=N*N/2;
            auto randomvec = bfssquare(random_unint((unsigned int)minn,(unsigned int)maxx),80);
            for(int xx=0;xx<N;xx++)
                for(int yy=0;yy<N;yy++)
                {
                    this->Mmates[x][y][xx][yy] = new FigureMate;
                    this->Mmates[x][y][xx][yy]->SetState(randomvec[xx][yy]);
                    connect(Mmates[x][y][xx][yy],&FigureMate::clicked,this,&GrandSquare::select);
                    this->Mmates[x][y][xx][yy]->setPos(QPointF(x*N*squaresize+xx*squaresize,y*N*squaresize+yy*squaresize));
                    this->Mmates[x][y][xx][yy]->setRowAndCol(x,y);
                    this->Mmates[x][y][xx][yy]->SetEditable(false);
                    this->addItem(this->Mmates[x][y][xx][yy]);
                }
        }
    int curnum=0;
    for(int x=0;x<width/5;x++)
    {
        for(int y=0;y<height/3;y++)
        {
            if(curnum<cubenum&&random_unint(0,1000)<cubenum*1000/(width*height/15))
            {
                int k = random_unint(0,10);
                auto tempvec=cubelist[curnum]->GetExpandView(k);
                for(int i=0;i<6;i++)
                {
                    int xx=x*5+offsets[k][i].x;
                    int yy=y*3+1+offsets[k][i].y;
                    for(int k=0;k<N;k++)
                        for(int j=0;j<N;j++)
                        {
                            StatesofMmates[xx][yy]=1;
                            Mmates[xx][yy][k][j]->SetState(tempvec[i][k][j]);
                        }

                }

            }
        }
    }
}


void GrandSquare::select(int x,int y)
{
    if(StatesofMmates[x][y]!=4)
    {
        for(int xx=0;xx<N;xx++)
            for(int yy=0;yy<N;yy++)
            {
                if(Mmates[x][y][xx][yy]->GetState()==3)
                {
                    Mmates[x][y][xx][yy]->SetState(1);
                }
                else if(Mmates[x][y][xx][yy]->GetState()==1&&count<6)
                {
                    Mmates[x][y][xx][yy]->SetState(3);
                }
            }
        switch (StatesofMmates[x][y])
            {
            case 0:
            {
                if(count<6)
                {
                    count++;
                    StatesofMmates[x][y]=2;
                }
                break;

            }
            case 1:
            {
                if(count<6)
                {
                    count++;
                    StatesofMmates[x][y]=3;
                }
                break;
            }
            case 2:
            {
                count--;
                StatesofMmates[x][y]=0;
                break;
            }
            case 3:
            {
                count--;
                StatesofMmates[x][y]=1;
                break;
            }
        }
     if(bfscheck(StatesofMmates,Mmates,x,y))
     {
         count=0;
         cubenum--;
         emit win();
         if(cubenum==0)
         {
             emit win();
         }
     }

    }

}
