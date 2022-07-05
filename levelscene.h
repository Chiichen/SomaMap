#ifndef LEVELSCENE_H
#define LEVELSCENE_H

#include <QWidget>

namespace Ui {
class LevelScene;
}

class LevelScene : public QWidget
{
    Q_OBJECT

public:
    explicit LevelScene(QWidget *parent = nullptr);
    ~LevelScene();

private:
    Ui::LevelScene *ui;
};

#endif // LEVELSCENE_H
