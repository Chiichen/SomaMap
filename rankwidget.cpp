#include "rankwidget.h"

RankWidget::RankWidget(QWidget *parent) :
    QListWidget(parent)
{

}

RankWidget::~RankWidget()
{
}

void RankWidget::insert(QString name, int score,QString level)
{
    RankItem* item = new RankItem();
    QListWidgetItem* listItem = new QListWidgetItem(this);
    listItem->setSizeHint(QSize(item->width(),item->height()));
    itemvec.push_back(item);
    std::sort(itemvec.begin(),itemvec.end(),[](RankItem* i1,RankItem* i2)->bool{return i1->score>i2->score;});
    for(int i=0;i<itemvec.size();i++) itemvec[i]->setrank(i+1);
    item->setname(name);
    item->setscore(score);
    item->setlevel(level);
    item->settime(QDateTime::currentDateTime().toString());
    insertItem(count(),listItem);
    itemvec.push_back(item);
    this->setItemWidget(listItem,item);
    if(score<10000)    listItem->setText(QString::number(0)+QString::number(score));
    else listItem->setText(QString::number(score));
    listItem->setForeground(QColor(255,255,255));
    QFont font;
    font.setPointSize(25);
    listItem->setFont(QFont(font));
    this->setSortingEnabled(true);
    this->sortItems(Qt::DescendingOrder);
}
