#include "tile.h"


Tile::Tile(std::shared_ptr<ArenaMember> pleb, QString pictureDir, bool solidBlock)
{
    solid = solidBlock;
    picture = pictureDir;
    hero = pleb;
}

QString Tile::givePicture() const
{
    return picture;
}

QString Tile::getHeroPic() const
{
    if (hero == nullptr){
        return "assets/transparent.png";
    } else if ( hero->r_current_hp() < 1 ){
        return "assets/tomato_texture.png";
    }
    return "assets/bull_ingame.png";
}

std::shared_ptr<ArenaMember> Tile::getHero() const
{
    return hero;
}

bool Tile::isSolid() const
{
    return solid;
}

