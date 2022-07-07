#ifndef LOADINGSCENE_H
#define LOADINGSCENE_H

#include <QWidget>

namespace Ui {
class LoadingScene;
}

class LoadingScene : public QWidget
{
    Q_OBJECT

public:
    explicit LoadingScene(QWidget *parent = nullptr);
    ~LoadingScene();

private:
    Ui::LoadingScene *ui;
};

#endif // LOADINGSCENE_H
