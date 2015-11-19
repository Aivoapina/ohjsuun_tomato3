#include "map.h"
#include "tile.h"
#include <QModelIndex>
#include <QDebug>


Map::Map(QObject *parent) : QAbstractListModel(parent)
{

}

void Map::setMapModel(QList<Tile> new_map)
{
    map = new_map;
}

void Map::liikuJohonkin(const QString &direction, const int &index)
{
    layoutAboutToBeChanged();
    if (direction == "right"){
        if (index % 10 == 9 or map.at(index+1).isSolid() ){
            qDebug() << "Can't move there";
            return;
        }
        map.swap(index, index+1);
    } else if(direction == "left" ){
        if (index % 10 == 0 or map.at(index-1).isSolid()){
            qDebug() << "Can't move there";
            return;
        }
        map.swap(index, index-1);
    } else if(direction == "up" ){
        if (index < 11 or map.at(index-10).isSolid()){
            qDebug() << "Can't move there";
            return;
        }
        map.swap(index, index-10);
    } else if(direction == "down" ){
        if (index > 150 or map.at(index+10).isSolid()){
            qDebug() << "Can't move there";
            return;
        }
        map.swap(index, index+10);
    }
    layoutChanged();
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
}

