#include "gamescene.h"
#include "ui_gamescene.h"

GameScene::GameScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameScene),
    timer1s(new QTimer),
    remaintime(10),
    grandsquare(new GrandSquare)
{

    ui->setupUi(this);
    timer1s->start(1000);
    connect(timer1s,&QTimer::timeout,this,&GameScene::timer1sout);
    connect(grandsquare,&GrandSquare::win,this,&GameScene::win);

    ui->graphicsView->setScene(grandsquare);
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
    ui->lcdNumber->display(QString::number((remaintime--)/60)+":"+QString::number(remaintime%60));
    if(remaintime==0) {
        timer1s->stop();
        emit timeout();
        return;
    }
}

void GameScene::win()
{
    QMessageBox message;
    message.setText("您获得了胜利！得分为"+QString::number(remaintime*100));
    message.setInformativeText("重新游玩或者返回菜单");
    auto playagainbutton = message.addButton("再来一次",QMessageBox::YesRole);
    auto returnmenubutton = message.addButton("返回主菜单",QMessageBox::NoRole);
    message.exec();
    if(message.clickedButton()==playagainbutton)
    {
        delete grandsquare;
        auto grandsquare=new GrandSquare;
        connect(grandsquare,&GrandSquare::win,this,&GameScene::win);
        ui->graphicsView->setScene(grandsquare);
    }
    else if(message.clickedButton()==returnmenubutton)
    {
        emit returnmenu();
    }

}




void GameScene::on_showans_clicked()
{

}

