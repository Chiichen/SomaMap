#include "animatedwidget.h"

//AnimatedWidget::AnimatedWidget()
//{
//    int i=0;
//}

void AnimatedWidget::showHintLabel(QWidget *parentWin, QString strText,  int time, QString strFontSize, QString strColor, QString strBgColor)
{


    QWidget *widgetPtr = new QWidget();  //为了兼容parent为nullptr时的圆角边框  方法是背景透明 上边叠加圆角控件
    widgetPtr->setWindowFlags(Qt::FramelessWindowHint);    //去除外框
    widgetPtr->setAttribute(Qt::WA_TranslucentBackground); //设置窗体背景透明

    QLabel *pLabel = new QLabel(widgetPtr);    //创建显示标签
    pLabel->setAlignment(Qt::AlignCenter);  //文字居中显示
    pLabel->setStyleSheet(QString("QLabel{background:%1;color:%2;font:%3 SimHei;border-radius:5px;}")
                              .arg(strBgColor).arg(strColor).arg(strFontSize)); //社长标签风格
    pLabel->setText(strText);                   //设置文字内容
    pLabel->adjustSize();
    pLabel->resize(pLabel->size() + QSize(120,120));
    //设置pFrame大小和位置
    widgetPtr->resize(pLabel->size()); //设置大小为label大小
    widgetPtr->move((parentWin->width()-widgetPtr->width())/2   + parentWin->pos().x(),
                 (parentWin->height()-widgetPtr->height())/2 + parentWin->pos().y());
    widgetPtr->show();

    //创建动画，使窗口淡化消失
    QPropertyAnimation *pAnimation = new QPropertyAnimation(widgetPtr,"windowOpacity",parentWin);
    pAnimation->setDuration(time);
    pAnimation->setEasingCurve(QEasingCurve::InCirc);
    pAnimation->setStartValue(1.0);
    pAnimation->setEndValue(0.0);
    pAnimation->start();        //启动动画
    //动画结束后删除创建的资源
    connect(pAnimation,&QPropertyAnimation::finished,[=]{
        delete pAnimation;
        delete widgetPtr;
    });
}
