#ifndef CUBE_H
#define CUBE_H
#include<vector>
#include<random>
#include<queue>
#include <QVector3D>
#include <QMatrix4x4>


static int N = 4;

struct Point3{
    int x=0;
    int y=0;
    int z=0;
    Point3(int a,int b,int c)
        :x(a),y(b),z(c){}
};

int random_unint(unsigned int min, unsigned int max);

void bfscube(std::vector<std::vector<std::vector<int>>>& cubevec, int n, int k );


class Cube
{
public:
    Cube();
    void rebuild();
    void rebuild(int);

    std::vector<QVector3D> GetCubePosition();
    QVector3D GetCamaraPosition();
    std::vector<std::vector<int>> GetFront();
    std::vector<std::vector<int>> GetBack();
    std::vector<std::vector<int>> GetUp();
    std::vector<std::vector<int>> GetDown();
    std::vector<std::vector<int>> GetLeft();
    std::vector<std::vector<int>> GetRight();

private:
    std::vector<std::vector<std::vector<int>>> cubevec;

};


#endif // CUBE_H
