#ifndef GLOBAL_H
#define GLOBAL_H
#include<vector>
#include<random>
#include<queue>
#include <QVector3D>
#include <QMatrix4x4>
#include <QGraphicsScene>
#include <QMainWindow>
#include <QObject>
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
#include <QtMath>

static int N = 4;
static int squaresize = 50;

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
           Point2(N*squaresize+squaresize/5,0),
           Point2(2*N*squaresize+squaresize*2/5,0),
           Point2(3*N*squaresize+squaresize*3/5,0),
           Point2(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
           Point2(3*N*squaresize+squaresize*3/5,-N*squaresize-squaresize/5)
           },
            //2
           {Point2(0, 0),
           Point2(N*squaresize+squaresize/5,0),
           Point2(2*N*squaresize+squaresize*2/5,0),
           Point2(3*N*squaresize+squaresize*3/5,0),
           Point2(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
           Point2(2*N*squaresize+squaresize*2/5,-N*squaresize-squaresize/5)
           },
            //3
           {Point2(0, 0),
           Point2(N*squaresize+squaresize/5,0),
           Point2(2*N*squaresize+squaresize*2/5,0),
           Point2(3*N*squaresize+squaresize*3/5,0),
           Point2(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
           Point2(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)
           },
            //4
           {Point2(0, 0),
           Point2(N*squaresize+squaresize/5,0),
           Point2(2*N*squaresize+squaresize*2/5,0),
           Point2(3*N*squaresize+squaresize*3/5,0),
           Point2(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
           Point2(0,-N*squaresize-squaresize/5)
           },
            //5
           {Point2(0, 0),
           Point2(N*squaresize+squaresize/5,0),
           Point2(2*N*squaresize+squaresize*2/5,0),
           Point2(3*N*squaresize+squaresize*3/5,0),
           Point2(2*N*squaresize+squaresize*2/5,N*squaresize+squaresize/5),
           Point2(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)
           },
            //6
           {Point2(0, 0),
           Point2(N*squaresize+squaresize/5,0),
           Point2(2*N*squaresize+squaresize*2/5,0),
           Point2(3*N*squaresize+squaresize*3/5,0),
           Point2(1*N*squaresize+squaresize*1/5,N*squaresize+squaresize/5),
           Point2(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)
           },
            //7
           {Point2(N*squaresize+squaresize/5,0),
           Point2(2*N*squaresize+squaresize*2/5,0),
           Point2(3*N*squaresize+squaresize*3/5,0),
           Point2(0,-N*squaresize-squaresize/5),
           Point2(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5),
           Point2(1*N*squaresize+squaresize*1/5,+N*squaresize+squaresize/5)
           },
            //8
            {Point2(N*squaresize+squaresize/5,0),
            Point2(2*N*squaresize+squaresize*2/5,0),
            Point2(3*N*squaresize+squaresize*3/5,0),
            Point2(0,-N*squaresize-squaresize/5),
            Point2(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5),
            Point2(2*N*squaresize+squaresize*2/5,+N*squaresize+squaresize/5)
            },
            //9
            {Point2(N*squaresize+squaresize/5,0),
            Point2(2*N*squaresize+squaresize*2/5,0),
            Point2(3*N*squaresize+squaresize*3/5,0),
            Point2(0,-N*squaresize-squaresize/5),
            Point2(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5),
            Point2(3*N*squaresize+squaresize*3/5,+N*squaresize+squaresize/5)
            },
            //10
           {Point2(0, 0),
           Point2(N*squaresize+squaresize/5,0),
           Point2(2*N*squaresize+squaresize*2/5,0),
           Point2(2*N*squaresize+squaresize*2/5,N*squaresize+squaresize/5),
           Point2(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
           Point2(4*N*squaresize+squaresize*4/5,N*squaresize+squaresize/5)
           },
            //11
           {Point2(N*squaresize+squaresize/5, 0),
           Point2(2*N*squaresize+squaresize*2/5,0),
           Point2(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
           Point2(0,-N*squaresize-squaresize/5),
           Point2(2*N*squaresize+squaresize*2/5,N*squaresize+squaresize/5),
           Point2(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)
           },

        }
        );
//static std::vector<std::vector<ViewPoint>> viewoffsets (
//        {
//            //1
//           {ViewPoint(0, 0,0,0,1,1),
//           ViewPoint(N*squaresize+squaresize/5,0),
//           ViewPoint(2*N*squaresize+squaresize*2/5,0),
//           ViewPoint(3*N*squaresize+squaresize*3/5,0),
//           ViewPoint(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
//           ViewPoint(3*N*squaresize+squaresize*3/5,-N*squaresize-squaresize/5)
//           },
//            //2
//           {ViewPoint(0, 0),
//           ViewPoint(N*squaresize+squaresize/5,0),
//           ViewPoint(2*N*squaresize+squaresize*2/5,0),
//           ViewPoint(3*N*squaresize+squaresize*3/5,0),
//           ViewPoint(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
//           ViewPoint(2*N*squaresize+squaresize*2/5,-N*squaresize-squaresize/5)
//           },
//            //3
//           {ViewPoint(0, 0),
//           ViewPoint(N*squaresize+squaresize/5,0),
//           ViewPoint(2*N*squaresize+squaresize*2/5,0),
//           ViewPoint(3*N*squaresize+squaresize*3/5,0),
//           ViewPoint(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
//           ViewPoint(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)
//           },
//            //4
//           {ViewPoint(0, 0),
//           ViewPoint(N*squaresize+squaresize/5,0),
//           ViewPoint(2*N*squaresize+squaresize*2/5,0),
//           ViewPoint(3*N*squaresize+squaresize*3/5,0),
//           ViewPoint(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
//           ViewPoint(0,-N*squaresize-squaresize/5)
//           },
//            //5
//           {ViewPoint(0, 0),
//           ViewPoint(N*squaresize+squaresize/5,0),
//           ViewPoint(2*N*squaresize+squaresize*2/5,0),
//           ViewPoint(3*N*squaresize+squaresize*3/5,0),
//           ViewPoint(2*N*squaresize+squaresize*2/5,N*squaresize+squaresize/5),
//           ViewPoint(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)
//           },
//            //6
//           {ViewPoint(0, 0),
//           ViewPoint(N*squaresize+squaresize/5,0),
//           ViewPoint(2*N*squaresize+squaresize*2/5,0),
//           ViewPoint(3*N*squaresize+squaresize*3/5,0),
//           ViewPoint(1*N*squaresize+squaresize*1/5,N*squaresize+squaresize/5),
//           ViewPoint(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)
//           },
//            //7
//           {ViewPoint(N*squaresize+squaresize/5,0),
//           ViewPoint(2*N*squaresize+squaresize*2/5,0),
//           ViewPoint(3*N*squaresize+squaresize*3/5,0),
//           ViewPoint(0,-N*squaresize-squaresize/5),
//           ViewPoint(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5),
//           ViewPoint(1*N*squaresize+squaresize*1/5,+N*squaresize+squaresize/5)
//           },
//            //8
//            {ViewPoint(N*squaresize+squaresize/5,0),
//            ViewPoint(2*N*squaresize+squaresize*2/5,0),
//            ViewPoint(3*N*squaresize+squaresize*3/5,0),
//            ViewPoint(0,-N*squaresize-squaresize/5),
//            ViewPoint(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5),
//            ViewPoint(2*N*squaresize+squaresize*2/5,+N*squaresize+squaresize/5)
//            },
//            //9
//            {ViewPoint(N*squaresize+squaresize/5,0),
//            ViewPoint(2*N*squaresize+squaresize*2/5,0),
//            ViewPoint(3*N*squaresize+squaresize*3/5,0),
//            ViewPoint(0,-N*squaresize-squaresize/5),
//            ViewPoint(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5),
//            ViewPoint(3*N*squaresize+squaresize*3/5,+N*squaresize+squaresize/5)
//            },
//            //10
//           {ViewPoint(0, 0),
//           ViewPoint(N*squaresize+squaresize/5,0),
//           ViewPoint(2*N*squaresize+squaresize*2/5,0),
//           ViewPoint(2*N*squaresize+squaresize*2/5,N*squaresize+squaresize/5),
//           ViewPoint(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
//           ViewPoint(4*N*squaresize+squaresize*4/5,N*squaresize+squaresize/5)
//           },
//            //11
//           {ViewPoint(N*squaresize+squaresize/5, 0),
//           ViewPoint(2*N*squaresize+squaresize*2/5,0),
//           ViewPoint(3*N*squaresize+squaresize*3/5,N*squaresize+squaresize/5),
//           ViewPoint(0,-N*squaresize-squaresize/5),
//           ViewPoint(2*N*squaresize+squaresize*2/5,N*squaresize+squaresize/5),
//           ViewPoint(1*N*squaresize+squaresize*1/5,-N*squaresize-squaresize/5)
//           },

//        }
//        );


#endif // GLOBAL_H
