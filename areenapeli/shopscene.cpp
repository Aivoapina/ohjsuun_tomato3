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

    Shopobject alien;
    QList<Shopobject> list_shopobjects;
    list_shopobjects = alien.refreshresults();
    ui->treeWidget->setColumnCount(4);
    unsigned int a;
    a = alien.countobjects(list_shopobjects);
    for (unsigned int i=0; i<a; i++) {
        QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
        itm->setText(0,list_shopobjects.at(i).r_name());
        itm->setText(1,list_shopobjects.at(i).r_price());
        itm->setText(2,list_shopobjects.at(i).r_damin());
        itm->setText(3,list_shopobjects.at(i).r_damout());
        itm->setData(4,2,list_shopobjects.at(i).toQString());

    }
    ui->label_7->setText("Weapon");
    ui->label_8->setText("Defence");

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
    //if ui->treeWidget->
    //valittu objecti palautuu tähän.
    //objektin arvot lisätään
    qDebug() << ui->treeWidget->currentItem()->data(4,2).toString();

    myteam_->return_selected()->osta_ase(ui->treeWidget->currentItem()->data(4,2).toString());
    emit tavara_ostettu();
    //std::shared_ptr<ArenaMember> selection_;

}
