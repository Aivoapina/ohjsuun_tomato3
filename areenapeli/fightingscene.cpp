#include "fightingscene.h"
#include "ui_fightingscene.h"
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
    mapmodel = new Map();
    mapmodel->setMapModel(map);

    QQmlContext *asd = ui->qmlView->rootContext();
    asd->setContextProperty("myModel", mapmodel);
    ui->qmlView->setSource(QUrl("qrc:/main.qml"));
    //QQuickItem *item = ui->qmlView->rootObject();
    //connect(ui->qmlView, SIGNAL(qmlSignal(QString, int)), mapmodel, SLOT(moveTo(QString, int)) );

}

FightingScene::~FightingScene()
{
    delete ui;
}

void FightingScene::moveTo(QString direction, int index)
{
    mapmodel->liikuJohonkin(direction, index);
}
