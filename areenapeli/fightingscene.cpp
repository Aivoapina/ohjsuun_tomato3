#include "fightingscene.h"
#include "ui_fightingscene.h"

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
