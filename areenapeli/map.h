#ifndef MAP_H
#define MAP_H
#include <QAbstractListModel>
#include "tile.h"
#include "arenateam.h"
#include "controller.h"

class Map : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(int m_index MEMBER m_index NOTIFY indexChanged)

public:
    /*enum MapRoles{
        BackgroundRole = Qt::DecorationRole,
        IconRole = Qt::DisplayRole
    };
    */
    Map(QObject *parent = 0);
    Controller* startFight(ArenaTeam *own_team, ArenaTeam *enemy_team);
    bool findPleb(std::shared_ptr<ArenaMember> pleb);
    Q_INVOKABLE void liikuJohonkin(const QString &direction, const int &index);
    //QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &/*parent*/) const;
    QVariant data(const QModelIndex &index, int role) const;

public slots:
    //void moveKappa(const QString &direction, const int &index);

signals:
    void indexChanged(int new_index);

private:
    QList<Tile> map;
    Controller * control;
    int m_index;

};
#endif

