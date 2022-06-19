#ifndef CUBE_H
#define CUBE_H
#include"global.h"


void bfscube(QVector<QVector<QVector<int>>>& cubevec, int n, int k );


class Cube
{
public:
    Cube();
    void rebuild();
    void rebuild(int);

    QVector<QVector3D> GetCubePosition();
    QVector3D GetCamaraPosition();
    QVector<QVector<int>> GetFront();
    QVector<QVector<int>> GetBack();
    QVector<QVector<int>> GetUp();
    QVector<QVector<int>> GetDown();
    QVector<QVector<int>> GetLeft();
    QVector<QVector<int>> GetRight();
    QVector<QVector<QVector<int>>> GetAllView();
    QVector<QVector<QVector<int>>> GetExpandView(int k);
    void SetCubevec(QVector<QVector<QVector<int>>> vec){cubevec = vec;}
private:
    QVector<QVector<QVector<int>>> cubevec;
    QVector<Point2> offsetvec;
};


#endif // CUBE_H
