#include "menuscene.h"

MenuScene::MenuScene(QWidget *parent)
    : QWidget{parent},
      Startmode1(new QPushButton),
      Startmode2(new QPushButton),
      mainlayout(new QVBoxLayout(this))
{
    mainlayout->addWidget(Startmode1);
    mainlayout->addWidget(Startmode2);
    Startmode1->setText("开始游戏");
    connect(Startmode1,&QPushButton::clicked,this,&MenuScene::start1clicked);
    connect(Startmode2,&QPushButton::clicked,this,&MenuScene::start2clicked);

}
void MenuScene::start1clicked()
{
    emit start1();
}
void MenuScene::start2clicked()
{
    emit start2();
}
