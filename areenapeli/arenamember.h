#ifndef ARENAMEMBER_H
#define ARENAMEMBER_H

#include <QString>
#include <QStringList>
#include <QObject>
#include <QMetaType>

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

    // tähän funktio jonka parametrinä saapuva dmg, palautetaan otettu dmg ja lyhyt kuvaus tapahtuneesta.

    QString r_rotu() const;
    QString r_nimi() const;

    int r_current_hp() const;
    int r_power() const;
    int r_armor() const;
    int r_liike() const;
    int r_nopeus() const;

    QString r_iconPath() const;
    int r_hinta() const;
    QStringList r_data();

private:
    stats stats_;
    QString nimi_;
    QString rotu_;
    int hinta_;
    QString iconPath_;


};


#endif // ARENAMEMBER_H
