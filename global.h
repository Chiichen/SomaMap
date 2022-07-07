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
#include<QMessageBox>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QStyleOptionGraphicsItem>
#include <QOpenGLWidget>
#include <QOpenGLShaderProgram>
#include <QOpenGLFunctions>
#include <QOpenGLTexture>
#include <QKeyEvent>
#include <QTime>
#include<QThread>
#include <QPointF>
#include <cmath>
#include<QTimer>
#include<QFrame>
#include <QtMath>
#include<QFile>
#include<QFileDialog>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include<QLabel>
#include<QPropertyAnimation>
#include<algorithm>
#include<QList>
#include<QListWidget>
#include<QDateTime>
extern int N;
extern int squaresize;
extern QString username;
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

struct Difficulty{
    int width;
    int height;
    int cubenum;
    int timelimit;
    int hintnum;
    Difficulty(int a,int b, int c, int d, int e):width(a),height(b),cubenum(c),timelimit(d),hintnum(e){}
};

static const Difficulty dif1(5,5,2,60,1);
static const Difficulty dif2(6,6,2,55,1);
static const Difficulty dif3(6,6,3,50,1);
static const Difficulty dif4(7,7,3,50,1);
static const Difficulty dif5(8,8,3,50,1);
static const Difficulty dif6(9,9,3,50,1);
static const Difficulty dif7(10,10,4,50,2);
static const Difficulty dif8(10,10,5,50,2);
static const Difficulty dif9(10,10,6,50,2);
static const QVector<Difficulty> difvec={dif1,dif2,dif3,dif4,dif5,dif6,dif7,dif8,dif9};

static QVector<QVector<Point2>> offsets (
        {
            //1
           {Point2(0, 0),
           Point2(1,0),
           Point2(2*1,0),
           Point2(3*1,0),
           Point2(0,1),
           Point2(0,-1)
           },
            //2
           {Point2(0, 0),
           Point2(1,0),
           Point2(2*1,0),
           Point2(3*1,0),
           Point2(1*1,1),
           Point2(0,-1)
           },
            //3
           {Point2(0, 0),
           Point2(1,0),
           Point2(2*1,0),
           Point2(3*1,0),
           Point2(2*1,1),
           Point2(0,-1)
           },
            //4
           {Point2(0, 0),
           Point2(1,0),
           Point2(2*1,0),
           Point2(3*1,0),
           Point2(3*1,1),
           Point2(0,-1)
           },
            //5
           {Point2(0, 0),
           Point2(1,0),
           Point2(2*1,0),
           Point2(3*1,0),
           Point2(2*1,1),
           Point2(1*1,-1)
           },
            //6
           {Point2(0, 0),
           Point2(1,0),
           Point2(2*1,0),
           Point2(3*1,0),
           Point2(1*1,1),
           Point2(1*1,-1)
           },
            //7
           {Point2(1,0),
           Point2(2*1,0),
           Point2(3*1,0),
           Point2(0,-1),
           Point2(1*1,+1),
           Point2(1*1,-1)

           },
            //8
            {Point2(1,0),
            Point2(2*1,0),
            Point2(3*1,0),
            Point2(0,-1),
            Point2(2*1,+1),
            Point2(1*1,-1)
            },
            //9
            {Point2(1,0),
            Point2(2*1,0),
            Point2(3*1,0),
            Point2(0,-1),
            Point2(3*1,+1),
            Point2(1*1,-1)

            },
            //10
           {Point2(0, 0),
           Point2(1,0),
           Point2(2*1,0),
           Point2(3*1,1),
           Point2(2*1,1),
           Point2(4*1,1)
           },
            //11
           {Point2(1, 0),
           Point2(2*1,0),
           Point2(3*1,1),
           Point2(0,-1),
           Point2(2*1,1),
           Point2(1*1,-1)
           },

        }
        );
//带空offsets
//static QVector<QVector<Point2>> offsets (
//        {
//            //1
//           {Point2(0, 0),
//           Point2(1+squaresize/5,0),
//           Point2(2*1+squaresize*2/5,0),
//           Point2(3*1+squaresize*3/5,0),
//           Point2(0,1+squaresize/5),
//           Point2(0,-1-squaresize/5)
//           },
//            //2
//           {Point2(0, 0),
//           Point2(1+squaresize/5,0),
//           Point2(2*1+squaresize*2/5,0),
//           Point2(3*1+squaresize*3/5,0),
//           Point2(1*1+squaresize*1/5,1+squaresize/5),
//           Point2(0,-1-squaresize/5)
//           },
//            //3
//           {Point2(0, 0),
//           Point2(1+squaresize/5,0),
//           Point2(2*1+squaresize*2/5,0),
//           Point2(3*1+squaresize*3/5,0),
//           Point2(2*1+squaresize*2/5,1+squaresize/5),
//           Point2(0,-1-squaresize/5)
//           },
//            //4
//           {Point2(0, 0),
//           Point2(1+squaresize/5,0),
//           Point2(2*1+squaresize*2/5,0),
//           Point2(3*1+squaresize*3/5,0),
//           Point2(3*1+squaresize*3/5,1+squaresize/5),
//           Point2(0,-1-squaresize/5)
//           },
//            //5
//           {Point2(0, 0),
//           Point2(1+squaresize/5,0),
//           Point2(2*1+squaresize*2/5,0),
//           Point2(3*1+squaresize*3/5,0),
//           Point2(2*1+squaresize*2/5,1+squaresize/5),
//           Point2(1*1+squaresize*1/5,-1-squaresize/5)
//           },
//            //6
//           {Point2(0, 0),
//           Point2(1+squaresize/5,0),
//           Point2(2*1+squaresize*2/5,0),
//           Point2(3*1+squaresize*3/5,0),
//           Point2(1*1+squaresize*1/5,1+squaresize/5),
//           Point2(1*1+squaresize*1/5,-1-squaresize/5)
//           },
//            //7
//           {Point2(1+squaresize/5,0),
//           Point2(2*1+squaresize*2/5,0),
//           Point2(3*1+squaresize*3/5,0),
//           Point2(0,-1-squaresize/5),
//           Point2(1*1+squaresize*1/5,+1+squaresize/5),
//           Point2(1*1+squaresize*1/5,-1-squaresize/5)

