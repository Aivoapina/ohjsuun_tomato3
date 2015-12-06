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
    if ( active_team_->getPlebs().contains(pleb) and pleb->r_current_hp() > 0){
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
    moved_plebs.clear();
    if (active_team_ == own_team_){
        active_team_ = enemy_team_;
    } else {
        active_team_ = own_team_;
    }
    return active_team_->getPlebs().at(0);
}

std::shared_ptr<ArenaMember> Controller::findUnmovedMember()
{
    for (auto mem : active_team_->getPlebs() ){
        if ( ( !moved_plebs.contains(mem) or moved_plebs[mem] < 2 ) and mem->r_current_hp() > 0 ){
            return mem;
        }
    }
    return nullptr;
}

QString Controller::hitMember(std::shared_ptr<ArenaMember> attacker, std::shared_ptr<ArenaMember> target)
{
    if (active_team_->getPlebs().contains(target)){
        return "Et voi lyödä omaa pelaajaa";
    }
    if (moved_plebs.contains(attacker)){
        moved_plebs[attacker] += 2;
    } else {
        moved_plebs.insert(attacker, 2);
    }
    return target->laske_osuma(attacker);
}

bool Controller::checkDeath(std::shared_ptr<ArenaMember> target)
{
    if (target == nullptr){
        return false;
    }
    if (target->r_current_hp() < 1){
        return true;
    }
    return false;
}

ArenaTeam* Controller::getWinner()
{
    if (active_team_ == own_team_){
        for (auto mem : enemy_team_->getPlebs()){
            if (mem->r_current_hp() > 0){
                return nullptr;
            }
        }
        return own_team_;
    } else {
        for (auto mem : own_team_->getPlebs()){
            if (mem->r_current_hp() > 0){
                return nullptr;
            }
        }
        return enemy_team_;
    }
}

bool Controller::isInSameTeam(std::shared_ptr<ArenaMember> pleb, std::shared_ptr<ArenaMember> pleb2)
{
    if (pleb == nullptr or pleb2 == nullptr) {
        return false;
    }
    if (own_team_->getPlebs().contains(pleb) and own_team_->getPlebs().contains(pleb2) ){
        return true;
    } else if (enemy_team_->getPlebs().contains(pleb) and enemy_team_->getPlebs().contains(pleb2) ){
        return true;
    }
    return false;
}



