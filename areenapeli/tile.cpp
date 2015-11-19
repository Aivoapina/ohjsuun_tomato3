#include "tile.h"

Tile::Tile(const QString &picture)
    : color_(picture)//, bool &isSolid)
{
  //  solid_ = isSolid;
   // color_ = picture;
}

QString Tile::color() const
{
    return color_;
}
/*
bool Tile::solid() const
{
    return solid_;
}*/

