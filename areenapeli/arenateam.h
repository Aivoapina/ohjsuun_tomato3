#ifndef ARENATEAM_H
#define ARENATEAM_H

#include <QString>
#include <memory>
#include <QList>
#include "arenamember.h"


class ArenaTeam
{
public:
    ArenaTeam();
    QList<std::shared_ptr<ArenaMember>> getPlebs();
    void buyNewMember(std::shared_ptr<ArenaMember> newpleb);
    std::shared_ptr<ArenaMember> return_selected();
    void select(std::shared_ptr<ArenaMember> s);
    int get_raha();

    void lisaa_rahaa(int maara);

private:
    QList<std::shared_ptr<ArenaMember>> members;
    uint gold;
    QString name;
    std::shared_ptr<ArenaMember> selected;

};

#endif // ARENATEAM_H
