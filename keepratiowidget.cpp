#include <QResizeEvent>
#include "keepratiowidget.h"

KeepRatioWidget::KeepRatioWidget(QWidget *parent) :
    QFrame(parent)
   , width_ratio_(16)
   , height_ratio_(9)
{
    center_widget_ = new QWidget(this);
    center_widget_->setStyleSheet("background-color:white;");
}

void KeepRatioWidget::setRatio(int width, int height)
{
    width_ratio_ = width;
    height_ratio_ = height;
}

QWidget *KeepRatioWidget::widget()
{
    return center_widget_;
}

void KeepRatioWidget::resizeEvent(QResizeEvent *event)
{
    QSize old_size = event->size();
    QSize new_size = event->size();

    if(new_size.width()<width_ratio_*new_size.height()/height_ratio_){
        //宽度不足，则以宽度来计算
        new_size.setHeight(height_ratio_ * new_size.width() / width_ratio_);
        //竖直方向居中
        center_widget_->move(0,(old_size.height()-new_size.height())/2);
    }
    else {
        //否则以高度来计算
        new_size.setWidth(width_ratio_ * new_size.height() / height_ratio_);
        //水平方向居中
        center_widget_->move((old_size.width()-new_size.width())/2,0);
    }

    center_widget_->resize(new_size);
}
