#include "levelscene.h"
#include "ui_levelscene.h"

LevelScene::LevelScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LevelScene)
{
    ui->setupUi(this);
}

LevelScene::~LevelScene()
{
    delete ui;
}
