#include "firstscene.h"

FirstScene::FirstScene(QWidget *parent)
    : QWidget{parent},
      cube(new Cube()),
      myglwidget(new MyGLWidget()),
      square(new Square),
      mainlayout(new QHBoxLayout(this)),
      leftlayout(new QGridLayout()),
      rightlayout(new QGridLayout()),
      RebuildCube(new QPushButton("重新生成立方体")),
      ResetRot(new QPushButton("重置旋转角度")),
      DisplayThreeviews(new QPushButton("显示交互三视图")),
      DisplayExpand(new QPushButton("显示展开图")),
      BuildFromView(new QPushButton("从三视图生成立方体")),
      graphicview(new QGraphicsView())
{
    mainlayout->addLayout(leftlayout);
    mainlayout->addLayout(rightlayout);
    mainlayout->setStretchFactor(leftlayout,1);
    mainlayout->setStretchFactor(rightlayout,1);
    leftlayout->addWidget(myglwidget,0,0,8,8);

    leftlayout->addWidget(RebuildCube,8,0,4,4);
    leftlayout->addWidget(ResetRot,8,3,4,4);
    leftlayout->addWidget(DisplayThreeviews,12,0,4,4);
    leftlayout->addWidget(DisplayExpand,12,3,4,4);
    leftlayout->addWidget(BuildFromView,16,0,4,8);
    square->SetCube(*cube);
    myglwidget->SetCube(*cube);
    graphicview->setScene(square);
    rightlayout->addWidget(graphicview);
    connect(RebuildCube,&QPushButton::clicked,this,&FirstScene::rebuildcube);
    connect(ResetRot,&QPushButton::clicked,this,&FirstScene::resetRotate);
    connect(DisplayThreeviews,&QPushButton::clicked,this,&FirstScene::displayThreeviews);
    connect(DisplayExpand,&QPushButton::clicked,this,&FirstScene::displayExpand);
    connect(BuildFromView,&QPushButton::clicked,this,&FirstScene::buildFromThreeview);
    square->DisplayExpand();
}


void FirstScene::rebuildcube()
{
    cube->rebuild();
    myglwidget->SetCube(*cube);
    square->SetCube(*cube);
    myglwidget->RebuildCube();
    square->UpdateSquare();
}

void FirstScene::resetRotate()
{
    this->myglwidget->resetRotate();
}

void FirstScene::displayThreeviews()
{
    this->square->DisplayThreeviews();
}
void  FirstScene::buildFromThreeview()
{
    cube = new Cube(this->square->OutputCube());
    square->SetCube(*cube);
    myglwidget->SetCube(*cube);
    myglwidget->RebuildCube();

}

void  FirstScene::displayExpand()
{
    square->DisplayExpand();
}


