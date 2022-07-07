#include "welcomescene.h"
#include "ui_welcomescene.h"

WelcomeScene::WelcomeScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeScene)
{
    QFont font("楷体",25);
    ui->setupUi(this);
    ui->label->setFont(font);
    ui->nameedit->setFont(font);
    ui->piclabel->setPixmap(QPixmap(":/pic/Somamap.png"));
}

WelcomeScene::~WelcomeScene()
{
    delete ui;
}

void WelcomeScene::on_startgame_clicked()
{
    if(!ui->nameedit->text().isEmpty())
    {
        username = ui->nameedit->text();
        emit startgame();
    }
    else AnimatedWidget::showHintLabel(this,"请输入用户名");

    return;
}

