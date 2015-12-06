#ifndef PLEBARPOJA_H
#define PLEBARPOJA_H

#include <QMap>
#include <QFile>
#include <QString>

#include "memory"
#include "arenamember.h"


struct statsit{
    QString rotu;
    QStringList nimi_mahikset;
    QString hp_range;
    QString voima_range;
    QString armor;
    QString liike;
    QString nopeus;
};


class plebArpoja
{
public:
    plebArpoja();

    std::shared_ptr<ArenaMember> arvoPleb();

    std::shared_ptr<ArenaMember> arvoAIPleb(int taso);

private:
    void lue_alustus();

    QMap<QString, statsit> rodut;
    QStringList rotujen_nimet;
};

#endif // PLEBARPOJA_H
