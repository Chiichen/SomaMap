#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    mainlayout(new QHBoxLayout(this)),
    menuscene(new MenuScene),
    viewscene(new ViewScene),
    gamescene(new GameScene),
    levelscene(new LevelScene)
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(menuscene);
    ui->stackedWidget->addWidget(viewscene);
    ui->stackedWidget->addWidget(gamescene);
    ui->stackedWidget->addWidget(levelscene);
    ui->stackedWidget->setCurrentWidget(menuscene);

    connect(menuscene,&MenuScene::start1,this,&MainWindow::start1);
    connect(menuscene,&MenuScene::start2,this,&MainWindow::start2);
    connect(gamescene,&GameScene::returnmenu,this,&MainWindow::returnmenu);
    connect(viewscene,&ViewScene::returnmenu,this,&MainWindow::returnmenu);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start1()
{
    ui->stackedWidget->setCurrentWidget(viewscene);
}
void MainWindow::start2()
{
    ui->stackedWidget->setCurrentWidget(levelscene);
}
void MainWindow::returnmenu()
{


    ui->stackedWidget->setCurrentWidget(menuscene);
    gamescene->reinitialize();
}
