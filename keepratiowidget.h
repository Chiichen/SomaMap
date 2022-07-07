#ifndef KEEPRATIOWIDGET_H
#define KEEPRATIOWIDGET_H
#include <QFrame>

class KeepRatioWidget : public QFrame
{
    Q_OBJECT

public:
    KeepRatioWidget(QWidget *parent = 0);

    void setRatio(int width, int height);
    QWidget* widget();

protected:
    virtual void resizeEvent(QResizeEvent *event);

private:
    int width_ratio_=9;
    int height_ratio_=16;
    QWidget* center_widget_;
};

#endif
