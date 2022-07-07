#ifndef RANKWIDGET_H
#define RANKWIDGET_H
#include"rankitem.h"
#include<global.h>



class RankWidget : public QListWidget
{
    Q_OBJECT

public:
    explicit RankWidget(QWidget *parent = nullptr);
    ~RankWidget();
    void insert(QString name,int score,QString level);
public slots:

private:
    QVector<RankItem*> itemvec;
};

#endif // RANKWIDGET_H
