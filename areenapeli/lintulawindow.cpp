#include "lintulawindow.h"
#include "ui_lintulawindow.h"

lintulaWindow::lintulaWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::lintulaWindow)
{
    ui->setupUi(this);
}

lintulaWindow::~lintulaWindow()
{
    delete ui;
}

void lintulaWindow::on_pushButton_clicked()
{
   emit lisaa_hp();
}


void lintulaWindow::on_pushButton_2_clicked()
{
    emit lisaa_power();
}
