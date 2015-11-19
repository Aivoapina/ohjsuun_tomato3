#include "tile.h"


Tile::Tile(std::shared_ptr<ArenaMember> pleb, QString pictureDir, bool solidBlock)
{
    solid = solidBlock;
    picture = pictureDir;
    hero = pleb;
}

QString Tile::givePicture()
{
    return picture;
}

QString Tile::getHeroPic()
{
    if (hero == nullptr){
        return "";
    }
    return hero->iconPath();
}

bool Tile::isSolid() const
{
    return solid;
}

