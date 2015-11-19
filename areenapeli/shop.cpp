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

using namespace std;




Shopobject::Shopobject()
{

}

Shopobject::~Shopobject(){}

vector<shobject> Shopobject::refreshresults(){
    vector<shobject> list_shopobjects;

    QFile fileobject("objectlist.txt");

    if ( fileobject.open(QIODevice::ReadOnly) ) {
        QTextStream stream(&fileobject);
        while( !stream.atEnd() ){
            QString row{stream.readLine()};
            qDebug() << row;
            QStringList tokens{row.split(';')};
            x.name = tokens.at(0);
            x.price = (tokens.at(1));
            x.damain = (tokens.at(2));
            x.damout = (tokens.at(3));
            list_shopobjects.push_back(x);

        }

    }
    //else {return;}

    fileobject.close();
    cout << "Reading complete without errors: "<< endl;

    return list_shopobjects;
}

unsigned int Shopobject::countobjects(vector<shobject> list_shopobjects)
{
    unsigned int a;
    a = list_shopobjects.size();
    return a;
}

//mitas kaikkea tarvitaan
//taistelijat (rotu, arvo,
