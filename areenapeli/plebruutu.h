#ifndef PLEBRUUTU_H
#define PLEBRUUTU_H

#include <QWidget>
#include <QMessageBox>
#include <memory>
#include <QMouseEvent>
#include "arenamember.h"
#include "plebruutu.h"
#include "arenateam.h"


namespace Ui {
class plebRuutu;
}

class plebRuutu : public QWidget
{
    Q_OBJECT

public:
    explicit plebRuutu(ArenaTeam *team, std::shared_ptr<ArenaMember> pleb, QWidget *parent = 0);
    plebRuutu(std::shared_ptr<ArenaMember> pleb, QWidget * parent = 0);
    ~plebRuutu();

    void paivita();

    void mousePressEvent(QMouseEvent *e);

signals:
    void selection_changed();

private slots:
    void on_aseLabel_clicked();

    void on_panssariLabel_clicked();

private:
    Ui::plebRuutu *ui;
    std::shared_ptr<ArenaMember> pleb_;
    ArenaTeam* team;
};

#endif // PLEBRUUTU_H




