#ifndef VIEWSCENE_H
#define VIEWSCENE_H
#include"global.h"
#include"cube.h"
#include"square.h"
#include"myglwidget.h"


namespace Ui {
class ViewScene;
}

class ViewScene : public QWidget
{
    Q_OBJECT

public:
    explicit ViewScene(QWidget *parent = nullptr);
    ~ViewScene();
    void reinitialize();

private slots:
    void on_BuildFromView_clicked();

    void on_DisplayExpand_clicked();

    void on_DisplayThreeviews_clicked();

    void on_RebuildCubbe_clicked();

    void on_ResetRot_clicked();

    void on_SetViewchoice_valueChanged(int arg1);
    void on_commandLinkButton_clicked();

    void on_savecube_clicked();

    void on_readcube_clicked();

signals:
    void returnmenu();
private:
    Ui::ViewScene *ui;
    Cube* cube;
    Square* square;
    MyGLWidget* myglwidget;
    QHBoxLayout* glwidgetlayout;
};

#endif // VIEWSCENE_H
