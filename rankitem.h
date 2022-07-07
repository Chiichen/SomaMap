#ifndef RANKITEM_H
#define RANKITEM_H

#include"global.h"

namespace Ui {
class RankItem;
}

class RankItem : public QWidget
{
    Q_OBJECT

public:
    explicit RankItem(QWidget *parent = nullptr);
    ~RankItem();
    void setrank(int a);
    void setname(QString str);
    void setscore(int a);
    void settime(QString str);
    void setlevel(QString level);
    bool operator <(RankItem);
    int score;
private:
    Ui::RankItem *ui;
};

#endif // RANKITEM_H
