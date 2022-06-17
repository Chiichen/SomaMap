#include "gamescene.h"
#include "ui_gamescene.h"

GameScene::GameScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameScene),
    timer1s(new QTimer),
    remaintime(62)
{
    ui->setupUi(this);
    timer1s->start(1000);
    connect(timer1s,&QTimer::timeout,this,&GameScene::timer1sout);
}

GameScene::~GameScene()
{
    delete ui;
}

void GameScene::on_commandLinkButton_clicked()
{
    emit returnmenu();
}

void GameScene::timer1sout()
{
    if(remaintime==1) {
        emit timeout();
        return;
    }
    ui->lcdNumber->display(QString::number((remaintime--)/60)+":"+QString::number(remaintime%60));
}


