#include "tile.h"

Tile::Tile(QString heroDir, QString pictureDir, bool isSolid)
{
    solid = isSolid;
    picture = pictureDir;
    hero = heroDir;
}

QString Tile::givePicture()
{
    return picture;
}
QString Tile::getHeroPic(){
    return hero;
}

/*
bool Tile::solid() const
{
    return solid_;
}*/

