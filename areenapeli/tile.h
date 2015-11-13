#ifndef TILE_H
#define TILE_H
#include <QString>
#include <QModelIndex>

class Tile : QModelIndex
{
public:
    Tile(QString color, bool solid = false);
    void onHit();

private:
    bool solid;
    QString color;
};

#endif // TILE_H
