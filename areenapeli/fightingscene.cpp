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

bool FightingScene::initScene(Map *mapmodel)
{
    ui->qmlView->rootContext()->setContextProperty("myModel", mapmodel);
    ui->qmlView->setSource(QUrl("qrc:/main.qml"));

    return true;
}
