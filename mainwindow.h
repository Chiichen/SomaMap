#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"global.h"
#include"menuscene.h"
#include"firstscene.h"
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

private:
    Ui::MainWindow *ui;
    QHBoxLayout* mainlayout;
    MenuScene* menuscene;
    FirstScene* firstscene;


};
#endif // MAINWINDOW_H
