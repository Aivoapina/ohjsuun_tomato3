#ifndef FIGHTINGSCENE_H
#define FIGHTINGSCENE_H

#include <QWidget>

namespace Ui {
class FightingScene;
}

class FightingScene : public QWidget
{
    Q_OBJECT

public:
    explicit FightingScene(QWidget *parent = 0);
    ~FightingScene();

private:
    Ui::FightingScene *ui;
};

#endif // FIGHTINGSCENE_H
