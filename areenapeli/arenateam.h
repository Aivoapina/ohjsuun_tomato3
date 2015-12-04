#ifndef ARENATEAM_H
#define ARENATEAM_H

#include <QString>
#include <memory>
#include <QList>
#include <QObject>
#include "arenamember.h"


class ArenaTeam: public QObject
{
    Q_OBJECT
public:
    explicit ArenaTeam(QObject *parent= 0);
    QList<std::shared_ptr<ArenaMember>> getPlebs();
    void buyNewMember(std::shared_ptr<ArenaMember> newpleb);
    std::shared_ptr<ArenaMember> return_selected();
    void select(std::shared_ptr<ArenaMember> s);
    int get_raha();
    void lisaa_rahaa(int maara);


signals:
    void tiedot_muuttunut();

private:
    QList<std::shared_ptr<ArenaMember>> members;
    uint gold;
    QString name;
    std::shared_ptr<ArenaMember> selected;

};

#endif // ARENATEAM_H
