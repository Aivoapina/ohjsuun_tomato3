#ifndef TILE_H
#define TILE_H
#include <QString>
#include <QModelIndex>

class Tile : QModelIndex
{
public:
    Tile(QString pictureDir, bool solid = false);
    void onHit();

private:
    bool solid;
    QPixmap picture;
};

#endif // TILE_H
