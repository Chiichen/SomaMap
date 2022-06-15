#ifndef MENUSCENE_H
#define MENUSCENE_H
#include"global.h"


class MenuScene : public QWidget
{
    Q_OBJECT
public:
    explicit MenuScene(QWidget *parent = nullptr);

private:
    QPushButton* Startmode1;
    QPushButton* Startmode2;
    QVBoxLayout* mainlayout;


private slots:
    void start1clicked();
    void start2clicked();
signals:
    void start1();
    void start2();
};

#endif // MENUSCENE_H
