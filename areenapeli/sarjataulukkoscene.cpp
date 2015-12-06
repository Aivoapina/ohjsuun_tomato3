#include "sarjataulukkoscene.h"
#include "ui_sarjataulukkoscene.h"
#include <QDebug>

SarjataulukkoScene::SarjataulukkoScene(ArenaTeam *myteam, QList<ArenaTeam *> aiteams, QList<QList<ArenaTeam*>> ohjelma,QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SarjataulukkoScene)
{

    ui->setupUi(this);
    for( auto i : ohjelma){
        qDebug() << i[0]->r_nimi()+"vs"+i[1]->r_nimi();
        QListWidgetItem *itm= new QListWidgetItem();
        itm->setText(i[0]->r_nimi()+"vs"+i[1]->r_nimi());
        ui->ohjelmaWidget->addItem(itm);
    }

    QMap<QString, int> sarjataulukko;
    sarjataulukko[myteam->r_nimi()] = myteam->r_voitot();
    for( auto i: aiteams ){
        sarjataulukko[i->r_nimi()] = i->r_voitot();
    }


    for( auto i : sarjataulukko.toStdMap() ){
        QListWidgetItem *itm= new QListWidgetItem();
        itm->setText(i.first + "\t\tVoittoja: " + QString::number(i.second));
        ui->taulukkoWidget->addItem(itm);
    }
}

SarjataulukkoScene::~SarjataulukkoScene()
{
    delete ui;
}
