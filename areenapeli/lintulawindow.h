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
    explicit lintulaWindow(QWidget *parent = 0);
    ~lintulaWindow();

signals:
    void lisaa_hp();
    void lisaa_power();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::lintulaWindow *ui;
    ArenaTeam *team_;
};

#endif // LINTULAWINDOW_H
