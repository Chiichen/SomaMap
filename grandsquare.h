#ifndef GRANDSQUARE_H
#define GRANDSQUARE_H

#include"global.h"
#include"figuremate.h"
class grandsquare : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit grandsquare(QObject *parent = nullptr);
private:
    int width;
    int height;
    QVector<QVector<QVector<FigureMate*>>> Mmates;
};

#endif // GRANDSQUARE_H
