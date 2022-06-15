#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    mainlayout(new QHBoxLayout(this)),
    firstscene(new FirstScene),
    menuscene(new MenuScene)
{
    ui->setupUi(this);
    ui->stackedWidget->addWidget(firstscene);
    ui->stackedWidget->addWidget(menuscene);
    ui->stackedWidget->setCurrentWidget(menuscene);
    connect(menuscene,&MenuScene::start1,this,&MainWindow::start1);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::start1()
{
    ui->stackedWidget->setCurrentWidget(firstscene);
}


