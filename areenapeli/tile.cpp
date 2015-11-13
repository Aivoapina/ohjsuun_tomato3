#include "tile.h"

Tile::Tile(QString pictureDir, bool isSolid = false)
{
    solid = isSolid;
    picture = QPixmap(pictureDir);
}

