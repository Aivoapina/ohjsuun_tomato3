#include "fightingscene.h"
#include "ui_fightingscene.h"
#include <QQuickView>
#include <QString>
#include <QQmlContext>
#include "tile.h"
#include "map.h"

FightingScene::FightingScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightingScene)
{
    ui->setupUi(this);
    QList<Tile> map;
    QString hero = "assets/bullmentula_ingame.png";
    QString location = "assets/grass_texture.jpg";

    for(int i = 0; i < 160; i++){
        if ( i == 5 ){
            map.append( Tile( hero, location ) );
            continue;
        }
        map.append( Tile( "", location ) );
    }
    Map mapmodel;
    mapmodel.setMapModel(map);

    QQmlContext *asd = ui->qmlView->rootContext();
    asd->setContextProperty("myModel", &mapmodel);
    ui->qmlView->setSource(QUrl("qrc:/main.qml"));

}

FightingScene::~FightingScene()
{
    delete ui;
}
