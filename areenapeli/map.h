
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
};

