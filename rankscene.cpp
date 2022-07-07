#include "rankscene.h"
#include "ui_rankscene.h"

RankScene::RankScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RankScene)
{
    ui->setupUi(this);
}

RankScene::~RankScene()
{
    delete ui;
}

void RankScene::on_commandLinkButton_clicked()
{
    emit returnmenu();
}

void RankScene::insertrank(QString name,int score,QString level)
{
    ui->rankwidget->insert(name,score,level);

}
