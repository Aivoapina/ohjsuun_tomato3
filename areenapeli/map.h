#ifndef MAP_H
#define MAP_H
#include <QAbstractListModel>
#include "tile.h"

class Map : public QAbstractListModel
{
    Q_OBJECT
    //Q_PROPERTY(int giveIndex READ getIndex NOTIFY indexChanged)

public:
    /*enum MapRoles{
        BackgroundRole = Qt::DecorationRole,
        IconRole = Qt::DisplayRole
    };
    */
    Map(QObject *parent = 0);
    void setMapModel( QList<Tile>);
    //int giveIndex();
    Q_INVOKABLE void liikuJohonkin(const QString &direction, const int &index);
    //QHash<int, QByteArray> roleNames() const;
    int rowCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;

public slots:
    //void moveKappa(const QString &direction, const int &index);

signals:
    void indexChanged();

private:
    QList<Tile> map;
};
#endif

