#include "fightingscene.h"
#include "ui_fightingscene.h"
#include "arenateam.h"
#include <QString>
#include <QQmlContext>
#include <QDebug>
#include "tile.h"
#include "map.h"
#include "plebruutu.h"

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
    connect(mapmodel, SIGNAL(somethingHappened(QString)) ,this, SLOT(updateLog(QString)));
    connect(mapmodel, SIGNAL(updateActiveMember(std::shared_ptr<ArenaMember>)), this, SLOT(updateMemberScreen(std::shared_ptr<ArenaMember>)));
    connect(mapmodel, SIGNAL(gameEnded(ArenaTeam*)), this, SLOT(endGame(ArenaTeam*)));
    control = mapmodel->startFight(my_team, enemy_team);
    ui->qmlView->rootContext()->setContextProperty("myModel", mapmodel);
    ui->qmlView->setSource(QUrl("qrc:/main.qml"));

}

FightingScene::~FightingScene()
{
    delete ui;
}

void FightingScene::updateLog(QString msg)
{
    log.push_front( msg );
    logModel->setStringList(log);
}

void FightingScene::updateMemberScreen(std::shared_ptr<ArenaMember> pleb)
{
    for(auto i: ui->frame->children()){
        delete i;
    }
    if (pleb == nullptr){
        return;
    }
    plebRuutu *ruutu = new plebRuutu(pleb, ui->frame);
    ruutu->show();

}

void FightingScene::endGame(ArenaTeam* winner)
{
    QDialog *win = new QDialog(this);
    win->exec();
    emit battleEnded();
    close();
}
