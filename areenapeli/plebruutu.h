#ifndef PLEBRUUTU_H
#define PLEBRUUTU_H

#include <QWidget>
#include <memory>
#include <QMouseEvent>
#include "arenamember.h"
#include "plebruutu.h"

namespace Ui {
class plebRuutu;
}

class plebRuutu : public QWidget
{
    Q_OBJECT

public:
    explicit plebRuutu(std::shared_ptr<ArenaMember> pleb, QWidget *parent = 0);
    ~plebRuutu();

    void paivita();

    void mousePressEvent(QMouseEvent *e);

signals:
    void selection_changed();

private:
    Ui::plebRuutu *ui;
    std::shared_ptr<ArenaMember> pleb_;
};

#endif // PLEBRUUTU_H
