#include "plebruutu.h"
#include "ui_plebruutu.h"
#include <QDebug>

plebRuutu::plebRuutu(ArenaTeam* tiimi, std::shared_ptr<ArenaMember> pleb, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::plebRuutu)
{
    ui->setupUi(this);
    team = tiimi;
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

void plebRuutu::on_aseLabel_clicked()
{
    if( pleb_->r_ase() == nullptr ){
        return;
    }
    else{
        int myyntihinta{pleb_->r_ase()->r_price().toInt()};
        QString viesti("Haluatko varmasti myydä aseesi? Saat " + pleb_->r_ase()->r_price() + "g takaisin." );
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Olet myymässä aseesi", viesti, QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            // myy ase
            pleb_->osta_ase("myyty");
            team->lisaa_rahaa(myyntihinta);
        }
    }
    // haluatko myydä aseesi????
}

void plebRuutu::on_panssariLabel_clicked()
{
    // haluatko myydä
    if( pleb_->r_panssari() == nullptr ){
        return;
    }
    else{
        int myyntihinta{pleb_->r_panssari()->r_price().toInt()};
        QString viesti("Haluatko varmasti myydä panssarisi? Saat " + pleb_->r_panssari()->r_price() + "g takaisin." );
        QMessageBox::StandardButton reply;
        reply = QMessageBox::question(this, "Olet myymässä panssarisi", viesti, QMessageBox::Yes|QMessageBox::No);
        if (reply == QMessageBox::Yes) {
            // myy ase
            pleb_->osta_armor("myyty");
            team->lisaa_rahaa(myyntihinta);
        }
    }
}
