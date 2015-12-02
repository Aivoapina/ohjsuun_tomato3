#include "arenamember.h"
#include <QTime>
#include <QDebug>

QList<QString> MAHD_NIMET{"Pena", "Pertti", "Laarnio", "Keba", "Jämä", "Prime", "PELLE", "Kusimuna", "VitunFuksi", "Kyrpä", "Hirviö", "Jooseppi", "Brotherman", "Bill"};

int randInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}


ArenaMember::ArenaMember()

{
    hinta_ = randInt(100,500);
    nimi_ = MAHD_NIMET[randInt(0,MAHD_NIMET.size()-1)];
    stats_.hp = randInt(10,50);
    stats_.power = randInt(3,15);
    iconPath_ = "assets/bullmentula_ingame.png";
}

ArenaMember::ArenaMember(QStringList data)
{
    rotu_ = data[0];
    nimi_ = data[1];
    stats_.hp = data[2].toInt();
    stats_.power = data[3].toInt();
    stats_.armor = data[4].toInt();
    stats_.liike = data[5].toInt();
    stats_.nopeus = data[6].toInt();
    hinta_ = data[7].toInt();
    qDebug()<<hinta_;
   // iconPath_ = data[4];
}

ArenaMember::ArenaMember(const ArenaMember &a)
{
    rotu_ = a.r_rotu();
    nimi_ = a.r_nimi();
    stats_.hp = a.r_current_hp();
    stats_.power = a.r_power();
    stats_.armor = a.r_armor();
    stats_.liike = a.r_liike();
    stats_.nopeus = a.r_nopeus();
    hinta_ = a.r_hinta();

    //iconPath_ = a.r_iconPath();
}

ArenaMember::~ArenaMember()
{
}

void ArenaMember::lisaa_maxhp()
{
    stats_.hp++;
}

void ArenaMember::lisaa_power()
{
    stats_.power++;
}

QString ArenaMember::r_rotu() const
{
    return rotu_;
}

QString ArenaMember::r_iconPath() const
{
    return iconPath_;
}

int ArenaMember::r_current_hp() const
{
    return stats_.hp;
}

int ArenaMember::r_power() const
{
    return stats_.power;
}

int ArenaMember::r_armor() const
{
    return stats_.armor;
}

int ArenaMember::r_liike() const
{
    return stats_.liike;
}

int ArenaMember::r_nopeus() const
{
    return stats_.nopeus;
}

QString ArenaMember::r_nimi() const
{
    return nimi_;
}

int ArenaMember::r_hinta() const
{
    return hinta_;
}

QStringList ArenaMember::r_data()
{
    QStringList data;
    data.append(rotu_);
    data.append(nimi_);
    data.append(QString::number(stats_.hp));
    data.append(QString::number(stats_.power));
    data.append(QString::number(stats_.armor));
    data.append(QString::number(stats_.liike));
    data.append(QString::number(stats_.nopeus));
    data.append(QString::number(hinta_));
    return data;
}

