#include "controller.h"
#include "tile.h"

Controller::Controller(ArenaTeam *own_team, ArenaTeam *enemy_team)
{
    own_team_ = own_team;
    enemy_team_ = enemy_team;
    map_model = new Map();
}

Map* Controller::initFight()
{
    map_model->makeMapModel(own_team_, enemy_team_);

    return map_model;
}

bool Controller::startFight()
{
    if (map_model->giveTurn( own_team_->getPlebs())){

    }
}


