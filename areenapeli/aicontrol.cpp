#include "aicontrol.h"
#include <cmath>

Aicontrol::Aicontrol(QObject *parent) : QObject(parent){

}

Aicontrol::Aicontrol(Map* mapmodel, ArenaTeam* team , QObject *parent) : QObject(parent)
{
    mapmodel_ = mapmodel;
    team_ = team;
    map = mapmodel_->getMap();
    connect(mapmodel_, SIGNAL(aiTurn(std::shared_ptr<ArenaMember>)), this, SLOT( aiEndTurn(std::shared_ptr<ArenaMember>)));
    dic.insert(1, "right"); dic.insert(-1 , "left");
    dic.insert(-10, "up"); dic.insert(10, "down");
    dic.insert(-9 , "upright"); dic.insert(-11, "upleft");
    dic.insert(11, "downright"); dic.insert(9, "downleft");
}

void Aicontrol::calculateNextMove(int attacker)
{
    QList<int> targets;
    for ( int i = 0; i < map.count(); i++  ){
        if (map.at(i).getHero() != nullptr and !team_->getPlebs().contains(map.at(i).getHero()) ){
            targets.push_back(i);
        }
    }
    int tar;
    double distance;
    double dist = 160;
    for (auto target : targets){
        distance = ( sqrt( pow (floor( (target - attacker) / 10), 2) + pow ( (target - attacker) % 10, 2  ) ) );
        if (distance < dist){
            tar = target;
        }
    }
    double deltay = floor((tar - attacker) / 10);
    double deltax = (tar- attacker) % 10;
    double angle = atan( deltay / deltax ) * 180 / 3.14159265;

    if ( angle == 0){
        if ( map.at(attacker + 1).isSolid() ){
            QString new_dir = goOtherDir(attacker);
            mapmodel_->liikuJohonkin(new_dir, attacker);
        } else {
            mapmodel_->liikuJohonkin("right", attacker);
        }
    } else if ( angle == 90){
        if ( map.at(attacker + 10).isSolid() ){
            QString new_dir = goOtherDir(attacker);
            mapmodel_->liikuJohonkin(new_dir, attacker);
        } else {
            mapmodel_->liikuJohonkin("down", attacker);
        }
    } else if ( angle == 180){
        if ( map.at(attacker - 1).isSolid() ){
            QString new_dir = goOtherDir(attacker);
            mapmodel_->liikuJohonkin(new_dir, attacker);
        } else {
            mapmodel_->liikuJohonkin("left", attacker);
        }
    } else if ( angle == 270){
        if ( map.at(attacker - 10).isSolid() ){
            QString new_dir = goOtherDir(attacker);
            mapmodel_->liikuJohonkin(new_dir, attacker);
        } else {
            mapmodel_->liikuJohonkin("up", attacker);
        }
    } else if ( angle > 0 and angle < 90 ){
        if ( map.at(attacker + 11).isSolid() ){
            QString new_dir = goOtherDir(attacker);
            mapmodel_->liikuJohonkin(new_dir, attacker);
        } else {
            mapmodel_->liikuJohonkin("downright", attacker);
        }
    } else if ( angle > 90 and angle < 180){
        if ( map.at(attacker + 9).isSolid() ){
            QString new_dir = goOtherDir(attacker);
            mapmodel_->liikuJohonkin(new_dir, attacker);
        } else {
            mapmodel_->liikuJohonkin("downleft", attacker);
        }
    } else if ( angle > 180 and angle < 270 ){
        if ( map.at(attacker - 11).isSolid() ){
            QString new_dir = goOtherDir(attacker);
            mapmodel_->liikuJohonkin(new_dir, attacker);
        } else {
            mapmodel_->liikuJohonkin("upleft", attacker);
        }
    } else if ( angle > 270 and angle < 360 ){
        if ( map.at(attacker - 9).isSolid() ){
            QString new_dir = goOtherDir(attacker);
            mapmodel_->liikuJohonkin(new_dir, attacker);
        } else {
            mapmodel_->liikuJohonkin("upright", attacker);
        }
    }
    int j = mapmodel_->getM_index();
    if (j == -1){
        return;
    } else {
        calculateNextMove(j);
    }
}

QString Aicontrol::goOtherDir(int attacker)
{
    QList<int> list = dic.keys();
    std::random_shuffle(list.begin(), list.end());
    if (! map.at(attacker+list.at(0)).isSolid() ){
        return dic[list.at(0)];
    } else {
        return goOtherDir(attacker);
    }
}

void Aicontrol::aiEndTurn(std::shared_ptr<ArenaMember> pleb){

    int i = findPleb(pleb);
    if ( i != -1 ){
        calculateNextMove(i);
    } else {
        mapmodel_->playerTurn();
    }
}

int Aicontrol::findPleb(std::shared_ptr<ArenaMember> pleb)
{
    if (pleb == nullptr){
        return -1;
    }
    for (int i = 0; i < map.count(); i++ ){
        if ( map.at(i).getHero() == pleb ){
            return i;
        }
    }
    return -1;
}

