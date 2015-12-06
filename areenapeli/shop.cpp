#include "shop.h"
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <ostream>
#include <iostream>
#include <QString>
#include <QFile>
#include <QDebug>
#include <QTextStream>
#include <QList>

Shopobject::Shopobject()
{

}

Shopobject::Shopobject(QString data){
    QStringList list;
    list = data.split(";");
    x.name = list.at(0);
    x.price = list.at(1);
    x.damain = list.at(2);
    x.damout = list.at(3);
}

Shopobject::~Shopobject(){}

QString Shopobject::r_name() const
{
    return x.name;
}

QString Shopobject::r_price() const
{
    return x.price;
}

QString Shopobject::r_damin() const
{
    return x.damain;
}

QString Shopobject::r_damout() const
{
    return x.damout;
}

QString Shopobject::toQString() const
{
    QString changedstring{""};
    changedstring = x.name+";"+x.price+";"+x.damain+";"+x.damout;
    return changedstring;
}

QList<Shopobject> Shopobject::refreshresults(){
    QList<Shopobject> list_shopobjects;

    QFile fileobject(":/assets/tavaroiden_alustus.txt");

    if ( fileobject.open(QIODevice::ReadOnly) ) {
        QTextStream stream(&fileobject);
        while( !stream.atEnd() ){
            QString row{stream.readLine()};
            Shopobject x(row);
            list_shopobjects.push_back(x);

        }

    }

    fileobject.close();

    return list_shopobjects;
}

unsigned int Shopobject::countobjects(QList<Shopobject> list_shopobjects)
{
    unsigned int a;
    a = list_shopobjects.size();
    return a;
}
