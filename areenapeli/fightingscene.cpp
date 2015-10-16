#include "fightingscene.h"
#include "ui_fightingscene.h"
#include <QQuickView>

FightingScene::FightingScene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FightingScene)
{
    ui->setupUi(this);
    qmlView = new QQuickWidget;
    qmlView->setSource(QUrl("qrc:/main.qml"));
    qmlView->show();

}

FightingScene::~FightingScene()
{
    delete ui;
}
