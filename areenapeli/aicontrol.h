#ifndef AICONTROL_H
#define AICONTROL_H
#include "arenateam.h"
#include "map.h"
#include <QObject>

class Aicontrol : public QObject
{
    Q_OBJECT
public:
    explicit Aicontrol(QObject *parent = 0);
    Aicontrol(Map* mapmodel, ArenaTeam* team, QObject *parent = 0);
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
