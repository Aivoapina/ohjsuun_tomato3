#ifndef KILTAMODEL_H
#define KILTAMODEL_H

#include <QAbstractListModel>
#include <memory>
#include <QList>
#include "arenamember.h"
#include "plebarpoja.h"


class kiltaModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum plebRoles{
        nimiRole = Qt::DisplayRole,
        hintaRole = Qt::UserRole,
        dataRole = Qt::UserRole +1
    };

    kiltaModel(QObject *parent = 0);

    void makePleb();

    bool removeRow(int row);
    int rowCount(const QModelIndex & parent = QModelIndex()) const;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

protected:
    QHash<int, QByteArray> roleNames() const;

private:
    QList<std::shared_ptr<ArenaMember>> model_;
    plebArpoja arpoja_;
};

#endif // KILTAMODEL_H

