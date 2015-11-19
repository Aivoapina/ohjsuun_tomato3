#ifndef TILE_H
#define TILE_H
#include <QString>
#include <QModelIndex>
#include <QPixmap>

class Tile
{
public:
<<<<<<< HEAD
    Tile(const QString &color);//, bool &solid);
    QString color() const;
   // bool solid() const;
  //  void onHit();
=======
    Tile(QString heroDir, QString pictureDir, bool solid = false);
    QString givePicture();
    QString getHeroPic();
    void onHit();
>>>>>>> 90f5f233c323c6cd88be95d062815dabd2289611


private:
<<<<<<< HEAD
  //  bool solid_;
    QString color_;
=======
    bool solid;
    QString picture;
    QString hero;
>>>>>>> 90f5f233c323c6cd88be95d062815dabd2289611
};

#endif // TILE_H
