#include "kiltamodel.h"
#include <QDebug>
int randInteger(int low, int high)
{
    return qrand() % ((high + 1) - low) + low;
}

kiltaModel::kiltaModel(QObject *parent)
    : QAbstractListModel(parent)
{

}


void kiltaModel::makePleb()
{
    int x = randInteger(2,6);
    beginInsertRows(QModelIndex(), 0, x);
    for( int j = 0; j<x; j++){
        // tähän generoidaan uusia jäbiä tehtaalla
        std::shared_ptr<ArenaMember> pleb(arpoja_.arvoPleb());
        model_ << pleb;
    }
    endInsertRows();
}

bool kiltaModel::removeRow(int row)
{
    beginRemoveRows(QModelIndex(), row, row);
    model_.removeAt(row);
    endRemoveRows();
    return true;
}

int kiltaModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return model_.count();
}

QVariant kiltaModel::data(const QModelIndex &index, int role) const
{
    if (index.row() < 0 || index.row() >= model_.count())
        return QVariant();

    ArenaMember *pleb = model_[index.row()].get();
    if (role == nimiRole){
        return pleb->r_nimi() + "\t" + QString::number(pleb->r_hinta()) + "g";
    }
    else if( role == hintaRole ){
        return pleb->r_hinta();
    }
    else if( role == dataRole ){
        return pleb->r_data();
    }
    return QVariant();
}

QHash<int, QByteArray> kiltaModel::roleNames() const {
    QHash<int, QByteArray> roles;
    roles[nimiRole] = "nimi";
    roles[hintaRole] = "hinta";
    roles[dataRole] = "data";
    return roles;
}
