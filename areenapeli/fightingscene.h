#ifndef FIGHTINGSCENE_H
#define FIGHTINGSCENE_H

#include <QWidget>
#include <QtQuickWidgets/QQuickWidget>
#include "map.h"
#include "arenateam.h"
#include <QStringListModel>

namespace Ui {
class FightingScene;
}

class FightingScene : public QWidget
{
    Q_OBJECT

public:
    explicit FightingScene(ArenaTeam *my_team, ArenaTeam *enemy_team, QWidget *parent = 0);
    ~FightingScene();
    bool initScene(Map* mapmodel);

public slots:
    void updateLog(QString msg);
    void updateMemberScreen(std::shared_ptr<ArenaMember> pleb);
    void endGame(ArenaTeam *winner);

private slots:

signals:
    void battleEnded();

private:
    Ui::FightingScene *ui;
    QStringListModel* logModel;
    QStringList log;
    Controller* control;
    Map* mapmodel;
};

#endif // FIGHTINGSCENE_H
