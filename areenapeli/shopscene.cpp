#include "shopscene.h"
#include "ui_shopscene.h"
#include "shop.h"
#include "mainwindow.h"
#include <QtCore>
#include <QtGui>
#include "arenateam.h"
#include "arenamember.h"

shopscene::shopscene(ArenaTeam *myteam, QWidget *parent) :
    QWidget(parent),

    ui(new Ui::shopscene)
{

    myteam_ = myteam;
    ui->setupUi(this);
    aseet = new QTreeWidgetItem(ui->treeWidget);
    aseet->setText(0,"Aseet");
    panssarit = new QTreeWidgetItem(ui->treeWidget);
    panssarit->setText(0,"Panssarit");
    Shopobject alien;
    QList<Shopobject> list_shopobjects;
    list_shopobjects = alien.refreshresults();
    ui->treeWidget->setColumnCount(4);
    ui->treeWidget->setColumnWidth(0,250);
    ui->treeWidget->setColumnWidth(1,60);
    ui->treeWidget->setColumnWidth(2,60);
    ui->treeWidget->setColumnWidth(3,60);


    unsigned int a;
    a = alien.countobjects(list_shopobjects);
    for (unsigned int i=0; i<a; i++) {
        QTreeWidgetItem *itm = new QTreeWidgetItem();
        itm->setText(0,list_shopobjects.at(i).r_name());
        itm->setText(1,list_shopobjects.at(i).r_price());
        itm->setText(2,list_shopobjects.at(i).r_damin());
        itm->setText(3,list_shopobjects.at(i).r_damout());
        itm->setData(4,2,list_shopobjects.at(i).toQString());
        if( list_shopobjects.at(i).r_damin() == "0" ){
            ui->treeWidget->itemAt(0,0)->addChild(itm);
        }
        else{
            ui->treeWidget->itemBelow(ui->treeWidget->itemAt(0,0))->addChild(itm);
        }
    }
    ui->treeWidget->expandAll();

}

shopscene::~shopscene()
{
    delete ui;
}

void shopscene::refresh_plebs()
{

}




void shopscene::on_ButtonBuy_clicked()
{
    if (!ui->treeWidget->currentItem() or ui->treeWidget->currentItem()->data(4,2).toString() == ""){
        ui->infoRuutu->setText("Valitse hahmosi painamalla hahmon ruutua!");
        return;
    }
    qDebug() << ui->treeWidget->currentItem()->data(4,2).toString();
    if (!myteam_->return_selected()){
        ui->infoRuutu->setText("Sinulla ei ole valittuja hahmoja.");
        return;
    }
    if (ui->treeWidget->currentItem()->data(4,2).toString().split(";").at(1).toInt()
            >= myteam_->get_raha()){
        ui->infoRuutu->setText("Sinulla ei ole tarpeeksi rahaa tätä ostosta varten.");
        return;
    }
    if( ui->treeWidget->currentItem()->parent()->text(0) == "Aseet" ){
        if( myteam_->return_selected()->r_ase() == nullptr ){
            myteam_->return_selected()->osta_ase(ui->treeWidget->currentItem()->data(4,2).toString());
            myteam_->lisaa_rahaa(-(ui->treeWidget->currentItem()->data(4,2).toString().split(";").at(1).toInt()));
            emit tavara_ostettu();
        }
        else{
            ui->infoRuutu->clear();
            ui->infoRuutu->setText("Myy ensin vanha aseesi!");
        }
    }
    else if( ui->treeWidget->currentItem()->parent()->text(0) == "Panssarit"){
        if( myteam_->return_selected()->r_panssari() == nullptr ){
            myteam_->return_selected()->osta_armor(ui->treeWidget->currentItem()->data(4,2).toString());
            myteam_->lisaa_rahaa(-(ui->treeWidget->currentItem()->data(4,2).toString().split(";").at(1).toInt()));
            emit tavara_ostettu();
        }
        else{
            ui->infoRuutu->clear();
            ui->infoRuutu->setText("Myy ensin vanha panssarisi!");
        }
    }

}
