#include "fightingscene.h"
#include "ui_fightingscene.h"
#include "arenateam.h"
#include <QString>
#include <QQmlContext>
#include <QDebug>
#include "tile.h"
#include "map.h"

FightingScene::FightingScene(ArenaTeam* my_team, ArenaTeam* enemy_team, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightingScene)
{
    ui->setupUi(this);

    mapmodel = new Map();
    control = mapmodel->startFight(my_team, enemy_team);
    ui->qmlView->rootContext()->setContextProperty("myModel", mapmodel);
    ui->qmlView->setSource(QUrl("qrc:/main.qml"));


}

FightingScene::~FightingScene()
{
    delete ui;
}

void FightingScene::on_endTurn_clicked()
{
    control->endTurn();
}
