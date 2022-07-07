QT       += core gui
QT += openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    animatedwidget.cpp \
    cube.cpp \
    figuremate.cpp \
    gamescene.cpp \
    global.cpp \
    grandsquare.cpp \
    keepratiowidget.cpp \
    loadingscene.cpp \
    main.cpp \
    mainwindow.cpp \
    menuscene.cpp \
    myglwidget.cpp \
    rankitem.cpp \
    rankscene.cpp \
    rankwidget.cpp \
    square.cpp \
    viewscene.cpp \
    welcomescene.cpp

HEADERS += \
    animatedwidget.h \
    cube.h \
    figuremate.h \
    gamescene.h \
    global.h \
    grandsquare.h \
    keepratiowidget.h \
    loadingscene.h \
    mainwindow.h \
    menuscene.h \
    myglwidget.h \
    rankitem.h \
    rankscene.h \
    rankwidget.h \
    square.h \
    viewscene.h \
    welcomescene.h

FORMS += \
    gamescene.ui \
    loadingscene.ui \
    mainwindow.ui \
    menuscene.ui \
    rankitem.ui \
    rankscene.ui \
    viewscene.ui \
    welcomescene.ui

TRANSLATIONS += \
    SomaMap_zh_CN.ts
CONFIG += lrelease
CONFIG += embed_translations

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    GLShaders.qrc
