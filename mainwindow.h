#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include"myglwidget.h"
#include"square.h"
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
   void on_Rebuild_clicked();

   void on_build2_clicked();

   void on_resetrotate_clicked();

private:
    Ui::MainWindow *ui;
    Square* square;
    Cube cube;
};
#endif // MAINWINDOW_H
