#ifndef AICONTROL_H
#define AICONTROL_H
#include "arenateam.h"
#include "map.h"

class Aicontrol : public QObject
{
    Q_OBJECT
public:
    Aicontrol(Map* mapmodel, ArenaTeam* team, QObject *parent);
    void calculateNextMove(int attacker);
    QString goOtherDir(int attacker);

public slots:
    void aiEndTurn(std::shared_ptr<ArenaMember> pleb);

private:
    int findPleb(std::shared_ptr<ArenaMember> pleb);
    Map* mapmodel_;
    ArenaTeam* team_;
    QMap <int,QString> dic;
    QList<Tile> map;
};

#endif // AICONTROL_H
