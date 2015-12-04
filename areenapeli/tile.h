#ifndef TILE_H
#define TILE_H
#include <QString>
#include <QModelIndex>
#include <QPixmap>
#include "arenamember.h"
#include <memory>

class Tile
{
public:
    Tile(std::shared_ptr<ArenaMember> pleb, QString pictureDir, bool solidBlock = false);
    QString givePicture() const;
    QString getHeroPic() const;
    std::shared_ptr<ArenaMember> getHero() const;
    bool isSolid() const;

private:
    bool solid;
    QString picture;
    std::shared_ptr<ArenaMember> hero;
};

#endif // TILE_H
