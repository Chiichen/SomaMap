#ifndef SQUARE_H
#define SQUARE_H

#include <QGraphicsScene>
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
    void SetUnEditableSquare();
    void SetEditableSquare();
private:
    std::vector<std::vector<int>> Cubevec;
    int length=0;
    bool state = true;
    Cube cube;
    std::vector<std::vector<FigureMate*>> mates;


};

#endif // SQUARE_H
