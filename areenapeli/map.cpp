#include "map.h"
#include "tile.h"

Map::Map(QObject *parent) : QAbstractItemModel(parent)
{

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
    }
}



