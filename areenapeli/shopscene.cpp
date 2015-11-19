#include "shopscene.h"
#include "ui_shopscene.h"
#include "shop.h"
#include "mainwindow.h"
#include <QtCore>
#include <QtGui>

shopscene::shopscene(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::shopscene)
{
    ui->setupUi(this);

    Shopobject alien;
    vector<shobject> list_shopobjects;
    list_shopobjects = alien.refreshresults();
    ui->treeWidget->setColumnCount(4);
    unsigned int a;
    a = alien.countobjects(list_shopobjects);
    for (unsigned int i=0; i<a; i++) {
        QTreeWidgetItem *itm = new QTreeWidgetItem(ui->treeWidget);
        itm->setText(0,list_shopobjects.at(i).name);
        itm->setText(1,list_shopobjects.at(i).price);
        itm->setText(2,list_shopobjects.at(i).damain);
        itm->setText(3,list_shopobjects.at(i).damout);

    }
}

shopscene::~shopscene()
{
    delete ui;
}



