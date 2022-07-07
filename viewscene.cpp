#include "viewscene.h"
#include "ui_viewscene.h"

ViewScene::ViewScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ViewScene),
    cube(new Cube),
    square(new Square),
    myglwidget(new MyGLWidget)
{
    squaresize=40;
    ui->setupUi(this);
    glwidgetlayout=new QHBoxLayout(ui->frame->widget());
    ui->graphicview->setScene(square);
    square->SetCube(*cube);
    myglwidget->SetCube(*cube);
    myglwidget->RebuildCube();
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
    square->DisplayExpand();
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


void ViewScene::on_savecube_clicked()
{
    QString Filename = QFileDialog::getSaveFileName(
                this,
                tr("保存文件至"),
                "",
                tr("*.txt")
                );
    if(Filename.isEmpty())return;
    else
    {
        QFile outfile;
        outfile.setFileName(Filename);
        outfile.open(QIODevice::WriteOnly);
        QDataStream ostream(&outfile);
        ostream<<cube->getcubevec();
        outfile.close();
        QMessageBox::information(NULL,tr("该立方体已经保存至"),Filename);
    }
}




void ViewScene::on_readcube_clicked()
{
    QString Filename = QFileDialog::getOpenFileName(
                this,
                tr("打开存档文件"),
                "",
                tr("*.txt"));
    if(Filename.isEmpty()) return;
    else
    {
        QFile infile;
        infile.setFileName(Filename);
        infile.open(QIODevice::ReadOnly);
        QDataStream istream(&infile);
        QVector<QVector<QVector<int>>> tempvec;
        istream>>tempvec;
        infile.close();
        cube->SetCubevec(tempvec);
        myglwidget->SetCube(*cube);
        square->SetCube(*cube);
        myglwidget->RebuildCube();
        square->DisplayExpand();

    }
}

void ViewScene::reinitialize()
{
    cube->rebuild();
    myglwidget->SetCube(*cube);
    square->SetCube(*cube);
    myglwidget->RebuildCube();
    square->DisplayExpand();
}
