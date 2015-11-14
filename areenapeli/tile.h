#ifndef TILE_H
#define TILE_H
#include <QString>
#include <QModelIndex>
#include <QPixmap>

class Tile : QModelIndex
{
public:
    Tile(QString &name, QString pictureDir, bool solid = false);
    QString givePicture();
    void onHit();

private:
    bool solid;
    QString picture;
};

#endif // TILE_H
