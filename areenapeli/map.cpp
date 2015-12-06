#include "map.h"
#include "tile.h"
#include <QModelIndex>
#include <QDebug>


int randomInt(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

Map::Map(QObject *parent) : QAbstractListModel(parent)
{
    dic.insert("right", "itään"); dic.insert("left", "länteen");
    dic.insert("up", "pohjoiseen"); dic.insert("down", "etelään");
    dic.insert("upright", "koiliseen"); dic.insert("upleft", "luoteeseen");
    dic.insert("downright", "kaakkoon"); dic.insert("downleft", "lounaaseen");
}

Controller *Map::startFight(ArenaTeam *own_team, ArenaTeam *enemy_team, Aicontrol *aic)
{
    QString location = "assets/grass_texture.png";
    QString stone = "assets/brick_texture.png";
    QString water = "assets/water_texture.png";
    int j = 0;
    int solid_tiles = 0;
    int max_solid_tiles = 20;
    for(int i = 0; i < 160; i++){
        if( i == 7 ){
            j = 0;
        }
        else if ( i > 2 and i < 7 ){
            if ( j < enemy_team->getPlebs().size() ){
                map.push_back( Tile( enemy_team->getPlebs().at(j), location, false ) );
                j++;
                continue;
            }
        }
        else if (10 < i and i < 150){
            if ( solid_tiles < max_solid_tiles){
                if (randomInt(1,20) == 1 ){
                    map.push_back( Tile(nullptr, stone, true) );
                    solid_tiles += 1;
                    continue;
                } else if(randomInt(1,20) == 1 ){
                    map.push_back( Tile(nullptr, water, true ) );
                    solid_tiles += 1;
                    continue;
                }
            }
        }
        else if ( i > 152 and i < 157 ){
            if ( j < own_team->getPlebs().size() ){
                map.push_back( Tile( own_team->getPlebs().at(j), location, false ) );
                j++;
                continue;
            }
        }
        map.push_back( Tile( nullptr, location ) );
    }
    control = new Controller(own_team, enemy_team);
    ai = aic;
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
    if (index == -1){
        return;
    }
    bool player_moved = false;
    std::shared_ptr<ArenaMember> target;
    std::shared_ptr<ArenaMember> mem = map.at(index).getHero();
    if ( control->canMemberMove( mem ) ){
        if (direction == "right" ){
            if (index % 10 == 9 or map.at(index+1).isSolid()){
                qDebug() << "Can't move there";
                return;
            }
            target = map.at(index+1).getHero();
            if (target != nullptr and target->r_current_hp() > 0 ){
                emit somethingHappened( control->hitMember(mem, target));
                emit updateActiveMember(mem);
            } else {
                player_moved = true;
                map.swap(index, index+1);
            }
        } else if(direction == "left" ){
            if (index % 10 == 0 or map.at(index-1).isSolid()){
                qDebug() << "Can't move there";
                return;
            }
            target = map.at(index-1).getHero();
            if (target != nullptr and target->r_current_hp() > 0 ){
                emit somethingHappened( control->hitMember(mem, target));
                emit updateActiveMember(mem);
            } else {
                player_moved = true;
                map.swap(index, index-1);
            }
        } else if(direction == "up" ){
            if (index < 10 or map.at(index-10).isSolid()){
                qDebug() << "Can't move there";
                return;
            }
            target = map.at(index-10).getHero();
            if ( target != nullptr and target->r_current_hp() > 0 ){
                emit somethingHappened( control->hitMember(mem, target) );
                emit updateActiveMember(mem);
            } else {
                player_moved = true;
                map.swap(index, index-10);
            }
        } else if(direction == "down" ){
            if (index > 149 or map.at(index+10).isSolid()){
                qDebug() << "Can't move there";
                return;
            }
            target = map.at(index+10).getHero();
            if (target != nullptr and target->r_current_hp() > 0 ){
                emit somethingHappened( control->hitMember(mem, target));
                emit updateActiveMember(mem);
            } else {
                player_moved = true;
                map.swap(index, index+10);
            }
        } else if(direction == "upleft") {
            if (index % 10 == 0 or index < 10 or map.at(index-11).isSolid() ){
                qDebug() << "Can't move there";
                return;
            }
            target = map.at(index-11).getHero();
            if ( target != nullptr and target->r_current_hp() > 0 ){
                emit somethingHappened( control->hitMember(mem, target));
                emit updateActiveMember(mem);
            } else {
                player_moved = true;
                map.swap(index, index-11);
            }
        } else if(direction == "upright"){
            if (index % 10 == 9 or index < 10 or map.at(index-9).isSolid() ){
                qDebug() << "Can't move there";
                return;
            }
            target = map.at(index-9).getHero();
            if ( target != nullptr and target->r_current_hp() > 0 ){
                emit somethingHappened( control->hitMember(mem, target));
                emit updateActiveMember(mem);
            } else {
                player_moved = true;
                map.swap(index, index-9);
            }
        } else if(direction == "downright"){
            if (index % 10 == 9 or index > 149 or map.at(index+11).isSolid() ){
                qDebug() << "Can't move there";
                return;
            }
            target = map.at(index+11).getHero();
            if (target != nullptr and target->r_current_hp() > 0 ){
                emit somethingHappened( control->hitMember(mem, target));
                emit updateActiveMember(mem);
            } else {
                player_moved = true;
                map.swap(index, index+11);
            }
        } else if(direction == "downleft"){
            if (index % 10 == 0 or index > 149 or map.at(index+9).isSolid() ){
                qDebug() << "Can't move there";
                return;
            }
            target = map.at(index+9).getHero();
            if ( target != nullptr and target->r_current_hp() > 0){
                emit somethingHappened( control->hitMember(mem, target));
                emit updateActiveMember(mem);
            } else {
                player_moved = true;
                map.swap(index, index+9);
            }
        } else if(direction == "skip"){
            control->memberMoved( mem );
            aiIndexChange();
            emit updateActiveMember( mem );
            emit somethingHappened( QString(mem->r_nimi() + " skippasi vuoronsa.") );
            return;
        }
    } else {
        return;
    }
    if ( !control->isInSameTeam(target, mem) and (target == nullptr or target->r_current_hp() < 1) ){
        control->memberMoved( mem );
    }
    if ( control->checkDeath(target) and !player_moved ){
        emit somethingHappened(QString( target->r_nimi() + " kuoli saatana." ));
        ArenaTeam* winner = control->getWinner();
        if ( winner != nullptr ){
            emit gameEnded(winner);
        }
    } else if (target == nullptr or target->r_current_hp() < 1) {
        emit somethingHappened( QString(mem->r_nimi() + " liikkui " + dic[direction] + "."));
    }
    emit updateActiveMember(mem);
    layoutChanged();
}

void Map::endTurn()
{
    emit aiTurn(control->endTurn());
}

void Map::playerChangedIndex(int index)
{
    m_index = index;
    emit updateActiveMember( map.at(index).getHero() );
}

int Map::getM_index()
{
    if ( findPleb(control->findUnmovedMember() ) ){
        emit updateActiveMember(map.at(m_index).getHero());
        return m_index;
    }
    emit updateActiveMember(nullptr);
    return -1;
}

void Map::setM_index(int new_index)
{
    m_index = new_index;
    emit m_indexChanged(new_index);
}

void Map::aiIndexChange()
{
    layoutAboutToBeChanged();
    map.swap(3,1);
    layoutChanged();
}

QList<Tile> Map::getMap()
{
    return map;
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

