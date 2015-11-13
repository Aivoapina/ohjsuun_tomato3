#include "tile.h"

Tile::Tile(QString picture, bool isSolid = false)
{
    solid = isSolid;
    color = picture;
}

