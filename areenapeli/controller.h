#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QAbstractItemModel>
#include "arenateam.h"

class Controller
{
public:
    Controller(ArenaTeam *own_team, ArenaTeam *enemy_team);
    std::shared_ptr<ArenaMember> startFight();
    bool canMemberMove(std::shared_ptr<ArenaMember> pleb);
    void endTurn();

private:
    ArenaTeam *own_team_;
    ArenaTeam *enemy_team_;
    bool players_turn;
    QList<std::shared_ptr<ArenaMember>> moved_plebs;
};

#endif // CONTROLLER_H
