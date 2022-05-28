#include "mainwindow.h"
#include <QVBoxLayout>
#include <QApplication>
#include <QLocale>
#include <QTranslator>
int main( int argc, char **argv )
{
  QApplication a( argc, argv );
  MainWindow w;
  w.show();
  return a.exec();
}

