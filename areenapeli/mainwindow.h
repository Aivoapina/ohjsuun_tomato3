#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
//#include "map.h"
#include "kiltahuone.h"
#include "kiltamodel.h"
#include "arenateam.h"
#include "plebruutu.h"
#include "lintulawindow.h"
#include "controller.h"

namespace Ui{
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:

public slots:

private slots:
    void on_exitGame_clicked();

    void on_startGame_clicked();

    void on_kilta_clicked();

    void refresh_plebs();

    void on_lintulaButton_clicked();

    void hp_ostettu();
    void power_ostettu();

    void pleb1_selected();
    void pleb2_selected();
    void pleb3_selected();
    void pleb4_selected();


    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    ArenaTeam *myteam_;
    std::shared_ptr<ArenaMember> selected;

};

#endif // MAINWINDOW_H
