#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    mainlayout(new QHBoxLayout(this)),
    menuscene(new MenuScene),
    viewscene(new ViewScene),
    gamescene(new GameScene),
    rankscene(new RankScene),
    welcomescene(new WelcomeScene),
    loadingscene(new LoadingScene)
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(menuscene);
    ui->stackedWidget->addWidget(viewscene);
    ui->stackedWidget->addWidget(gamescene);
    ui->stackedWidget->addWidget(rankscene);
    ui->stackedWidget->addWidget(welcomescene);
    ui->stackedWidget->addWidget(loadingscene);
    ui->stackedWidget->setCurrentWidget(welcomescene);
    connect(gamescene,&GameScene::addrank,rankscene,&RankScene::insertrank);
    connect(gamescene,&GameScene::loading,this,&MainWindow::loading);
//    connect(gamescene,&GameScene::loadend,this,&MainWindow::loadend);
    connect(welcomescene,&WelcomeScene::startgame,this,&MainWindow::rowreturnmenu);
    connect(menuscene,&MenuScene::exit,qApp,&QApplication::quit);
    connect(menuscene,&MenuScene::rankscene,this,&MainWindow::openrank);
    connect(menuscene,&MenuScene::start1,this,&MainWindow::start1);
    connect(menuscene,&MenuScene::start2,this,&MainWindow::start2);
    connect(gamescene,&GameScene::returnmenu,this,&MainWindow::returnmenu);
    connect(viewscene,&ViewScene::returnmenu,this,&MainWindow::rowreturnmenu);
    connect(rankscene,&RankScene::returnmenu,this,&MainWindow::rowreturnmenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start1()
{
    viewscene->reinitialize();
    ui->stackedWidget->setCurrentWidget(viewscene);
}
void MainWindow::start2()
{
    gamescene->reinitialize();
    ui->stackedWidget->setCurrentWidget(gamescene);
}
void MainWindow::returnmenu()
{
    //qDebug()<<"??????";
    ui->stackedWidget->setCurrentWidget(menuscene);

}
void MainWindow::rowreturnmenu()
{
    ui->stackedWidget->setCurrentWidget(menuscene);
}
void MainWindow::openrank()
{
    ui->stackedWidget->setCurrentWidget(rankscene);

}

void MainWindow::loading()
{
    ui->stackedWidget->setCurrentWidget(loadingscene);
    QTimer::singleShot(2000,[=]()->void{emit menuscene->start2();});


}

//void MainWindow::loadend()
//{
//    gamescene->reinitialize();
//    ui->stackedWidget->setCurrentWidget(gamescene);
//}
