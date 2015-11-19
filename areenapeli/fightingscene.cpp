#include "fightingscene.h"
#include "ui_fightingscene.h"
#include "arenateam.h"
#include <QString>
#include <QQmlContext>
#include <QDebug>
#include "tile.h"
#include "map.h"

FightingScene::FightingScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightingScene)
{
    ui->setupUi(this);

}

FightingScene::~FightingScene()
{
    delete ui;
}

bool FightingScene::initFight(ArenaTeam *ownTeam, ArenaTeam *enemyTeam)
{
    QList<Tile> map;
    QString location = "assets/grass_texture.jpg";
    int j = 0;
    for(int i = 0; i < 160; i++){
        if ( i > 2 and i < 7 ){
            if ( j < enemyTeam->getPlebs().size() ){
                map.append( Tile( enemyTeam->getPlebs().at(j), location, true ) );
                j++;
                continue;
            } else if( i == 6 ){
                j = 0;
            }
        }
        if ( i > 152 and i < 157 ){
            if ( j < ownTeam->getPlebs().size() ){
                map.append( Tile( ownTeam->getPlebs().at(j), location, true ) );
                j++;
                continue;
            }
        }
        map.append( Tile( nullptr, location ) );
    }
    mapmodel = new Map();
    mapmodel->setMapModel(map);

    ui->qmlView->rootContext()->setContextProperty("myModel", mapmodel);
    ui->qmlView->setSource(QUrl("qrc:/main.qml"));

    return true;
}

void FightingScene::moveTo(QString direction, int index)
{
    mapmodel->liikuJohonkin(direction, index);
}
