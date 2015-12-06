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
    void buyNewMember(std::shared_ptr<ArenaMember> newpleb);
    void select(std::shared_ptr<ArenaMember> s);
    void lisaa_voitto();
    void alusta();
    void lisaa_rahaa(int maara);

    std::shared_ptr<ArenaMember> return_selected();
    int get_raha();
    QString r_nimi();
    int r_voitot();
    QList<std::shared_ptr<ArenaMember>> getPlebs();


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
