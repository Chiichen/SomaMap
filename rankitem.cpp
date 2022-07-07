#include "rankitem.h"
#include "ui_rankitem.h"

RankItem::RankItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RankItem)
{
    ui->setupUi(this);
}

RankItem::~RankItem()
{
    delete ui;
}

void RankItem::setrank(int a)
{
    //ui->rank->setText(QString::number(a));
}

void RankItem::setname(QString str)
{
    ui->name->setText(str);
}
void RankItem::setscore(int a)
{
    ui->score->setText(QString::number(a));
    score = a;
}

bool RankItem::operator <(RankItem item)
{
    return this->score<item.score;
}
void RankItem::settime(QString str)
{
    ui->time->setText(str);
}
void RankItem::setlevel(QString level)
{
    ui->level->setText(level);
}
