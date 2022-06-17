#ifndef GAMESCENE_H
#define GAMESCENE_H

#include <QWidget>

namespace Ui {
class GameScene;
}

class GameScene : public QWidget
{
    Q_OBJECT

public:
    explicit GameScene(QWidget *parent = nullptr);
    ~GameScene();
signals:
    void returnmenu();
private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::GameScene *ui;
};

#endif // GAMESCENE_H
