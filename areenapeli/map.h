#ifndef MAP_H
#define MAP_H
#include <QAbstractListModel>
#include "tile.h"
#include "arenateam.h"
#include "controller.h"

class Map : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int m_index READ getM_index WRITE setM_index NOTIFY m_indexChanged)

public:
    Map(QObject *parent = 0);

    Controller* startFight(ArenaTeam *own_team, ArenaTeam *enemy_team);
    bool findPleb(std::shared_ptr<ArenaMember> pleb);

    Q_INVOKABLE void liikuJohonkin(const QString &direction, const int &index);
    Q_INVOKABLE void endTurn();
    Q_INVOKABLE void playerChangedIndex(int index);
    int getM_index();
    void setM_index(int new_index);
    void aiTurnEnd();
    void playerTurn();
    QList<Tile> getMap();

    int rowCount(const QModelIndex &/*parent*/) const;
    QVariant data(const QModelIndex &index, int role) const;

signals:
    void m_indexChanged(int new_index);
    void somethingHappened(QString msg);
    void updateActiveMember(std::shared_ptr<ArenaMember> pleb);
    void gameEnded(ArenaTeam* winner);
    void aiTurn(std::shared_ptr<ArenaMember> pleb);

private:
    QList<Tile> map;
    Controller * control;
    QMap<QString, QString> dic;
    int m_index;

};
#endif

