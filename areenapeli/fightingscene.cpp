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
    QString name = "yee";
    QString location = "black";

    for(int i = 0; i < 160; i++){
        if ( !(i % 5) ){
            map.append( Tile( name, "white" ) );
            continue;
        }
        map.append( Tile( name, location ) );
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
