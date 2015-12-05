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

    logModel = new QStringListModel(this);
    logModel->setStringList(log);
    ui->logList->setModel(logModel);
    ui->logList->setEditTriggers(QAbstractItemView::NoEditTriggers);

    mapmodel = new Map();
    connect(mapmodel, SIGNAL(memberMoved(QString, std::shared_ptr<ArenaMember>)) ,this, SLOT(updateLog(QString,std::shared_ptr<ArenaMember>)));
    control = mapmodel->startFight(my_team, enemy_team);
    ui->qmlView->rootContext()->setContextProperty("myModel", mapmodel);
    ui->qmlView->setSource(QUrl("qrc:/main.qml"));



}

FightingScene::~FightingScene()
{
    delete ui;
}

void FightingScene::updateLog(QString dir, std::shared_ptr<ArenaMember> pleb)
{
    log.push_front( pleb->r_nimi() + " liikkui " + dir);
    logModel->setStringList(log);

}
