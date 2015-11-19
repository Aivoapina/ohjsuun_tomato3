#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QAbstractItemModel>

class Controller : QAbstractItemModel
{
public:
    Controller();
    void createMap();
};

#endif // CONTROLLER_H
