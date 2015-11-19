#include "fightingscene.h"
#include "ui_fightingscene.h"
#include "map.h"
#include <QQuickView>
<<<<<<< HEAD
#include <QGuiApplication>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <QDebug>
=======
#include <QString>
#include <QQmlContext>
#include "tile.h"
#include "map.h"
>>>>>>> 90f5f233c323c6cd88be95d062815dabd2289611

FightingScene::FightingScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightingScene)
{
    ui->setupUi(this);
<<<<<<< HEAD
=======
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

>>>>>>> 90f5f233c323c6cd88be95d062815dabd2289611
}

FightingScene::~FightingScene()
{
    delete ui;
}
