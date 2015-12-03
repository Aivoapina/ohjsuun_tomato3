#include "plebruutu.h"
#include "ui_plebruutu.h"

plebRuutu::plebRuutu(std::shared_ptr<ArenaMember> pleb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::plebRuutu)
{
    ui->setupUi(this);
    pleb_ = pleb;
    paivita();


}


plebRuutu::~plebRuutu()
{
    delete ui;
}

void plebRuutu::paivita()
{
    ui->nimiLabel->setText("Nimi: " +pleb_->r_nimi());
    QPixmap icon(":assets/" + pleb_->r_rotu()+".png");
    ui->Kuva->setPixmap(icon);
    ui->powerLabel->setText("Power: " + QString::number(pleb_->r_power()));
    ui->hpLabel->setText("HP: " + QString::number(pleb_->r_current_hp()));
    ui->armorLabel->setText("Armor:" + QString::number(pleb_->r_armor()));
    ui->rotuLabel->setText("Rotu: " + pleb_->r_rotu());
    ui->nopeusLabel->setText("Nopeus: " + QString::number(pleb_->r_nopeus()));
    if( pleb_->r_panssari() == nullptr ){
        ui->panssariLabel->setText("Ei panssaria");
    }
    else{
        ui->panssariLabel->setText(pleb_->r_panssari()->r_name());
    }
    if( pleb_->r_ase() == nullptr ){
        ui->aseLabel->setText("Ei asetta");
    }
    else{
        ui->aseLabel->setText(pleb_->r_ase()->r_name());
    }
}

void plebRuutu::mousePressEvent(QMouseEvent *e)
{
    e->ignore();
}
