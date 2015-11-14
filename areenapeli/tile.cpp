#include "tile.h"

Tile::Tile(QString &name, QString pictureDir, bool isSolid)
{
    solid = isSolid;
    picture = pictureDir;
}

QString Tile::givePicture()
{
    return picture;
}

