#include "fightingscene.h"
#include "ui_fightingscene.h"
#include <QQuickView>

FightingScene::FightingScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightingScene)
{
    ui->setupUi(this);
    ui->qmlView->setSource(QUrl("qrc:/main.qml"));


}

FightingScene::~FightingScene()
{
    delete ui;
}
