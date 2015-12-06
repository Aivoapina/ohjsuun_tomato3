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
    myteam_->set_name("MEIDÄN TIIMI");

    for( int i = 0; i < 5; i ++ ){
        ArenaTeam *aiteam = new ArenaTeam(i);
        aiTeams_.append(aiteam);
    }

    arvoOtteluohjelma();

    ui->rahaLabel->setText(QString::number(myteam_->get_raha()));

    ui->pleb1->setFrameStyle(QFrame::NoFrame);
    ui->pleb2->setFrameStyle(QFrame::NoFrame);
    ui->pleb3->setFrameStyle(QFrame::NoFrame);
    ui->pleb4->setFrameStyle(QFrame::NoFrame);


    connect(myteam_, SIGNAL(tiedot_muuttunut()), this, SLOT(refresh_plebs()));
    connect(ui->pleb1, SIGNAL(clicked()), this, SLOT(pleb1_selected()));
    connect(ui->pleb2, SIGNAL(clicked()), this, SLOT(pleb2_selected()));
    connect(ui->pleb3, SIGNAL(clicked()), this, SLOT(pleb3_selected()));
    connect(ui->pleb4, SIGNAL(clicked()), this, SLOT(pleb4_selected()));



}
MainWindow::~MainWindow(){
    delete ui;
}

void MainWindow::arvoOtteluohjelma()
{
    for( ArenaTeam * t : aiTeams_ ){
        QList<ArenaTeam*> lisattava;
        lisattava.push_back(t);
        lisattava.push_back(myteam_);
        otteluohjelma.push_back(lisattava);
    }
    QList<ArenaTeam*> arvottavat{aiTeams_};
    for( ArenaTeam * t1: aiTeams_ ){
        arvottavat.pop_front();
        for( ArenaTeam * t2 : arvottavat ){
            QList<ArenaTeam*> lisattava;
            lisattava.push_back(t1);
            lisattava.push_back(t2);
            otteluohjelma.push_back(lisattava);
        }
    }
    std::random_shuffle(otteluohjelma.begin(), otteluohjelma.end());

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
        plebRuutu *w = new plebRuutu(myteam_, myteam_->getPlebs()[0], ui->pleb1);
        w->show();
        plebRuutu *w2 = new plebRuutu(myteam_,myteam_->getPlebs()[1], ui->pleb2);
        w2->show();
        plebRuutu *w3 = new plebRuutu(myteam_,myteam_->getPlebs()[2], ui->pleb3);
        w3->show();
        plebRuutu *w4 = new plebRuutu(myteam_,myteam_->getPlebs()[3], ui->pleb4);
        w4->show();
    }
    else if( myteam_->getPlebs().size() == 3 ){
        plebRuutu *w = new plebRuutu(myteam_,myteam_->getPlebs()[0], ui->pleb1);
        w->show();
        plebRuutu *w2 = new plebRuutu(myteam_,myteam_->getPlebs()[1], ui->pleb2);
        w2->show();
        plebRuutu *w3 = new plebRuutu(myteam_,myteam_->getPlebs()[2], ui->pleb3);
        w3->show();
    }
    else if( myteam_->getPlebs().size() == 2 ){
        plebRuutu *w = new plebRuutu(myteam_,myteam_->getPlebs()[0], ui->pleb1);
        w->show();
        plebRuutu *w2 = new plebRuutu(myteam_,myteam_->getPlebs()[1], ui->pleb2);
        w2->show();
    }
    else if( myteam_->getPlebs().size() == 1 ){
        plebRuutu *w = new plebRuutu(myteam_,myteam_->getPlebs()[0], ui->pleb1);
        w->show();
    }

}

void MainWindow::on_lintulaButton_clicked()
{
    for(auto i: ui->keskiWidget->children()){
        delete i;
    }
    lintulaWindow *w = new lintulaWindow(myteam_, ui->keskiWidget);
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
    ui->pleb1->setFrameStyle(QFrame::Box);
    myteam_->select(myteam_->getPlebs()[0]);
    ui->pleb2->setFrameStyle(QFrame::NoFrame);
    ui->pleb3->setFrameStyle(QFrame::NoFrame);
    ui->pleb4->setFrameStyle(QFrame::NoFrame);
}

void MainWindow::pleb2_selected()
{
    ui->pleb2->setFrameStyle(QFrame::Box);
    myteam_->select(myteam_->getPlebs()[1]);
    ui->pleb1->setFrameStyle(QFrame::NoFrame);
    ui->pleb3->setFrameStyle(QFrame::NoFrame);
    ui->pleb4->setFrameStyle(QFrame::NoFrame);
}

void MainWindow::pleb3_selected()
{
    ui->pleb3->setFrameStyle(QFrame::Box);
    myteam_->select(myteam_->getPlebs()[2]);
    ui->pleb2->setFrameStyle(QFrame::NoFrame);
    ui->pleb1->setFrameStyle(QFrame::NoFrame);
    ui->pleb4->setFrameStyle(QFrame::NoFrame);
}

void MainWindow::pleb4_selected()
{
    ui->pleb4->setFrameStyle(QFrame::Box);
    myteam_->select(myteam_->getPlebs()[3]);
    ui->pleb2->setFrameStyle(QFrame::NoFrame);
    ui->pleb3->setFrameStyle(QFrame::NoFrame);
    ui->pleb1->setFrameStyle(QFrame::NoFrame);
}



void MainWindow::on_startGame_clicked()
{
    ArenaTeam *AIteam = new ArenaTeam(0);
    FightingScene *window = new FightingScene(myteam_, AIteam, 0);
    hide();
    connect(window, SIGNAL(battleEnded()), this, SLOT(show()));
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

void MainWindow::on_sarjaButton_clicked()
{
    SarjataulukkoScene * w = new SarjataulukkoScene(myteam_, aiTeams_, otteluohjelma);
    w->show();
}
