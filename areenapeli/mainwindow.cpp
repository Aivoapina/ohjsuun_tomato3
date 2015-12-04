#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fightingscene.h"
#include <QQmlContext>
#include "map.h"
#include <QSignalMapper>
#include <QFrame>
#include "myqframe.h"
#include <QDebug>
#include "shopscene.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
  ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myteam_ = new ArenaTeam();

    ui->rahaLabel->setText(QString::number(myteam_->get_raha()));


    connect(ui->pleb1, SIGNAL(clicked()), this, SLOT(pleb1_selected()));
    connect(ui->pleb2, SIGNAL(clicked()), this, SLOT(pleb2_selected()));
    connect(ui->pleb3, SIGNAL(clicked()), this, SLOT(pleb3_selected()));
    connect(ui->pleb4, SIGNAL(clicked()), this, SLOT(pleb4_selected()));


}
MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_exitGame_clicked()
{
    close();
}

void MainWindow::on_kilta_clicked()
{
    for(auto i: ui->keskiWidget->children()){
        delete i;
    }
    kiltahuone *w = new kiltahuone(myteam_, ui->keskiWidget);
    connect(w, SIGNAL(pleb_ostettu()),this, SLOT(refresh_plebs()));
    w->show();
}

void MainWindow::refresh_plebs()
{
    ui->rahaLabel->setText(QString::number(myteam_->get_raha()));
    for(auto i: ui->pleb1->children()){
        delete i;
    }
    for(auto i: ui->pleb2->children()){
        delete i;
    }
    for(auto i: ui->pleb3->children()){
        delete i;
    }
    for(auto i: ui->pleb4->children()){
        delete i;
    }
    if( myteam_->getPlebs().size() == 4 ){
        plebRuutu *w = new plebRuutu(myteam_->getPlebs()[0], ui->pleb1);
        w->show();
        plebRuutu *w2 = new plebRuutu(myteam_->getPlebs()[1], ui->pleb2);
        w2->show();
        plebRuutu *w3 = new plebRuutu(myteam_->getPlebs()[2], ui->pleb3);
        w3->show();
        plebRuutu *w4 = new plebRuutu(myteam_->getPlebs()[3], ui->pleb4);
        w4->show();
    }
    else if( myteam_->getPlebs().size() == 3 ){
        plebRuutu *w = new plebRuutu(myteam_->getPlebs()[0], ui->pleb1);
        w->show();
        plebRuutu *w2 = new plebRuutu(myteam_->getPlebs()[1], ui->pleb2);
        w2->show();
        plebRuutu *w3 = new plebRuutu(myteam_->getPlebs()[2], ui->pleb3);
        w3->show();
    }
    else if( myteam_->getPlebs().size() == 2 ){
        plebRuutu *w = new plebRuutu(myteam_->getPlebs()[0], ui->pleb1);
        w->show();
        plebRuutu *w2 = new plebRuutu(myteam_->getPlebs()[1], ui->pleb2);
        w2->show();
    }
    else if( myteam_->getPlebs().size() == 1 ){
        plebRuutu *w = new plebRuutu(myteam_->getPlebs()[0], ui->pleb1);
        w->show();
    }

}

void MainWindow::on_lintulaButton_clicked()
{
    for(auto i: ui->keskiWidget->children()){
        delete i;
    }
    lintulaWindow *w = new lintulaWindow(ui->keskiWidget);
    connect(w, SIGNAL(lisaa_hp()), this, SLOT(hp_ostettu()));
    connect(w, SIGNAL(lisaa_power()), this, SLOT(power_ostettu()));
    w->show();

}

void MainWindow::hp_ostettu()
{
    if( myteam_->return_selected() == nullptr ){
        return;
    }
    if( myteam_->get_raha() >= 250 ){
        myteam_->lisaa_rahaa(-250);
        ui->rahaLabel->setText(QString::number(myteam_->get_raha()));
        myteam_->return_selected()->lisaa_maxhp();
    }
    refresh_plebs();
}

void MainWindow::power_ostettu()
{
    if( myteam_->return_selected() == nullptr ){
        return;
    }
    if( myteam_->get_raha() >= 1000 ){
        myteam_->lisaa_rahaa(-1000);
        ui->rahaLabel->setText(QString::number(myteam_->get_raha()));
        myteam_->return_selected()->lisaa_power();
    }
    refresh_plebs();
}

void MainWindow::pleb1_selected()
{
    ui->pleb1->setFrameShadow(QFrame::Raised);
    myteam_->select(myteam_->getPlebs()[0]);
    ui->pleb2->setFrameShadow(QFrame::Sunken);
    ui->pleb3->setFrameShadow(QFrame::Sunken);
    ui->pleb4->setFrameShadow(QFrame::Sunken);
}

void MainWindow::pleb2_selected()
{
    ui->pleb2->setFrameShadow(QFrame::Raised);
    myteam_->select(myteam_->getPlebs()[1]);
    ui->pleb1->setFrameShadow(QFrame::Sunken);
    ui->pleb3->setFrameShadow(QFrame::Sunken);
    ui->pleb4->setFrameShadow(QFrame::Sunken);
}

void MainWindow::pleb3_selected()
{
    ui->pleb3->setFrameShadow(QFrame::Raised);
    myteam_->select(myteam_->getPlebs()[2]);
    ui->pleb2->setFrameShadow(QFrame::Sunken);
    ui->pleb1->setFrameShadow(QFrame::Sunken);
    ui->pleb4->setFrameShadow(QFrame::Sunken);
}

void MainWindow::pleb4_selected()
{
    ui->pleb4->setFrameShadow(QFrame::Raised);
    myteam_->select(myteam_->getPlebs()[3]);
    ui->pleb2->setFrameShadow(QFrame::Sunken);
    ui->pleb3->setFrameShadow(QFrame::Sunken);
    ui->pleb1->setFrameShadow(QFrame::Sunken);
}



void MainWindow::on_startGame_clicked()
{
    FightingScene *window = new FightingScene(myteam_, myteam_, ui->keskiWidget);
    window->show();
}

void MainWindow::on_pushButton_clicked()
{
    for(auto i: ui->keskiWidget->children()){
        delete i;
    }

    shopscene *window = new shopscene(myteam_, ui->keskiWidget);
    connect(window, SIGNAL(tavara_ostettu()),this, SLOT(refresh_plebs()));
    window->show();
}
