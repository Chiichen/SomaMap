#ifndef ANIMATEDWIDGET_H
#define ANIMATEDWIDGET_H
#include"global.h"

class AnimatedWidget:public QObject
{
    Q_OBJECT
public:
   static void showHintLabel(QWidget *parent,
                              QString strText, int time = 2000,
                              QString strFontSize = "32px",
                              QString strColor = "#202020",
                              QString strBgColor = "#ffffff");


};

#endif // ANIMATEDWIDGET_H
