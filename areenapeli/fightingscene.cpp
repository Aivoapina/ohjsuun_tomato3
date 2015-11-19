#include "fightingscene.h"
#include "ui_fightingscene.h"
#include "map.h"
#include <QQuickView>
#include <QGuiApplication>
#include <qqmlengine.h>
#include <qqmlcontext.h>
#include <qqml.h>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>
#include <QDebug>

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
