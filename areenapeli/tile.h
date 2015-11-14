#ifndef TILE_H
#define TILE_H
#include <QString>
#include <QModelIndex>
#include <QPixmap>

class Tile : QModelIndex
{
public:
    Tile(QString heroDir, QString pictureDir, bool solid = false);
    QString givePicture();
    QString getHeroPic();
    void onHit();


private:
    bool solid;
    QString picture;
    QString hero;
};

#endif // TILE_H
