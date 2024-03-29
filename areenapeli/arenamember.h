#ifndef ARENAMEMBER_H
#define ARENAMEMBER_H

#include <QString>
#include <QStringList>
#include <QObject>
#include <QMetaType>
#include <memory>

#include "shop.h"

struct stats{
    int hp;
    int power;
    int armor;
    int liike;
    int nopeus;

};

class ArenaMember
{
public:
    ArenaMember();// QObject *p = 0 );
    ArenaMember(QStringList data);
    ArenaMember(const ArenaMember &a);
    ~ArenaMember();

    void lisaa_maxhp();
    void lisaa_power();
    void lisaa_nopeus();

    void osta_ase(QString d);
    void osta_armor(QString d);

    QString laske_osuma(std::shared_ptr<ArenaMember> hyokkaaja);

    void alusta();

    QString r_rotu() const;
    QString r_nimi() const;

    int r_current_hp() const;
    int r_maxhp();
    int r_power() const;
    int r_armor() const;
    int r_liike() const;
    int r_nopeus() const;

    Shopobject *r_panssari() const;
    Shopobject *r_ase() const;

    QString r_iconPath() const;
    int r_hinta() const;
    QStringList r_data();

private:
    stats stats_;
    int current_hp;
    QString nimi_;
    QString rotu_;
    int hinta_;
    QString iconPath_;

    Shopobject *armor_;
    Shopobject *ase_;
};


#endif // ARENAMEMBER_H
