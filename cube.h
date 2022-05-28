#ifndef CUBE_H
#define CUBE_H
#include"global.h"

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
    std::vector<std::vector<std::vector<int>>> GetAllView();
    void SetCubevec(std::vector<std::vector<std::vector<int>>> vec){cubevec = vec;}
private:
    std::vector<std::vector<std::vector<int>>> cubevec;
    std::vector<Point2> offsetvec;
};


#endif // CUBE_H