//           },
//            //8
//            {Point2(1+squaresize/5,0),
//            Point2(2*1+squaresize*2/5,0),
//            Point2(3*1+squaresize*3/5,0),
//            Point2(0,-1-squaresize/5),
//            Point2(2*1+squaresize*2/5,+1+squaresize/5),
//            Point2(1*1+squaresize*1/5,-1-squaresize/5)
//            },
//            //9
//            {Point2(1+squaresize/5,0),
//            Point2(2*1+squaresize*2/5,0),
//            Point2(3*1+squaresize*3/5,0),
//            Point2(0,-1-squaresize/5),
//            Point2(3*1+squaresize*3/5,+1+squaresize/5),
//            Point2(1*1+squaresize*1/5,-1-squaresize/5)

//            },
//            //10
//           {Point2(0, 0),
//           Point2(1+squaresize/5,0),
//           Point2(2*1+squaresize*2/5,0),
//           Point2(3*1+squaresize*3/5,1+squaresize/5),
//           Point2(2*1+squaresize*2/5,1+squaresize/5),
//           Point2(4*1+squaresize*4/5,1+squaresize/5)
//           },
//            //11
//           {Point2(1+squaresize/5, 0),
//           Point2(2*1+squaresize*2/5,0),
//           Point2(3*1+squaresize*3/5,1+squaresize/5),
//           Point2(0,-1-squaresize/5),
//           Point2(2*1+squaresize*2/5,1+squaresize/5),
//           Point2(1*1+squaresize*1/5,-1-squaresize/5)
//           },

//        }
//        );
//static void globalupdate()
//{
//    offsets=
//    {
//        //1
//        //1
//       {Point2(0, 0),
//       Point2(1,0),
//       Point2(2*1,0),
//       Point2(3*1,0),
//       Point2(0,1),
//       Point2(0,-1)
//       },
//        //2
//       {Point2(0, 0),
//       Point2(1,0),
//       Point2(2*1,0),
//       Point2(3*1,0),
//       Point2(1*1,1),
//       Point2(0,-1)
//       },
//        //3
//       {Point2(0, 0),
//       Point2(1,0),
//       Point2(2*1,0),
//       Point2(3*1,0),
//       Point2(2*1,1),
//       Point2(0,-1)
//       },
//        //4
//       {Point2(0, 0),
//       Point2(1,0),
//       Point2(2*1,0),
//       Point2(3*1,0),
//       Point2(3*1,1),
//       Point2(0,-1)
//       },
//        //5
//       {Point2(0, 0),
//       Point2(1,0),
//       Point2(2*1,0),
//       Point2(3*1,0),
//       Point2(2*1,1),
//       Point2(1*1,-1)
//       },
//        //6
//       {Point2(0, 0),
//       Point2(1,0),
//       Point2(2*1,0),
//       Point2(3*1,0),
//       Point2(1*1,1),
//       Point2(1*1,-1)
//       },
//        //7
//       {Point2(1,0),
//       Point2(2*1,0),
//       Point2(3*1,0),
//       Point2(0,-1),
//       Point2(1*1,+1),
//       Point2(1*1,-1)

//       },
//        //8
//        {Point2(1,0),
//        Point2(2*1,0),
//        Point2(3*1,0),
//        Point2(0,-1),
//        Point2(2*1,+1),
//        Point2(1*1,-1)
//        },
//        //9
//        {Point2(1,0),
//        Point2(2*1,0),
//        Point2(3*1,0),
//        Point2(0,-1),
//        Point2(3*1,+1),
//        Point2(1*1,-1)

//        },
//        //10
//       {Point2(0, 0),
//       Point2(1,0),
//       Point2(2*1,0),
//       Point2(3*1,1),
//       Point2(2*1,1),
//       Point2(4*1,1)
//       },
//        //11
//       {Point2(1, 0),
//       Point2(2*1,0),
//       Point2(3*1,1),
//       Point2(0,-1),
//       Point2(2*1,1),
//       Point2(1*1,-1)
//       },

//    };

//}

static QVector<QVector<int>>RightRotate(QVector<QVector<int>>vec)
{
    QVector<QVector<int>>tempvec;
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
static QVector<QVector<int>>LeftRotate(QVector<QVector<int>>vec)
{
    QVector<QVector<int>>tempvec;
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


static QVector<QVector<int>>UpsideReverse(QVector<QVector<int>>vec)
{
    QVector<QVector<int>>tempvec;
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



static QVector<QVector<int>>LeftsideReverse(QVector<QVector<int>>vec)
{
    QVector<QVector<int>>tempvec;
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
static int random_unint(unsigned int min, unsigned int max)
{
    std::random_device rd;
    static std::default_random_engine e(rd());
    std::uniform_int_distribution<int> u(min, max);
    return u(e);
}



#endif // GLOBAL_H
