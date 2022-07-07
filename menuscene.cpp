#include "menuscene.h"
#include "ui_menuscene.h"

MenuScene::MenuScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuScene)
{
    ui->setupUi(this);
    ui->piclabel->setPixmap(QPixmap(":/pic/Somamap.png"));
}

MenuScene::~MenuScene()
{
    delete ui;
}

void MenuScene::on_StartMode2_clicked()
{
    emit start2();
}


void MenuScene::on_StartMode1_clicked()
{
    emit start1();
}




void MenuScene::on_ExitButton_clicked()
{
    QMessageBox message;
    message.setInformativeText("确定要退出游戏吗");
    auto exitbutton = message.addButton("确定退出",QMessageBox::YesRole);
    auto cancelbutton = message.addButton("取消",QMessageBox::NoRole);
    message.exec();
    if(message.clickedButton()==exitbutton)
    {
        emit exit();
    }
    else if(message.clickedButton()==cancelbutton)
    {

    }
}


void MenuScene::on_RankScene_clicked()
{
    emit rankscene();
}


void MenuScene::on_spinBox_valueChanged(int arg1)
{
    N = arg1;
}

