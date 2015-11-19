#ifndef FIGHTINGSCENE_H
#define FIGHTINGSCENE_H

#include <QWidget>
#include <QtQuickWidgets/QQuickWidget>
#include "map.h"
namespace Ui {
class FightingScene;
}

class FightingScene : public QWidget
{
    Q_OBJECT

public:
    explicit FightingScene(QWidget *parent = 0);
    ~FightingScene();

public slots:
    void moveTo(QString direction, int index);


private:
    Map* mapmodel;
    Ui::FightingScene *ui;
    QQuickWidget *qmlView;
};

#endif // FIGHTINGSCENE_H
