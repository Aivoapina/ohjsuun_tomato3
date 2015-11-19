#include "map.h"
#include "tile.h"
<<<<<<< HEAD
#include <QDebug>

Map::Map(QObject *parent)
    : QAbstractTableModel(parent)
=======
#include <QModelIndex>


Map::Map(QObject *parent) : QAbstractListModel(parent)
>>>>>>> 90f5f233c323c6cd88be95d062815dabd2289611
{
}

<<<<<<< HEAD
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
=======
void Map::setMapModel(QList<Tile> new_map)
{
    map = new_map;
}
/*
QHash<int, QByteArray> Map::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[BackgroundRole] = "background";
    roles[IconRole] = "icon";
    return roles;
}*/



int Map::rowCount(const QModelIndex & parent ) const
{
    return map.count();
}

QVariant Map::data(const QModelIndex &index, int role) const
{
    if (role != Qt::DisplayRole && role != Qt::DecorationRole){
        return QVariant();
    } else if (role == Qt::DecorationRole){
        Tile asd = map.at( index.row() );
        return asd.givePicture();
    } else if ( role == Qt::DisplayRole ){
        Tile hero = map.at( index.row() );
        if (hero.getHeroPic() == ""){
            return QVariant();
        }
        return hero.getHeroPic();
    }
    return QVariant();
>>>>>>> 90f5f233c323c6cd88be95d062815dabd2289611
}

