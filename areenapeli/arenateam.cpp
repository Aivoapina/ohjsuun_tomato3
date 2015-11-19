#include "arenateam.h"

ArenaTeam::ArenaTeam()
{
    name = "Tiimi";
    gold = 9000;
}

void ArenaTeam::buyNewMember(std::shared_ptr<ArenaMember> newpleb)
{
    gold = gold-newpleb.get()->r_hinta();
    members.push_back(newpleb);
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
