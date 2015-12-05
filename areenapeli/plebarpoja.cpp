#include "plebarpoja.h"
#include <QTextStream>
#include <QDebug>

int randI(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

QString laske_hinta(QStringList l){
    return QString::number( l[2].toInt()*2 + l[3].toInt()*2 + l[4].toInt()*2 + l[5].toInt()*2 + l[6].toInt()*2 + 50 );
}

plebArpoja::plebArpoja()
{
    lue_alustus();
}

std::shared_ptr<ArenaMember> plebArpoja::arvoPleb()
{
    QStringList data;
    QString Lisattavan_rotu = rotujen_nimet[randI(0,rotujen_nimet.size()-1)];
    statsit Lisattavan_statsit = rodut[Lisattavan_rotu];
    //rotu
    data.push_back(Lisattavan_rotu);
    //nimi
    data.push_back(Lisattavan_statsit.nimi_mahikset[randI(0, Lisattavan_statsit.nimi_mahikset.size()-1)]);

    QStringList tmp{Lisattavan_statsit.hp_range.split('-')};
    //hp
    data.push_back( QString::number(randI(tmp[0].toInt(), tmp[1].toInt())) );

    tmp = Lisattavan_statsit.voima_range.split('-');
    //voima
    data.push_back( QString::number(randI(tmp[0].toInt(), tmp[1].toInt())) );

    //armor
    data.push_back( Lisattavan_statsit.armor );

    //liike
    data.push_back( Lisattavan_statsit.liike);

    //nopeus
    data.push_back( Lisattavan_statsit.nopeus);

    //hinta
    data.push_back( laske_hinta(data) );

    //ase ja panssari jätetään tyhjiksi
    QString tyhja("");
    data.push_back(tyhja);
    data.push_back(tyhja);

    std::shared_ptr<ArenaMember> arvottu(new ArenaMember(data));
    return arvottu;
}

std::shared_ptr<ArenaMember> plebArpoja::arvoAIPleb(int taso)
{
    QStringList data;
    QString Lisattavan_rotu = rotujen_nimet[randI(0,rotujen_nimet.size()-1)];
    statsit Lisattavan_statsit = rodut[Lisattavan_rotu];
    //rotu
    data.push_back(Lisattavan_rotu);
    //nimi
    data.push_back(Lisattavan_statsit.nimi_mahikset[randI(0, Lisattavan_statsit.nimi_mahikset.size()-1)]);

    QStringList tmp{Lisattavan_statsit.hp_range.split('-')};
    //hp
    data.push_back( QString::number(randI(tmp[0].toInt(), tmp[1].toInt())) );

    tmp = Lisattavan_statsit.voima_range.split('-');
    //voima
    data.push_back( QString::number(randI(tmp[0].toInt(), tmp[1].toInt())) );

    //armor
    data.push_back( Lisattavan_statsit.armor );

    //liike
    data.push_back( Lisattavan_statsit.liike);

    //nopeus
    data.push_back( Lisattavan_statsit.nopeus);

    //hinta
    data.push_back( laske_hinta(data) );

    //ase ja panssari jätetään tyhjiksi
    QString tyhja("");
    data.push_back(tyhja);
    data.push_back(tyhja);

    std::shared_ptr<ArenaMember> arvottu(new ArenaMember(data));

    arvottu->osta_armor("Puusuojat;20;1;0");
    arvottu->osta_ase("Puutikari;20;0;1");
    return arvottu;
}

void plebArpoja::lue_alustus()
{
    QFile tiedosto(":/rotu_alustus");
    if( tiedosto.open(QIODevice::ReadOnly) ){
        QTextStream stream(&tiedosto);
        while(!stream.atEnd()){
            QString row{stream.readLine()};
            if( row == "" or row[0] == '/' ){
                continue;
            }
            QStringList data{row.split(';')};
            statsit lisattavat;
            lisattavat.nimi_mahikset = data[1].split(',');
            lisattavat.hp_range = data[2];
            lisattavat.voima_range = data[3];
            lisattavat.armor = data[4];
            lisattavat.liike = data[5];
            lisattavat.nopeus = data[6];

            QString rotu = data[0];
            rotujen_nimet.push_back(data[0]);
            rodut[rotu] = lisattavat;
        }
    }
}


