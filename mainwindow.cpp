#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    square(new Square)
{
    ui->setupUi(this);
    ui->graphicsView->setScene(square);
    square->SetCube(cube);
    ui->myglwidget->SetCube(cube);
    ui->myglwidget->RebuildCube();
    square->DisplayThreeviews();

    //connect(ui->Rebuild,SIGNAL(clicked()),ui->myglwidget,SLOT(RebuildCube()));
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_Rebuild_clicked()
{
    cube.rebuild();
    ui->myglwidget->SetCube(cube);
    ui->myglwidget->RebuildCube();
    square->SetCube(cube);
    square->SetLength(N);
    square->UpdateSquare();
}


void MainWindow::on_build2_clicked()
{
    square->SetCube(cube);
    square->DisplayExpand();
}


//void MainWindow::on_resetrotate_clicked()
//{
//    ui->myglwidget->resetRotate();
//}



void MainWindow::on_spinBox_valueChanged(int arg1)
{
    square->SetViewchoice(arg1-1);
    square->DisplayExpand();
}


void MainWindow::on_buildfromsquare_clicked()
{
    cube=square->OutputCube();
    ui->myglwidget->SetCube(cube);
    ui->myglwidget->RebuildCube();
}

