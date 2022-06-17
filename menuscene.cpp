#include "menuscene.h"
#include "ui_menuscene.h"

MenuScene::MenuScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuScene)
{
    ui->setupUi(this);
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

