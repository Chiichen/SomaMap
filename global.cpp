//#include"global.h"

//static std::vector<std::vector<int>>RightRotate(std::vector<std::vector<int>>vec)
//{
//    std::vector<std::vector<int>>tempvec;
//    tempvec.resize(vec.size());
//    for(auto e:vec) e.resize(vec[0].size());
//    int k = vec.size();
//    int p = vec[0].size();
//    for(int i=0;i<k;i++)
//    {
//        for(int j=0; j<p; j++)
//        {
//            tempvec[i][j]=vec[k-1-j][i];
//        }
//    }
//    return tempvec;
//}
//static std::vector<std::vector<int>>LeftRotate(std::vector<std::vector<int>>vec)
//{
//    std::vector<std::vector<int>>tempvec;
//    tempvec.resize(vec.size());
//    for(auto e:vec) e.resize(vec[0].size());
//    int k = vec.size();
//    int p = vec[0].size();
//    for(int i=0;i<k;i++)
//    {
//        for(int j=0; j<p; j++)
//        {
//            tempvec[k-1-j][i]=vec[i][j];
//        }
//    }
//    return tempvec;
//}


//static std::vector<std::vector<int>>UpsideReverse(std::vector<std::vector<int>>vec)
//{
//    std::vector<std::vector<int>>tempvec;
//    tempvec.resize(vec.size());
//    for(auto e:vec) e.resize(vec[0].size());
//    int k = vec.size();
//    int p = vec[0].size();
//    for(int i=0;i<k;i++)
//    {
//        for(int j=0; j<p; j++)
//        {
//            tempvec[i][j]=vec[i][p-1-j];
//        }
//    }
//    return tempvec;
//}



//static std::vector<std::vector<int>>LeftReverse(std::vector<std::vector<int>>vec)
//{
//    std::vector<std::vector<int>>tempvec;
//    tempvec.resize(vec.size());
//    for(auto e:vec) e.resize(vec[0].size());
//    int k = vec.size();
//    int p = vec[0].size();
//    for(int i=0;i<k;i++)
//    {
//        for(int j=0; j<p; j++)
//        {
//            tempvec[k-1-i][j]=vec[i][j];
//        }
//    }
//    return tempvec;
//}
