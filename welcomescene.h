#ifndef WELCOMESCENE_H
#define WELCOMESCENE_H
#include"global.h"
#include"animatedwidget.h"

namespace Ui {
class WelcomeScene;
}

class WelcomeScene : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeScene(QWidget *parent = nullptr);
    ~WelcomeScene();
signals:
    void startgame();
private slots:
    void on_startgame_clicked();

private:
    Ui::WelcomeScene *ui;
};

#endif // WELCOMESCENE_H
