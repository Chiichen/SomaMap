#include "cube.h"


void bfscube(QVector<QVector<QVector<int>>>& cubevec, int n, int k )
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

QVector<QVector3D> Cube::GetCubePosition()
{
    QVector<QVector3D> vec;
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

QVector<QVector<int>> Cube::GetFront()
{
    QVector<QVector<int>> vec;
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
QVector<QVector<int>> Cube::GetBack()
{
    QVector<QVector<int>> vec;
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
                vec[x][y]=vec[x][y]|cubevec[N-x-1][y][z];
            }
        }
    }
    return vec;
}
QVector<QVector<int>> Cube::GetUp()
{
    QVector<QVector<int>> vec;
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
                vec[x][z]=vec[x][z]|cubevec[x][y][N-z-1];
            }
        }
    }
    return vec;
}
QVector<QVector<int>> Cube::GetDown()
{
    QVector<QVector<int>> vec;
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
                vec[x][z]=vec[x][z]|cubevec[x][y][z];
            }
        }
    }
    return vec;
}
QVector<QVector<int>> Cube::GetLeft()
{
    QVector<QVector<int>> vec;
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
                vec[z][y]=vec[z][y]|cubevec[x][y][z];
            }
        }
    }
    return vec;
}
QVector<QVector<int>> Cube::GetRight()
{
    QVector<QVector<int>> vec;
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
                vec[z][y]=vec[z][y]|cubevec[x][y][N-z-1];
            }
        }
    }
    return vec;
}




 QVector<QVector<QVector<int>>> Cube::GetAllView()
 {
QVector<QVector<QVector<int>>> vec;
     vec.push_back(this->GetDown());
     vec.push_back(this->GetRight());
     vec.push_back(this->GetUp());
     vec.push_back(this->GetLeft());
     vec.push_back(this->GetFront());
     vec.push_back(this->GetBack());
     return vec;
 }
 QVector<QVector<QVector<int>>> Cube::GetExpandView(int k)
 {
     QVector<QVector<QVector<int>>> ansvec1=this->GetAllView();

     switch (k)
     {
        case 0:
     {
        ansvec1[0]=UpsideReverse(ansvec1[0]);
        ansvec1[1]=UpsideReverse(ansvec1[1]);
        ansvec1[1]=LeftRotate(ansvec1[1]);
        ansvec1[2]=LeftsideReverse(ansvec1[2]);
        ansvec1[3]=UpsideReverse(ansvec1[3]);
        ansvec1[3]=RightRotate(ansvec1[3]);
        ansvec1[4]=UpsideReverse(ansvec1[4]);
        ansvec1[5]=LeftsideReverse(ansvec1[5]);


        return ansvec1;
     }
        case 1:
     {
         ansvec1[4]=RightRotate(ansvec1[4]);
         ansvec1[0]=UpsideReverse(ansvec1[0]);
         ansvec1[1]=UpsideReverse(ansvec1[1]);
         ansvec1[1]=LeftRotate(ansvec1[1]);
         ansvec1[2]=LeftsideReverse(ansvec1[2]);
         ansvec1[3]=UpsideReverse(ansvec1[3]);
         ansvec1[3]=RightRotate(ansvec1[3]);
         ansvec1[4]=UpsideReverse(ansvec1[4]);
         ansvec1[5]=LeftsideReverse(ansvec1[5]);
         return ansvec1;
     }
     case 2:
     {
         ansvec1[4]=RightRotate(ansvec1[4]);
         ansvec1[4]=RightRotate(ansvec1[4]);

         ansvec1[0]=UpsideReverse(ansvec1[0]);
         ansvec1[1]=UpsideReverse(ansvec1[1]);
         ansvec1[1]=LeftRotate(ansvec1[1]);
         ansvec1[2]=LeftsideReverse(ansvec1[2]);
         ansvec1[3]=UpsideReverse(ansvec1[3]);
         ansvec1[3]=RightRotate(ansvec1[3]);
         ansvec1[4]=UpsideReverse(ansvec1[4]);
         ansvec1[5]=LeftsideReverse(ansvec1[5]);
         return ansvec1;
     }
     case 3:
     {
         ansvec1[4]=RightRotate(ansvec1[4]);
         ansvec1[4]=RightRotate(ansvec1[4]);
         ansvec1[4]=RightRotate(ansvec1[4]);

         ansvec1[0]=UpsideReverse(ansvec1[0]);
         ansvec1[1]=UpsideReverse(ansvec1[1]);
         ansvec1[1]=LeftRotate(ansvec1[1]);
         ansvec1[2]=LeftsideReverse(ansvec1[2]);
         ansvec1[3]=UpsideReverse(ansvec1[3]);
         ansvec1[3]=RightRotate(ansvec1[3]);
         ansvec1[4]=UpsideReverse(ansvec1[4]);
         ansvec1[5]=LeftsideReverse(ansvec1[5]);
         return ansvec1;
     }
     case 4:
     {
         ansvec1[5]=LeftRotate(ansvec1[5]);
         ansvec1[4]=RightRotate(ansvec1[4]);
         ansvec1[4]=RightRotate(ansvec1[4]);

         ansvec1[0]=UpsideReverse(ansvec1[0]);
         ansvec1[1]=UpsideReverse(ansvec1[1]);
         ansvec1[1]=LeftRotate(ansvec1[1]);
         ansvec1[2]=LeftsideReverse(ansvec1[2]);
         ansvec1[3]=UpsideReverse(ansvec1[3]);
         ansvec1[3]=RightRotate(ansvec1[3]);
         ansvec1[4]=UpsideReverse(ansvec1[4]);
         ansvec1[5]=LeftsideReverse(ansvec1[5]);
         return ansvec1;
     }
     case 5:
     {
         ansvec1[5]=LeftRotate(ansvec1[5]);
         ansvec1[4]=RightRotate(ansvec1[4]);

         ansvec1[0]=UpsideReverse(ansvec1[0]);
         ansvec1[1]=UpsideReverse(ansvec1[1]);
         ansvec1[1]=LeftRotate(ansvec1[1]);
         ansvec1[2]=LeftsideReverse(ansvec1[2]);
         ansvec1[3]=UpsideReverse(ansvec1[3]);
         ansvec1[3]=RightRotate(ansvec1[3]);
         ansvec1[4]=UpsideReverse(ansvec1[4]);
         ansvec1[5]=LeftsideReverse(ansvec1[5]);
         return ansvec1;
     }
     case 6:
     {
         ansvec1[3]=LeftRotate(ansvec1[3]);

         ansvec1[0]=UpsideReverse(ansvec1[0]);
         ansvec1[1]=UpsideReverse(ansvec1[1]);
         ansvec1[1]=LeftRotate(ansvec1[1]);
         ansvec1[2]=LeftsideReverse(ansvec1[2]);
         ansvec1[3]=UpsideReverse(ansvec1[3]);
         ansvec1[3]=RightRotate(ansvec1[3]);
         ansvec1[4]=UpsideReverse(ansvec1[4]);
         ansvec1[5]=LeftsideReverse(ansvec1[5]);
         return ansvec1;
     }
     case 7:
     {
         ansvec1[4]=RightRotate(ansvec1[4]);
         ansvec1[3]=LeftRotate(ansvec1[3]);

         ansvec1[0]=UpsideReverse(ansvec1[0]);
         ansvec1[1]=UpsideReverse(ansvec1[1]);
         ansvec1[1]=LeftRotate(ansvec1[1]);
         ansvec1[2]=LeftsideReverse(ansvec1[2]);
         ansvec1[3]=UpsideReverse(ansvec1[3]);
         ansvec1[3]=RightRotate(ansvec1[3]);
         ansvec1[4]=UpsideReverse(ansvec1[4]);
         ansvec1[5]=LeftsideReverse(ansvec1[5]);
         return ansvec1;
     }
     case 8:
     {
         ansvec1[4]=RightRotate(ansvec1[4]);
         ansvec1[4]=RightRotate(ansvec1[4]);
         ansvec1[3]=LeftRotate(ansvec1[3]);

         ansvec1[0]=UpsideReverse(ansvec1[0]);
         ansvec1[1]=UpsideReverse(ansvec1[1]);
         ansvec1[1]=LeftRotate(ansvec1[1]);
         ansvec1[2]=LeftsideReverse(ansvec1[2]);
         ansvec1[3]=UpsideReverse(ansvec1[3]);
         ansvec1[3]=RightRotate(ansvec1[3]);
         ansvec1[4]=UpsideReverse(ansvec1[4]);
         ansvec1[5]=LeftsideReverse(ansvec1[5]);
         return ansvec1;
     }
     case 9:
     {


         ansvec1[0]=UpsideReverse(ansvec1[0]);
         ansvec1[1]=UpsideReverse(ansvec1[1]);
         ansvec1[1]=LeftRotate(ansvec1[1]);
         ansvec1[2]=LeftsideReverse(ansvec1[2]);
         ansvec1[3]=LeftsideReverse(ansvec1[3]);
         ansvec1[4]=LeftsideReverse(ansvec1[4]);
         ansvec1[5]=LeftsideReverse(ansvec1[5]);
         return ansvec1;
     }
     case 10:
     {
         ansvec1[3]=LeftRotate(ansvec1[3]);
         ansvec1[4]=RightRotate(ansvec1[4]);
         ansvec1[2]=LeftRotate(ansvec1[2]);

         ansvec1[0]=UpsideReverse(ansvec1[0]);
         ansvec1[1]=UpsideReverse(ansvec1[1]);
         ansvec1[1]=LeftRotate(ansvec1[1]);
         ansvec1[2]=LeftsideReverse(ansvec1[2]);
         ansvec1[3]=UpsideReverse(ansvec1[3]);
         ansvec1[3]=RightRotate(ansvec1[3]);
         ansvec1[4]=UpsideReverse(ansvec1[4]);
         ansvec1[5]=LeftsideReverse(ansvec1[5]);
         return ansvec1;
     }
     default:
         return ansvec1;
     }
 }

