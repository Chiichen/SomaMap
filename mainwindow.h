#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"global.h"
#include"menuscene.h"
#include"viewscene.h"
#include"gamescene.h"
#include"levelscene.h"
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void start1();
    void start2();
    void returnmenu();
private:
    Ui::MainWindow *ui;
    QHBoxLayout* mainlayout;
    MenuScene* menuscene;
    ViewScene* viewscene;
    GameScene* gamescene;
    LevelScene* levelscene;
};
#endif // MAINWINDOW_H
