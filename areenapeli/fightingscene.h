#ifndef FIGHTINGSCENE_H
#define FIGHTINGSCENE_H

#include <QWidget>
#include <QtQuickWidgets/QQuickWidget>
#include "map.h"
#include "arenateam.h"

namespace Ui {
class FightingScene;
}

class FightingScene : public QWidget
{
    Q_OBJECT

public:
    explicit FightingScene(QWidget *parent = 0);
    ~FightingScene();
    bool initScene(Map* mapmodel);

public slots:


private:
    Ui::FightingScene *ui;
};

#endif // FIGHTINGSCENE_H
