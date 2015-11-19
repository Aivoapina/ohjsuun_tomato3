#ifndef ARENAMEMBER_H
#define ARENAMEMBER_H

#include <QString>
#include <QStringList>
#include <QObject>
#include <QMetaType>

struct stats{

    int hp;
    int power;

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

    QString iconPath() const;
    int r_current_hp() const;
    int r_power() const;
    QString r_nimi() const;
    int r_hinta() const;
    QStringList r_data();

private:
    stats stats_;
    QString nimi_;
    int hinta_;
    QString iconPath_;


};


#endif // ARENAMEMBER_H
