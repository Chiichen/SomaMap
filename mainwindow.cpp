#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //connect(ui->Rebuild,SIGNAL(clicked()),ui->myglwidget,SLOT(RebuildCube()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


