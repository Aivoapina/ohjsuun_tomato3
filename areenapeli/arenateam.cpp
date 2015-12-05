#include "arenateam.h"
#include <QDebug>

ArenaTeam::ArenaTeam(QObject *parent)
    :QObject(parent)
{
    name = "Tiimi";
    gold = 9000;
    selected = nullptr;
}

ArenaTeam::ArenaTeam(int AItaso, QObject *parent)
    :QObject(parent)
{
    arpoja = new plebArpoja();
    gold = 99999999; //purkka ":D"
    buyNewMember(arpoja->arvoAIPleb(0));
    buyNewMember(arpoja->arvoAIPleb(0));
    buyNewMember(arpoja->arvoAIPleb(0));
    buyNewMember(arpoja->arvoAIPleb(0));
}



void ArenaTeam::buyNewMember(std::shared_ptr<ArenaMember> newpleb)
{
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
    emit tiedot_muuttunut();
}


QList<std::shared_ptr<ArenaMember>> ArenaTeam::getPlebs()
{
    return members;
}
