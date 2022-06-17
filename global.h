#ifndef GLOBAL_H
#define GLOBAL_H
#include<vector>
#include<random>
#include<queue>
#include <QVector3D>
#include <QMatrix4x4>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include<QPushButton>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QGridLayout>
#include<QSpinBox>
#include<QGraphicsPixmapItem>
#include <QPixmap>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QStyleOptionGraphicsItem>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>
#include <QKeyEvent>
#include <QTime>
#include <QPointF>
#include <cmath>
#include<QFrame>
#include <QtMath>

static int N = 4;
static int squaresize = 40;

struct Point3{
    int x=0;
    int y=0;
    int z=0;
    Point3(int a,int b,int c)
        :x(a),y(b),z(c){}
};

struct Point2{
    int x=0;
    int y=0;
    Point2(int a, int b)
        :x(a),y(b){}
};

struct ViewPoint{
    Point2 point;
    int x_offset=0;
    int y_offset=0;
    int x_dir=1;
    int y_dir=1;
    ViewPoint(int xx, int yy,int a, int b, int c, int d)
        :point(xx,yy),x_offset(a),y_offset(b),x_dir(c),y_dir(d){}
};

static std::vector<std::vector<Point2>> offsets (
        {
            //1
           {Point2(0, 0),
           Point2(N*squaresize,0),
           Point2(2*N*squaresize,0),
           Point2(3*N*squaresize,0),
           Point2(0,N*squaresize),
           Point2(0,-N*squaresize)
           },
            //2
           {Point2(0, 0),
           Point2(N*squaresize,0),
           Point2(2*N*squaresize,0),
           Point2(3*N*squaresize,0),
           Point2(1*N*squaresize,N*squaresize),
           Point2(0,-N*squaresize)
           },
            //3
           {Point2(0, 0),
           Point2(N*squaresize,0),
           Point2(2*N*squaresize,0),
           Point2(3*N*squaresize,0),
           Point2(2*N*squaresize,N*squaresize),
           Point2(0,-N*squaresize)
           },
            //4
           {Point2(0, 0),
           Point2(N*squaresize,0),
           Point2(2*N*squaresize,0),
           Point2(3*N*squaresize,0),
           Point2(3*N*squaresize,N*squaresize),
           Point2(0,-N*squaresize)
           },
            //5
           {Point2(0, 0),
           Point2(N*squaresize,0),
           Point2(2*N*squaresize,0),
           Point2(3*N*squaresize,0),
           Point2(2*N*squaresize,N*squaresize),
           Point2(1*N*squaresize,-N*squaresize)
           },
            //6
           {Point2(0, 0),
           Point2(N*squaresize,0),
           Point2(2*N*squaresize,0),
           Point2(3*N*squaresize,0),
           Point2(1*N*squaresize,N*squaresize),
           Point2(1*N*squaresize,-N*squaresize)
           },
            //7
           {Point2(N*squaresize,0),
           Point2(2*N*squaresize,0),
           Point2(3*N*squaresize,0),
           Point2(0,-N*squaresize),
           Point2(1*N*squaresize,+N*squaresize),
           Point2(1*N*squaresize,-N*squaresize)

           },
            //8
            {Point2(N*squaresize,0),
            Point2(2*N*squaresize,0),
            Point2(3*N*squaresize,0),
            Point2(0,-N*squaresize),
            Point2(2*N*squaresize,+N*squaresize),
            Point2(1*N*squaresize,-N*squaresize)
            },
            //9
            {Point2(N*squaresize,0),
            Point2(2*N*squaresize,0),
            Point2(3*N*squaresize,0),
            Point2(0,-N*squaresize),
            Point2(3*N*squaresize,+N*squaresize),
            Point2(1*N*squaresize,-N*squaresize)

            },
            //10
           {Point2(0, 0),
           Point2(N*squaresize,0),
           Point2(2*N*squaresize,0),
           Point2(3*N*squaresize,N*squaresize),
           Point2(2*N*squaresize,N*squaresize),
           Point2(4*N*squaresize,N*squaresize)
           },
            //11
           {Point2(N*squaresize, 0),
           Point2(2*N*squaresize,0),
           Point2(3*N*squaresize,N*squaresize),
           Point2(0,-N*squaresize),
           Point2(2*N*squaresize,N*squaresize),
           Point2(1*N*squaresize,-N*squaresize)
           },

        }
        );
