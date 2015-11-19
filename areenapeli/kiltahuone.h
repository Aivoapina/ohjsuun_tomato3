#ifndef KILTAHUONE_H
#define KILTAHUONE_H

#include <QWidget>
#include <QList>
#include <memory>
#include "kiltamodel.h"
#include "arenamember.h"
#include "arenateam.h"
#include "plebruutu.h"

namespace Ui {
class kiltahuone;
}

class kiltahuone : public QWidget
{
    Q_OBJECT

public:
    explicit kiltahuone(ArenaTeam *tiimi, QWidget *parent = 0);

    ~kiltahuone();

signals:
    void pleb_ostettu();

private slots:
    void on_osta_clicked();
    void view_clicked();

private:
    std::shared_ptr<ArenaMember> selection_;
    Ui::kiltahuone *ui;
    kiltaModel *model_;
    ArenaTeam *tiimi_;
    //QList<std::shared_ptr<ArenaMember> plebs_;
};

#endif // KILTAHUONE_H
