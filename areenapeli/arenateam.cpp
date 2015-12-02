#include "arenateam.h"
#include <QDebug>

ArenaTeam::ArenaTeam()
{
    name = "Tiimi";
    gold = 9000;
    selected = nullptr;
}

void ArenaTeam::buyNewMember(std::shared_ptr<ArenaMember> newpleb)
{
    qDebug() << newpleb.get()->r_hinta();
    gold = gold-newpleb.get()->r_hinta();
    members.push_back(newpleb);
}

std::shared_ptr<ArenaMember> ArenaTeam::return_selected()
{
    return selected;
}

void ArenaTeam::select(std::shared_ptr<ArenaMember> s)
{
    selected = s;
}

int ArenaTeam::get_raha()
{
    return gold;
}

void ArenaTeam::lisaa_rahaa(int maara)
{
    gold = gold + maara;
}


QList<std::shared_ptr<ArenaMember>> ArenaTeam::getPlebs()
{
    return members;
}
