#include "viewscene.h"
#include "ui_viewscene.h"

ViewScene::ViewScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewScene),
    cube(new Cube),
    square(new Square),
    myglwidget(new MyGLWidget)
{
    ui->setupUi(this);
    glwidgetlayout=new QHBoxLayout(ui->frame->widget());
    ui->graphicview->setScene(square);
    square->SetCube(*cube);
    myglwidget->SetCube(*cube);
    glwidgetlayout->addWidget(myglwidget);
    square->DisplayExpand();
}

ViewScene::~ViewScene()
{
    delete ui;
}

void ViewScene::on_BuildFromView_clicked()
{
    cube = new Cube(this->square->OutputCube());
    square->SetCube(*cube);
    myglwidget->SetCube(*cube);
    myglwidget->RebuildCube();
}


void ViewScene::on_DisplayExpand_clicked()
{
     square->DisplayExpand();
}


void ViewScene::on_DisplayThreeviews_clicked()
{
        this->square->DisplayThreeviews();
}


void ViewScene::on_RebuildCubbe_clicked()
{
    cube->rebuild();
    myglwidget->SetCube(*cube);
    square->SetCube(*cube);
    myglwidget->RebuildCube();
    square->UpdateSquare();
}


void ViewScene::on_ResetRot_clicked()
{
       myglwidget->resetRotate();
}


void ViewScene::on_SetViewchoice_valueChanged(int arg1)
{
    square->SetViewchoice(arg1-1);
    square->DisplayExpand();
}


void ViewScene::on_commandLinkButton_clicked()
{
    emit returnmenu();
}

