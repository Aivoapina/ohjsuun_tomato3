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
    void memberMoved(std::shared_ptr<ArenaMember> pleb);
    std::shared_ptr<ArenaMember> endTurn();
    std::shared_ptr<ArenaMember> findUnmovedMember();
    QString hitMember(std::shared_ptr<ArenaMember> attacker, std::shared_ptr<ArenaMember> target);
    bool checkDeath(std::shared_ptr<ArenaMember> target);
    ArenaTeam *getWinner();

private:
    ArenaTeam *own_team_;
    ArenaTeam *enemy_team_;
    ArenaTeam *active_team_;
    QMap<std::shared_ptr<ArenaMember>, int> moved_plebs;
};

#endif // CONTROLLER_H
