#include "arenamember.h"
#include <QTime>

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
    nimi_ = data[0];
    hinta_ = data[1].toInt();
    stats_.hp = data[2].toInt();
    stats_.power = data[3].toInt();
    iconPath_ = data[4];
}

ArenaMember::ArenaMember(const ArenaMember &a)
{
    stats_.hp = a.r_current_hp();
    stats_.power = a.r_power();
    nimi_ = a.r_nimi();
    hinta_ = a.r_hinta();
    iconPath_ = a.r_iconPath();
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
    data.append(nimi_);
    data.append(QString::number(hinta_));
    data.append(QString::number(stats_.hp));
    data.append(QString::number(stats_.power));
    data.append(r_iconPath());
    return data;
}

