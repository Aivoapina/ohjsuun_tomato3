#include "arenamember.h"
#include <QTime>
#include <QDebug>


int randInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}


ArenaMember::ArenaMember()

{
}

ArenaMember::ArenaMember(QStringList data)
{
    rotu_ = data[0];
    nimi_ = data[1];
    stats_.hp = data[2].toInt();
    current_hp = stats_.hp;
    stats_.power = data[3].toInt();
    stats_.armor = data[4].toInt();
    stats_.liike = data[5].toInt();
    stats_.nopeus = data[6].toInt();
    hinta_ = data[7].toInt();

    if( data[8] == "" ){
        armor_ = nullptr;
    }
    else{
        armor_ = new Shopobject(data[8]);
    }
    if( data[9] == ""){
        ase_ = nullptr;
    }
    else{
        ase_ = new Shopobject(data[9]);
    }
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
    armor_ = a.r_panssari();
    ase_ = a.r_ase();
}

ArenaMember::~ArenaMember()
{
}

void ArenaMember::lisaa_maxhp()
{
    stats_.hp++;
    current_hp = stats_.hp;
}

void ArenaMember::lisaa_power()
{
    stats_.power++;
}

void ArenaMember::lisaa_nopeus()
{
    stats_.nopeus++;
}

void ArenaMember::osta_ase(QString d)
{
    if ( d == "myyty" ){
        ase_ = nullptr;
    }
    else{
        ase_ = new Shopobject(d);
    }
}

void ArenaMember::osta_armor(QString d)
{
    if ( d == "myyty" ){
        armor_ = nullptr;
    }
    else{
        armor_ = new Shopobject(d);
    }
}

QStringList ArenaMember::laske_osuma(int saapuva)
{
    QStringList osuma_selitys;

    if ( randInt(0,100) < r_nopeus() ){
        osuma_selitys.push_back("0");
        osuma_selitys.push_back(r_nimi()+ " väisti iskun, eikä täten ota osumaa");
        return osuma_selitys;
    }

    if( saapuva <= r_armor() ){
        osuma_selitys.push_back("0");
        osuma_selitys.push_back(r_nimi()+ "n panssari torjui kaiken osuman");
        return osuma_selitys;
    }
    osuma_selitys.push_back(QString::number(saapuva - r_armor()));
    current_hp = current_hp - ( saapuva- r_armor() );
    qDebug() << current_hp;
    osuma_selitys.push_back(r_nimi()+ ": Otti " + QString::number(saapuva - r_armor())+ " damagea. Panssari torjui " + QString::number(r_armor()) +" vahinkoa." );
    return osuma_selitys;
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
    return current_hp;
}

int ArenaMember::r_maxhp()
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

Shopobject *ArenaMember::r_panssari() const
{
    return armor_;
}

Shopobject *ArenaMember::r_ase() const
{
    return ase_;
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
    if(armor_ == nullptr ){
        data.append("");
    }
    else{
        data.append(armor_->toQString());
    }
    if(ase_ == nullptr ){
        data.append("");
    }
    else{
        data.append(ase_->toQString());
    }
    return data;
}

