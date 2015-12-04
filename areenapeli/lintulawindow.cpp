#include "lintulawindow.h"
#include "ui_lintulawindow.h"

lintulaWindow::lintulaWindow(ArenaTeam *myteam, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lintulaWindow)
{
    myteam_ = myteam;
    ui->setupUi(this);
    hp_hinta = 250;
    nopeus_hinta = 500;
    voima_hinta = 1000;
    ui->nhl->setText("Hinta: " + QString::number(nopeus_hinta));
    ui->khl->setText("Hinta: " + QString::number(hp_hinta));
    ui->vhl->setText("Hinta: " + QString::number(voima_hinta));
}

lintulaWindow::~lintulaWindow()
{
    delete ui;
}


void lintulaWindow::on_kesavyysButton_clicked()
{
    if( myteam_->return_selected() == nullptr){
        ui->infoLaatikko->setText("Valitse ensin tiiminjäsen, jota haluat kouluttaa.");
        return;
    }
    if( myteam_->get_raha() >= hp_hinta ){
        myteam_->return_selected()->lisaa_maxhp();
        myteam_->lisaa_rahaa(-hp_hinta);
        ui->infoLaatikko->setText("HP ostettu!");
    }
    else{
        ui->infoLaatikko->setText("Rahasi eivät riitä!! Vitun köyhät");
        return;
    }
}

void lintulaWindow::on_voimaButton_clicked()
{

    if( myteam_->return_selected() == nullptr){
        ui->infoLaatikko->setText("Valitse ensin tiiminjäsen, jota haluat kouluttaa.");
        return;
    }
    if( myteam_->get_raha() >= voima_hinta ){
        myteam_->return_selected()->lisaa_power();
        myteam_->lisaa_rahaa(-voima_hinta);
        ui->infoLaatikko->setText("Voimaa ostettu!");
    }
    else{
        ui->infoLaatikko->setText("Rahasi eivät riitä!! Vitun köyhät");
        return;
    }
}

void lintulaWindow::on_nopeusButton_clicked()
{
    if( myteam_->return_selected() == nullptr){
        ui->infoLaatikko->setText("Valitse ensin tiiminjäsen, jota haluat kouluttaa.");
        return;
    }
    if( myteam_->get_raha() >= nopeus_hinta ){
        myteam_->return_selected()->lisaa_nopeus();
        myteam_->lisaa_rahaa(-nopeus_hinta);
        ui->infoLaatikko->setText("Nopeutta ostettu!");
    }
    else{
        ui->infoLaatikko->setText("Rahasi eivät riitä!! Vitun köyhät");
        return;
    }
}
