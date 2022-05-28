#include "cube.h"

int random_unint(unsigned int min, unsigned int max)
{
    std::random_device rd;
    static std::default_random_engine e(rd());
    std::uniform_int_distribution<int> u(min, max);
    return u(e);
}
void bfscube(std::vector<std::vector<std::vector<int>>>& cubevec, int n, int k )
{
    int move_x[]={0,0,0,0,1,-1,0};
    int move_y[]={1,-1,0,0,0,0,0};
    int move_z[]={0,0,1,-1,0,0,0};
    Point3 p1(N/2,N/2,N/2);
    cubevec[N/2][N/2][N/2]=1;
    std::queue<Point3> que;
    que.push(p1);
    int count = 0;
    while(!que.empty())
    {
        Point3 p = que.front();
        que.pop();
        for(int i=0; i<7; i++)
        {
            Point3 curp(p.x+move_x[i],p.y+move_y[i],p.z+move_z[i]);
            if(curp.x>=0&&curp.x<N&&curp.y>=0&&curp.y<N&&curp.z>=0&&curp.z<N&&cubevec[curp.x][curp.y][curp.z]==0&&random_unint(0,100)<=k&&count<n)
            {
                cubevec[curp.x][curp.y][curp.z] = 1;
                count++;
                que.push(curp);
            }
            else if(count<n-1&&que.empty())
            {
                que.push(curp);
            }
        }
    }
}


Cube::Cube()
    :cubevec(0)
{
    cubevec.clear();
    cubevec.resize(N);
    for(auto &e:cubevec)
    {
        e.resize(N);
        for(auto &u:e)
        {
            u.resize(N);
        }
    }
    bfscube(cubevec,N*(N-1),60);
}

void Cube::rebuild()
{
    cubevec.clear();
    cubevec.resize(N);
    for(auto &e:cubevec)
    {
        e.resize(N);
        for(auto &u:e)
        {
            u.resize(N);
        }
    }

    bfscube(cubevec,N*(N-1),60);
}

void Cube::rebuild(int n)
{
    if(n<=1||n>6)
    {
        return;
    }
    else N=n;
    cubevec.clear();
    cubevec.resize(N);
    for(auto &e:cubevec)
    {
        e.resize(N);
        for(auto &u:e)
        {
            u.resize(N);
        }
    }
    return;
}

std::vector<QVector3D> Cube::GetCubePosition()
{
    std::vector<QVector3D> vec;
    for(int x=0;x<N;x++)
            for(int y=0;y<N;y++)
                    for(int z=0;z<N;z++)
                            if(cubevec[x][y][z]==1)
                                    vec.push_back(QVector3D(x*1.0f,y*1.0f,z*1.0f));
    if(N%2==0)
    {
        for(auto &e:vec)
        {
            e.setX(e.x()-(N/2)*1.0f+0.5f);
            e.setY(e.y()-(N/2)*1.0f+0.5f);
            e.setZ(e.z()-(N/2)*1.0f+0.5f);
        }
    }
    else if(N%2!=0)
    {
        for(auto &e:vec)
        {
            e.setX(e.x()-((N-1)/2)*1.0f);
            e.setY(e.y()-((N-1)/2)*1.0f);
            e.setZ(e.z()-((N-1)/2)*1.0f);
        }
    }
    return vec;

}

QVector3D Cube::GetCamaraPosition()
{
    return QVector3D(0,0,4.0f);
}

std::vector<std::vector<int>> Cube::GetFront()
{
    std::vector<std::vector<int>> vec;
    vec.resize(N);
    for(auto &e:vec)
    {
        e.resize(N);
    }
    for(int z=0;z<N;z++)
    {
        for(int y=0;y<N;y++)
        {
            for(int x = 0;x<N;x++)
            {
                vec[x][y]=vec[x][y]|cubevec[x][y][z];
            }
        }
    }
    return vec;
}
std::vector<std::vector<int>> Cube::GetBack()
{
    std::vector<std::vector<int>> vec;
    vec.resize(N);
    for(auto &e:vec)
    {
        e.resize(N);
    }
    for(int z=0;z<N;z++)
    {
        for(int y=0;y<N;y++)
        {
            for(int x = N;x>=0;x--)
            {
                vec[x][y]=vec[x][y]|cubevec[x][y][z];
            }
        }
    }
    return vec;
}
std::vector<std::vector<int>> Cube::GetUp()
{
    std::vector<std::vector<int>> vec;
    vec.resize(N);
    for(auto &e:vec)
    {
        e.resize(N);
    }
    for(int y=0;y<N;y++)
    {
        for(int z=N;z>=0;z--)
        {
            for(int x = 0;x<N;x++)
            {
                vec[x][y]=vec[x][y]|cubevec[x][y][z];
            }
        }
    }
    return vec;
}
std::vector<std::vector<int>> Cube::GetDown()
{
    std::vector<std::vector<int>> vec;
    vec.resize(N);
    for(auto &e:vec)
    {
        e.resize(N);
    }
    for(int y=0;y<N;y++)
    {
        for(int z=0;z<N;z++)
        {
            for(int x = 0;x<N;x++)
            {
                vec[x][y]=vec[x][y]|cubevec[x][y][z];
            }
        }
    }
    return vec;
}
std::vector<std::vector<int>> Cube::GetLeft()
{
    std::vector<std::vector<int>> vec;
    vec.resize(N);
    for(auto &e:vec)
    {
        e.resize(N);
    }
    for(int x=0;x<N;x++)
    {
        for(int z=0;z<N;z++)
        {
            for(int y = 0;y<N;y++)
            {
                vec[x][y]=vec[x][y]|cubevec[x][y][z];
            }
        }
    }
    return vec;
}
std::vector<std::vector<int>> Cube::GetRight()
{
    std::vector<std::vector<int>> vec;
    vec.resize(N);
    for(auto &e:vec)
    {
        e.resize(N);
    }
    for(int y=0;y<N;y++)
    {
        for(int z=N;z>=0;z--)
        {
            for(int x = 0;x<N;x++)
            {
                vec[x][y]=vec[x][y]|cubevec[x][y][z];
            }
        }
    }
    return vec;
}


