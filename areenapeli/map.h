#ifndef MAP_H
#define MAP_H
#include <QAbstractItemModel>
#include "tile.h"

class Map : QAbstractItemModel
{
    Q_OBJECT
public:
    enum MapRoles{
        Image = Qt::DecorationRole
    };

    Map(QObject *parent = 0);

    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
private:
    QList<Tile> map;


};

#endif // MAP_H
