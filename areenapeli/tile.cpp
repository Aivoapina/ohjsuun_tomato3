#include "tile.h"

<<<<<<< HEAD
Tile::Tile(const QString &picture)
    : color_(picture)//, bool &isSolid)
{
  //  solid_ = isSolid;
   // color_ = picture;
=======
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
>>>>>>> 90f5f233c323c6cd88be95d062815dabd2289611
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