//带空offsets
//static std::vector<std::vector<Point2>> offsets (
//        {
//            //1
//           {Point2(0, 0),
//           Point2(N*squaresize+squaresize/5,0),
//           Point2(2*N*squaresize+squaresize*2/5,0),
//           Point2(3*N*squaresize+squaresize*3/5,0),
//           Point2(0,N*squaresize+squaresize/5),
//           Point2(0,-N*squaresize-squaresize/5)
//           },
//            //2
//           {Point2(0, 0),
//           Point2(N*squaresize+squaresize/5,0),
//           Point2(2*N*squaresize+squaresize*2/5,0),
//           Point2(3*N*squaresize+squaresize*3/5,0),
//           Point2(1*N*squaresize+squaresize*1/5,N*squaresize+squaresize/5),
//           Point2(0,-N*squaresize-squaresize/5)
//           },
//            //3
//           {Point2(0, 0),
//           Point2(N*squaresize+squaresize/5,0),
//           Point2(2*N*squaresize+squaresize*2/5,0),
//           Point2(3*N*squaresize+squaresize*3/5,0),
//           Point2(2*N*squaresize+squaresize*2/5,N*squaresize+squaresize/5),
//           Point2(0,-N*squaresize-squaresize/5)
//           },
//            //4
//           {Point2(0, 0),
//           Point2(N*squaresize+squaresize/5,0),
//           Point2(2*N*squaresize+squaresize*2/5,0),
//           Point2(3*N*squaresize+squaresize*3/5,0),
//           Point2(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
//           Point2(0,-N*squaresize-squaresize/5)
//           },
//            //5
//           {Point2(0, 0),
//           Point2(N*squaresize+squaresize/5,0),
//           Point2(2*N*squaresize+squaresize*2/5,0),
//           Point2(3*N*squaresize+squaresize*3/5,0),
//           Point2(2*N*squaresize+squaresize*2/5,N*squaresize+squaresize/5),
//           Point2(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)
//           },
//            //6
//           {Point2(0, 0),
//           Point2(N*squaresize+squaresize/5,0),
//           Point2(2*N*squaresize+squaresize*2/5,0),
//           Point2(3*N*squaresize+squaresize*3/5,0),
//           Point2(1*N*squaresize+squaresize*1/5,N*squaresize+squaresize/5),
//           Point2(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)
//           },
//            //7
//           {Point2(N*squaresize+squaresize/5,0),
//           Point2(2*N*squaresize+squaresize*2/5,0),
//           Point2(3*N*squaresize+squaresize*3/5,0),
//           Point2(0,-N*squaresize-squaresize/5),
//           Point2(1*N*squaresize+squaresize*1/5,+N*squaresize+squaresize/5),
//           Point2(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)

//           },
//            //8
//            {Point2(N*squaresize+squaresize/5,0),
//            Point2(2*N*squaresize+squaresize*2/5,0),
//            Point2(3*N*squaresize+squaresize*3/5,0),
//            Point2(0,-N*squaresize-squaresize/5),
//            Point2(2*N*squaresize+squaresize*2/5,+N*squaresize+squaresize/5),
//            Point2(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)
//            },
//            //9
//            {Point2(N*squaresize+squaresize/5,0),
//            Point2(2*N*squaresize+squaresize*2/5,0),
//            Point2(3*N*squaresize+squaresize*3/5,0),
//            Point2(0,-N*squaresize-squaresize/5),
//            Point2(3*N*squaresize+squaresize*3/5,+N*squaresize+squaresize/5),
//            Point2(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)

//            },
//            //10
//           {Point2(0, 0),
//           Point2(N*squaresize+squaresize/5,0),
//           Point2(2*N*squaresize+squaresize*2/5,0),
//           Point2(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
//           Point2(2*N*squaresize+squaresize*2/5,N*squaresize+squaresize/5),
//           Point2(4*N*squaresize+squaresize*4/5,N*squaresize+squaresize/5)
//           },
//            //11
//           {Point2(N*squaresize+squaresize/5, 0),
//           Point2(2*N*squaresize+squaresize*2/5,0),
//           Point2(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
//           Point2(0,-N*squaresize-squaresize/5),
//           Point2(2*N*squaresize+squaresize*2/5,N*squaresize+squaresize/5),
//           Point2(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)
//           },

