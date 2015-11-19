<<<<<<< HEAD

#include <QAbstractTableModel>
#include <QStringList>

#include "tile.h"

class Map : public QAbstractTableModel
{
    Q_OBJECT
public:
    enum tileRoles {

        ColorRole = Qt::UserRole
       // solidRole
    };

    Map(QObject *parent = 0);

    void makeTile();

    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    int columnCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<QList<Tile>> map_;
=======
#ifndef MAP_H
#define MAP_H
#include <QAbstractListModel>
#include "tile.h"

class Map : public QAbstractListModel
{
    Q_OBJECT

public:
    /*enum MapRoles{
        BackgroundRole = Qt::DecorationRole,
        IconRole = Qt::DisplayRole
    };
    */
    Map(QObject *parent = 0);
    void setMapModel( QList<Tile>);
    //QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

private:
    QList<Tile> map;


>>>>>>> 90f5f233c323c6cd88be95d062815dabd2289611
};

