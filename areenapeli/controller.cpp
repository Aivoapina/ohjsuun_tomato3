#include "controller.h"
#include "tile.h"

Controller::Controller(ArenaTeam *own_team, ArenaTeam *enemy_team)
{
    own_team_ = own_team;
    enemy_team_ = enemy_team;
}

std::shared_ptr<ArenaMember> Controller::startFight()
{
    players_turn = true;
    return own_team_->getPlebs().at(0);

}

bool Controller::canMemberMove(std::shared_ptr<ArenaMember> pleb)
{
    if (players_turn){
        if ( own_team_->getPlebs().contains(pleb) and !moved_plebs.contains(pleb) ){
            moved_plebs.push_back(pleb);
            return true;
        }
    } else {
        if ( enemy_team_->getPlebs().contains(pleb) and !moved_plebs.contains(pleb) ){
            moved_plebs.push_back(pleb);
            return true;
        }
    }
    return false;
}

void Controller::endTurn()
{
    players_turn = !players_turn;
    moved_plebs.clear();
}


