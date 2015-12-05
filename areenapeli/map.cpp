#include "map.h"
#include "tile.h"
#include <QModelIndex>
#include <QDebug>


Map::Map(QObject *parent) : QAbstractListModel(parent)
{

}

Controller *Map::startFight(ArenaTeam *own_team, ArenaTeam *enemy_team)
{
    QString location = "assets/grass_texture.png";
    int j = 0;
    for(int i = 0; i < 160; i++){
        if( i == 7 ){
            j = 0;
        }
        else if ( i > 2 and i < 7 ){
            if ( j < enemy_team->getPlebs().size() ){
                map.push_back( Tile( enemy_team->getPlebs().at(j), location, true ) );
                j++;
                continue;
            }
        }
        else if ( i > 152 and i < 157 ){
            if ( j < own_team->getPlebs().size() ){
                map.push_back( Tile( own_team->getPlebs().at(j), location, true ) );
                j++;
                continue;
            }
        }
        map.append( Tile( nullptr, location ) );
    }
    control = new Controller(own_team, enemy_team);

    if ( !findPleb( control->startFight() ) ){
        qDebug() << "rip";
    }
    return control;
}

bool Map::findPleb(std::shared_ptr<ArenaMember> pleb)
{
    if (pleb == nullptr){
        return false;
    }
    for (int i = 0; i < map.count(); i++ ){
        if ( map.at(i).getHero() == pleb ){
            setM_index(i);
            return true;
        }
    }
    return false;
}

void Map::liikuJohonkin(const QString &direction, const int &index)
{
    layoutAboutToBeChanged();
    std::shared_ptr<ArenaMember> mem = map.at(index).getHero();
    if ( control->canMemberMove( mem ) ){
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
        } else if(direction == "upleft") {
            if (index % 10 == 0 or index < 10 or map.at(index-11).isSolid() ){
                qDebug() << "Can't move there";
                return;
            }
            map.swap(index, index-11);
        } else if(direction == "upright"){
            if (index % 10 == 9 or index < 10 or map.at(index-9).isSolid() ){
                qDebug() << "Can't move there";
                return;
            }
            map.swap(index, index-9);
        } else if(direction == "downright"){
            if (index % 10 == 9 or index > 149 or map.at(index+11).isSolid() ){
                qDebug() << "Can't move there";
                return;
            }
            map.swap(index, index+11);
        } else if(direction == "downleft"){
            if (index % 10 == 0 or index > 149 or map.at(index+9).isSolid() ){
                qDebug() << "Can't move there";
                return;
            }
            map.swap(index, index+9);
        }
    } else {
        return;
    }
    control->memberMoved( mem );
    layoutChanged();
}

void Map::endTurn()
{
    if ( !findPleb( control->endTurn() ) ){
        qDebug() << "rip";
    }
}

int Map::getM_index()
{
    if ( findPleb(control->findUnmovedMember() ) ){
        return m_index;
    }
    return -1;
}

void Map::setM_index(int new_index)
{
    m_index = new_index;
    emit m_indexChanged(new_index);
}
/*
QHash<int, QByteArray> Map::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[BackgroundRole] = "background";
    roles[IconRole] = "icon";
    return roles;
}*/



int Map::rowCount(const QModelIndex & /*parent*/ ) const
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

