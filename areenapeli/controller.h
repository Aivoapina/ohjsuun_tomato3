#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QAbstractItemModel>
#include "arenateam.h"
#include "map.h"

class Controller
{
public:
    Controller(ArenaTeam *own_team, ArenaTeam *enemy_team);
    Map *initFight();
    bool startFight();

private:
    ArenaTeam *own_team_;
    ArenaTeam *enemy_team_;
    Map *map_model;
};

#endif // CONTROLLER_H
