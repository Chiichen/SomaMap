#include "gamescene.h"
#include "ui_gamescene.h"

GameScene::GameScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameScene),
    timer1s(new QTimer),
    remaintime(100),
    grandsquare(new GrandSquare(this)),
    hintnum(2),
    timelimit(60),
    curdifficulty(0),
    totalrecord(0)
{

    ui->setupUi(this);
    timer1s->start(1000);
    connect(timer1s,&QTimer::timeout,this,&GameScene::timer1sout);
    connect(grandsquare,&GrandSquare::win,this,&GameScene::win);
    ui->showans->setText(QString("显示答案")+"(剩余"+QString::number(hintnum)+"次)");
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
    auto nextlevelbutton = message.addButton("下一关",QMessageBox::AcceptRole);
    auto returnmenubutton = message.addButton("返回主菜单",QMessageBox::NoRole);
    message.exec();
    ///message.close();
    timer1s->stop();
    if(message.clickedButton()==playagainbutton)
    {
        emit loading();
//        qDebug()<<333;
//        this->setAttribute(Qt::WA_TransparentForMouseEvents, true);
//        reinitialize();
//        QTimer::singleShot(2000,[=]()->void{this->setAttribute(Qt::WA_TransparentForMouseEvents, false);});

    }
    else if(message.clickedButton()==returnmenubutton)
    {
        totalrecord+=remaintime*100;
                   qDebug()<<username;
        emit addrank(username,totalrecord,QString::number(curdifficulty+1));
        totalrecord=0;
        emit returnmenu();
    }
    else if (message.clickedButton()==nextlevelbutton)
    {
        totalrecord+=remaintime*100;
        if(curdifficulty<8)
        {
             setdifficulty(difvec[std::min(8,++curdifficulty)]);
             emit loading();
        }
        else
        {
            AnimatedWidget::showHintLabel(this,"您已抵达深渊之底");
            emit addrank(username,totalrecord,QString::number(curdifficulty+1));
            totalrecord=0;
            QTimer::singleShot(2000,[=]()->void{emit returnmenu();});
        }


    }
    message.close();
}




void GameScene::on_showans_clicked()
{
    if(hintnum>0)
    {
       grandsquare->showans();
       ui->showans->setText(QString("显示答案")+"(剩余"+QString::number(--hintnum)+"次)");
    }
    else
    {
        AnimatedWidget::showHintLabel(this,"无剩余显示答案机会");
    }

}

void GameScene::reinitialize()
{
    timer1s->start();
    remaintime = timelimit;
    hintnum = difvec[curdifficulty].hintnum;
    ui->showans->setText(QString("显示答案")+"(剩余"+QString::number(hintnum)+"次)");
    grandsquare->Initialize();
//    emit loadend();

}

void GameScene::setdifficulty(Difficulty dif)
{
    grandsquare->width=dif.width;
    grandsquare->height=dif.height;
    grandsquare->cubenum=dif.height;
    hintnum = dif.hintnum;
    timelimit = dif.timelimit;
    remaintime = timelimit;
}
