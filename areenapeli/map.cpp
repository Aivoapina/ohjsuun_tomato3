#include "map.h"
#include "tile.h"
#include <QDebug>

Map::Map(QObject *parent)
    : QAbstractTableModel(parent)
{
}

void Map::makeTile()
{
    beginInsertRows(QModelIndex(), 0, 7);
    for( int j = 0; j<8; j++){
        QList<Tile> list;
        map_ << list;
    }
    endInsertRows();

    for(int j = 0; j < 8; j++){
        beginInsertColumns(QModelIndex(), 0, 11);
        for( int i = 0 ; i<12; i++){
            Tile *tile = new Tile("red");
            map_[j] << *tile;
        }
        endInsertColumns();
    }
}


int Map::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 8;
}
int Map::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);

    return 12;
}

QVariant Map::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= map_.count())
        return QVariant();

    const Tile &tile = map_[index.column()].at(index.row());
    if (role == ColorRole){
        return tile.color();
    }
 //   else if (role == solidRole){
 //       return tile.solid();
 //   }
    return QVariant();

}

QHash<int, QByteArray> Map::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[ColorRole] = "color_";
   // roles[solidRole] = "solid";
    return roles;
}