//        }
//        );
static void globalreset()
{
    offsets=
    {
        //1
        //1
       {Point2(0, 0),
       Point2(N*squaresize,0),
       Point2(2*N*squaresize,0),
       Point2(3*N*squaresize,0),
       Point2(0,N*squaresize),
       Point2(0,-N*squaresize)
       },
        //2
       {Point2(0, 0),
       Point2(N*squaresize,0),
       Point2(2*N*squaresize,0),
       Point2(3*N*squaresize,0),
       Point2(1*N*squaresize,N*squaresize),
       Point2(0,-N*squaresize)
       },
        //3
       {Point2(0, 0),
       Point2(N*squaresize,0),
       Point2(2*N*squaresize,0),
       Point2(3*N*squaresize,0),
       Point2(2*N*squaresize,N*squaresize),
       Point2(0,-N*squaresize)
       },
        //4
       {Point2(0, 0),
       Point2(N*squaresize,0),
       Point2(2*N*squaresize,0),
       Point2(3*N*squaresize,0),
       Point2(3*N*squaresize,N*squaresize),
       Point2(0,-N*squaresize)
       },
        //5
       {Point2(0, 0),
       Point2(N*squaresize,0),
       Point2(2*N*squaresize,0),
       Point2(3*N*squaresize,0),
       Point2(2*N*squaresize,N*squaresize),
       Point2(1*N*squaresize,-N*squaresize)
       },
        //6
       {Point2(0, 0),
       Point2(N*squaresize,0),
       Point2(2*N*squaresize,0),
       Point2(3*N*squaresize,0),
       Point2(1*N*squaresize,N*squaresize),
       Point2(1*N*squaresize,-N*squaresize)
       },
        //7
       {Point2(N*squaresize,0),
       Point2(2*N*squaresize,0),
       Point2(3*N*squaresize,0),
       Point2(0,-N*squaresize),
       Point2(1*N*squaresize,+N*squaresize),
       Point2(1*N*squaresize,-N*squaresize)

       },
        //8
        {Point2(N*squaresize,0),
        Point2(2*N*squaresize,0),
        Point2(3*N*squaresize,0),
        Point2(0,-N*squaresize),
        Point2(2*N*squaresize,+N*squaresize),
        Point2(1*N*squaresize,-N*squaresize)
        },
        //9
        {Point2(N*squaresize,0),
        Point2(2*N*squaresize,0),
        Point2(3*N*squaresize,0),
        Point2(0,-N*squaresize),
        Point2(3*N*squaresize,+N*squaresize),
        Point2(1*N*squaresize,-N*squaresize)

        },
        //10
       {Point2(0, 0),
       Point2(N*squaresize,0),
       Point2(2*N*squaresize,0),
       Point2(3*N*squaresize,N*squaresize),
       Point2(2*N*squaresize,N*squaresize),
       Point2(4*N*squaresize,N*squaresize)
       },
        //11
       {Point2(N*squaresize, 0),
       Point2(2*N*squaresize,0),
       Point2(3*N*squaresize,N*squaresize),
       Point2(0,-N*squaresize),
       Point2(2*N*squaresize,N*squaresize),
       Point2(1*N*squaresize,-N*squaresize)
       },

    };

}

static std::vector<std::vector<int>>RightRotate(std::vector<std::vector<int>>vec)
{
    std::vector<std::vector<int>>tempvec;
    tempvec.resize(vec.size());
    for(auto& e:tempvec) e.resize(vec[0].size());
    int k = vec.size();
    int p = vec[0].size();
    for(int i=0;i<k;i++)
    {
        for(int j=0; j<p; j++)
        {
            tempvec[i][j]=vec[k-1-j][i];
        }
    }
    return tempvec;
}
static std::vector<std::vector<int>>LeftRotate(std::vector<std::vector<int>>vec)
{
    std::vector<std::vector<int>>tempvec;
    tempvec.resize(vec.size());
    for(auto& e:tempvec) e.resize(vec[0].size());
    int k = vec.size();
    int p = vec[0].size();
    for(int i=0;i<k;i++)
    {
        for(int j=0; j<p; j++)
        {
            tempvec[k-1-j][i]=vec[i][j];
        }
    }
    return tempvec;
}


static std::vector<std::vector<int>>UpsideReverse(std::vector<std::vector<int>>vec)
{
    std::vector<std::vector<int>>tempvec;
    tempvec.resize(vec.size());
    for(auto& e:tempvec) e.resize(vec[0].size());
    int k = vec.size();
    int p = vec[0].size();
    for(int i=0;i<k;i++)
    {
        for(int j=0; j<p; j++)
        {
            tempvec[i][j]=vec[i][p-1-j];
        }
    }
    return tempvec;
}



static std::vector<std::vector<int>>LeftsideReverse(std::vector<std::vector<int>>vec)
{
    std::vector<std::vector<int>>tempvec;
    tempvec.resize(vec.size());
    for(auto& e:tempvec) e.resize(vec[0].size());
    int k = vec.size();
    int p = vec[0].size();
    for(int i=0;i<k;i++)
    {
        for(int j=0; j<p; j++)
        {
            tempvec[k-1-i][j]=vec[i][j];
        }
    }
    return tempvec;
}

#endif // GLOBAL_H
