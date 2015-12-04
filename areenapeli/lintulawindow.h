#ifndef LINTULAWINDOW_H
#define LINTULAWINDOW_H

#include <QWidget>
#include "arenateam.h"

namespace Ui {
class lintulaWindow;
}

class lintulaWindow : public QWidget
{
    Q_OBJECT

public:
    explicit lintulaWindow(ArenaTeam *team, QWidget *parent = 0);
    ~lintulaWindow();


private slots:


    void on_kesavyysButton_clicked();

    void on_voimaButton_clicked();

    void on_nopeusButton_clicked();

private:
    Ui::lintulaWindow *ui;
    ArenaTeam *myteam_;

    int hp_hinta;
    int voima_hinta;
    int nopeus_hinta;
};

#endif // LINTULAWINDOW_H
