#ifndef MAP_H
#define MAP_H
#include <QAbstractListModel>
#include "tile.h"

class Map : public QAbstractListModel
{
    Q_OBJECT

public:
    /*enum MapRoles{
        BackgroundRole = Qt::DecorationRole,
        IconRole = Qt::DisplayRole
    };
    */
    Map(QObject *parent = 0);
    void setMapModel( QList<Tile>);
    //QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    QList<Tile> map;


};

#endif // MAP_H
