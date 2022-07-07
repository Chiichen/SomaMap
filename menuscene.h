#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <QWidget>
#include"global.h"
namespace Ui {
class MenuScene;
}

class MenuScene : public QWidget
{
    Q_OBJECT

public:
    explicit MenuScene(QWidget *parent = nullptr);
    ~MenuScene();
signals:
    void start1();
    void start2();
    void start3();
    void rankscene();
    void exit();
private slots:
    void on_StartMode2_clicked();

    void on_StartMode1_clicked();

    void on_ExitButton_clicked();

    void on_RankScene_clicked();

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MenuScene *ui;
};

#endif // MENUSCENE_H
