#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "fightingscene.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent),
  ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}
MainWindow::~MainWindow(){
    delete ui;
}


void MainWindow::on_exitGame_clicked()
{
    close();
}

void MainWindow::on_startGame_clicked()
{
    FightingScene *window = new FightingScene();
    window->show();
    close();
}
