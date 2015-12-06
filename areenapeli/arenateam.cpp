#include "arenateam.h"
#include <QDebug>

ArenaTeam::ArenaTeam(QObject *parent)
    :QObject(parent)
{
    voitot = 0;
    gold = 9000;
    selected = nullptr;
}

ArenaTeam::ArenaTeam(int AItaso, QObject *parent)
    :QObject(parent)
{
    voitot = 0;
    arpoja = new plebArpoja();
    gold = 99999999;

    if( AItaso == 0 ){
        set_name("Surkimukset");
    }
    else if( AItaso == 1 ){
        set_name("Aloittelijat");
    }
    else if( AItaso == 2){
        set_name("PerusPlebit");
    }
    else if( AItaso == 3){
        set_name("HyväYri");
    }
    else if( AItaso == 4){
        set_name("Jumalat");
    }

    buyNewMember(arpoja->arvoAIPleb(AItaso));
    buyNewMember(arpoja->arvoAIPleb(AItaso));
    buyNewMember(arpoja->arvoAIPleb(AItaso));
    buyNewMember(arpoja->arvoAIPleb(AItaso));
}

void ArenaTeam::set_name(QString n)
{
    name = n;
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

void ArenaTeam::lisaa_voitto()
{
    voitot++;
}

void ArenaTeam::alusta()
{
    for( std::shared_ptr<ArenaMember> mem : members ){
        mem->alusta();
    }
}

QString ArenaTeam::r_nimi()
{
    return name;
}

int ArenaTeam::r_voitot()
{
    return voitot;
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
