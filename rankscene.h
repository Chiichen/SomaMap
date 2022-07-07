#ifndef RANKSCENE_H
#define RANKSCENE_H

#include <QWidget>

namespace Ui {
class RankScene;
}

class RankScene : public QWidget
{
    Q_OBJECT

public:
    explicit RankScene(QWidget *parent = nullptr);
    ~RankScene();
signals:
    void returnmenu();
public slots:
        void insertrank(QString name,int score,QString level);
private slots:
    void on_commandLinkButton_clicked();

private:
    Ui::RankScene *ui;
};

#endif // RANKSCENE_H
