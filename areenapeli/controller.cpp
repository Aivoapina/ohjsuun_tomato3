#include "controller.h"
#include "tile.h"

Controller::Controller(ArenaTeam *own_team, ArenaTeam *enemy_team)
{
    own_team_ = own_team;
    enemy_team_ = enemy_team;
}

std::shared_ptr<ArenaMember> Controller::startFight()
{
    active_team_ = own_team_;
    return active_team_->getPlebs().at(0);

}

bool Controller::canMemberMove(std::shared_ptr<ArenaMember> pleb)
{
    if ( active_team_->getPlebs().contains(pleb) and !moved_plebs.contains(pleb)  ){
        return true;
    }
    return false;
}

void Controller::memberMoved(std::shared_ptr<ArenaMember> pleb)
{
    moved_plebs.push_back(pleb);
}

std::shared_ptr<ArenaMember> Controller::endTurn()
{
    if (active_team_ == own_team_){
        active_team_ = enemy_team_;
    } else {
        active_team_ = own_team_;
    }
    moved_plebs.clear();
    return active_team_->getPlebs().at(0);
}

std::shared_ptr<ArenaMember> Controller::findUnmovedMember()
{
    for (auto mem : active_team_->getPlebs() ){
        if ( !moved_plebs.contains(mem) ){
            return mem;
        }
    }
    return nullptr;
}


