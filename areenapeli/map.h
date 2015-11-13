#ifndef MAP_H
#define MAP_H
#include <QAbstractItemModel>

class Map : QAbstractItemModel
{
public:
    Map();
    void makeMap();

private:

    QAbstractItemModel *map_;
};

#endif // MAP_H
