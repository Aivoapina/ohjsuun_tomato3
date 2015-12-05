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

QString ArenaMember::laske_osuma(std::shared_ptr<ArenaMember> hyokkaaja)
{
    QString kuvaus;
    if ( randInt(0,100) < r_nopeus() ){
        kuvaus = r_nimi()+ " väisti iskun, eikä täten ota osumaa";
        return kuvaus;
    }
    int torjuttu;
    int otettu;

    int saapuva{0};
    if( hyokkaaja->r_ase() != nullptr ){
        QStringList asedata = hyokkaaja->r_ase()->r_damout().split('d');
        for( int i = 0; i < asedata[0].toInt(); i++){
            saapuva = saapuva + randInt(1,asedata[1].toInt());
        }
    }
    saapuva = saapuva + hyokkaaja->r_power();

    torjuttu = r_armor();
    if( r_panssari() != nullptr ){
        torjuttu = torjuttu + r_panssari()->r_damin().toInt();
    }

    if( saapuva <= torjuttu ){
        kuvaus = r_nimi()+ "n panssari torjui kaiken osuman";
        return kuvaus;
    }
    otettu = saapuva - torjuttu;
    current_hp = current_hp - otettu;
    kuvaus = hyokkaaja->r_nimi() + " iski voimalla " + QString::number(saapuva) + ". " + r_nimi()+ ": Otti " + QString::number(otettu)+ " damagea. Panssari torjui " + QString::number(torjuttu) +" vahinkoa.";
    return kuvaus;
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

