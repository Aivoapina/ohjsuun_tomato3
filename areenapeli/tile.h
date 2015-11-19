#ifndef TILE_H
#define TILE_H
#include <QString>
#include <QModelIndex>

class Tile
{
public:
    Tile(const QString &color);//, bool &solid);
    QString color() const;
   // bool solid() const;
  //  void onHit();

private:
  //  bool solid_;
    QString color_;
};

#endif // TILE_H
