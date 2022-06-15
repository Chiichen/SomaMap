#ifndef SQUARE_H
#define SQUARE_H

#include"global.h"
#include"figuremate.h"
#include"cube.h"
class Square : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit Square(QObject *parent = nullptr);
    ~Square();
    void UpdateSquare();
    void SetLength(int l){length = l;}
    void SetCubevec(std::vector<std::vector<int>> vec){Cubevec = vec;}
    void initialize();
    void SetCube(Cube c){cube = c;}
    void DisplayExpand();
    void DisplayThreeviews();
    void SetViewchoice(int k){viewchoice = k;}
    Cube OutputCube();
private:
    std::vector<std::vector<int>> Cubevec;
    int length=0;
    bool state = true;
    int viewchoice = 0;
    Cube cube;
    std::vector<std::vector<Point2>> offset;
    std::vector<std::vector<std::vector<FigureMate*>>> Mmates;//六向视图
    std::vector<std::vector<std::vector<FigureMate*>>> three_views;//可操作三视图
    Cube outputcube;

signals:
};




#endif // SQUARE_H
