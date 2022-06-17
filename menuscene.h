#ifndef MENUSCENE_H
#define MENUSCENE_H

#include <QWidget>

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
private slots:
    void on_StartMode2_clicked();

    void on_StartMode1_clicked();

private:
    Ui::MenuScene *ui;
};

#endif // MENUSCENE_H
