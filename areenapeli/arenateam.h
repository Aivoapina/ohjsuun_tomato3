#ifndef ARENATEAM_H
#define ARENATEAM_H

#include <QString>
#include <memory>
#include <QList>
#include <QObject>
#include "arenamember.h"
#include "plebarpoja.h"


class ArenaTeam: public QObject
{
    Q_OBJECT
public:
    explicit ArenaTeam(QObject *parent= 0);

    ArenaTeam(int AItaso, QObject *parent = 0);


    void set_name(QString n);
    QList<std::shared_ptr<ArenaMember>> getPlebs();
    void buyNewMember(std::shared_ptr<ArenaMember> newpleb);
    std::shared_ptr<ArenaMember> return_selected();
    void select(std::shared_ptr<ArenaMember> s);
    int get_raha();
    void lisaa_voitto();
    void alusta();
    QString r_nimi();
    int r_voitot();
    void lisaa_rahaa(int maara);


signals:
    void tiedot_muuttunut();

private:
    int voitot;
    QList<std::shared_ptr<ArenaMember>> members;
    uint gold;
    QString name;
    std::shared_ptr<ArenaMember> selected;
    plebArpoja *arpoja;

};

#endif // ARENATEAM_H
