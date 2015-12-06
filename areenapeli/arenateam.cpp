#include "arenateam.h"
#include <QDebug>

ArenaTeam::ArenaTeam(QObject *parent)
    :QObject(parent)
{
    voitot = 0;
    name = "Tiimi";
    gold = 9000;
    selected = nullptr;
}

ArenaTeam::ArenaTeam(int AItaso, QObject *parent)
    :QObject(parent)
{
    voitot = 0;
    arpoja = new plebArpoja();
    gold = 99999999; //purkka ":D"

    if( AItaso == 0 ){
        set_name("1");
        lisaa_voitto();
    }
    else if( AItaso == 1 ){
        set_name("2");
    }
    else if( AItaso == 2){
        lisaa_voitto();
        lisaa_voitto();
        lisaa_voitto();
        set_name("3");
    }
    else if( AItaso == 3){
        set_name("4");
    }
    else if( AItaso == 4){
        set_name("5");
        lisaa_voitto();
        lisaa_voitto();
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
