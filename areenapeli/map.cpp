#include "map.h"
#include "tile.h"


Map::Map(QObject *parent) : QAbstractItemModel(parent)
{

}

void Map::addTile(Tile)
{

}

QHash<int, QByteArray> Map::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[BackgroundRole] = "background";
    roles[IconRole] = "icon";
    return roles;
}



int Map::rowCount(const QModelIndex &parent) const
{
    return 16;
}

int Map::columnCount(const QModelIndex &parent) const
{
    return 10;
}

QVariant Map::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole){
        return QVariant();
    } else if (role == Qt::DisplayRole){
        return
    }
}



