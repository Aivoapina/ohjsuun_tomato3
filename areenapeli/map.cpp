#include "map.h"
#include "tile.h"
#include <QModelIndex>
#include <QDebug>


Map::Map(QObject *parent) : QAbstractListModel(parent)
{

}

void Map::makeMapModel(ArenaTeam *own_team, ArenaTeam *enemy_team)
{
    //QList<Tile> new_map;
    QString location = "assets/grass_texture.jpg";
    int j = 0;
    for(int i = 0; i < 160; i++){
        if ( i > 2 and i < 7 ){
            if ( j < enemy_team->getPlebs().size() ){
                map.append( Tile( enemy_team->getPlebs().at(j), location, true ) );
                j++;
                continue;
            } else if( i == 6 ){
                j = 0;
            }
        }
        if ( i > 152 and i < 157 ){
            if ( j < own_team->getPlebs().size() ){
                map.append( Tile( own_team->getPlebs().at(j), location, true ) );
                j++;
                continue;
            }
        }
        map.append( Tile( nullptr, location ) );
    }

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
        if (index < 10 or map.at(index-10).isSolid()){
            qDebug() << "Can't move there";
            return;
        }
        map.swap(index, index-10);
    } else if(direction == "down" ){
        if (index > 149 or map.at(index+10).isSolid()){
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

