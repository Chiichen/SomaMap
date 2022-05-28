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
    square->SetCubevec(cube.GetFront());
    square->UpdateSquare();
}


void MainWindow::on_build2_clicked()
{
    square->SetCube(cube);
    square->SetUnEditableSquare();
}


void MainWindow::on_resetrotate_clicked()
{
    ui->myglwidget->resetRotate();
}

