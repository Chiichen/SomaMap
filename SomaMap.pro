QT       += core gui
QT += openglwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    cube.cpp \
    figuremate.cpp \
    firstscene.cpp \
    gamescene.cpp \
    global.cpp \
    grandsquare.cpp \
    keepratiowidget.cpp \
    main.cpp \
    mainwindow.cpp \
    menuscene.cpp \
    myglwidget.cpp \
    square.cpp \
    viewscene.cpp

HEADERS += \
    cube.h \
    figuremate.h \
    firstscene.h \
    gamescene.h \
    global.h \
    grandsquare.h \
    keepratiowidget.h \
    mainwindow.h \
    menuscene.h \
    myglwidget.h \
    square.h \
    viewscene.h

FORMS += \
    gamescene.ui \
    mainwindow.ui \
    menuscene.ui \
    viewscene.ui

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
