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
    if ( active_team_->getPlebs().contains(pleb)){
        if (!moved_plebs.contains(pleb) or moved_plebs[pleb] < 2  ){
            return true;
        }
    }
    return false;
}

void Controller::memberMoved(std::shared_ptr<ArenaMember> pleb)
{
    if (moved_plebs.contains(pleb)){
        moved_plebs[pleb] += 1;
    } else {
        moved_plebs.insert(pleb, 1);
    }
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
        if ( !moved_plebs.contains(mem) or moved_plebs[mem] < 2 ){
            return mem;
        }
    }
    return nullptr;
}


