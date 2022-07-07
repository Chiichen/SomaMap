#include "loadingscene.h"
#include "ui_loadingscene.h"

LoadingScene::LoadingScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoadingScene)
{
    ui->setupUi(this);
}

LoadingScene::~LoadingScene()
{
    delete ui;
}
