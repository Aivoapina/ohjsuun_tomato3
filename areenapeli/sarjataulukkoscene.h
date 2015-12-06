#ifndef SARJATAULUKKOSCENE_H
#define SARJATAULUKKOSCENE_H

#include "mainwindow.h"
#include <QWidget>
#include "arenamember.h"
#include "arenateam.h"
#include <memory>
#include <QList>



namespace Ui {
class SarjataulukkoScene;
}

class SarjataulukkoScene : public QWidget
{
    Q_OBJECT

public:
    explicit SarjataulukkoScene(ArenaTeam* myteam, QList<ArenaTeam*> aiteams,  QList<QList<ArenaTeam*>> ohjelma, QWidget *parent = 0);
    ~SarjataulukkoScene();

private:
    Ui::SarjataulukkoScene *ui;
};

#endif // SARJATAULUKKOSCENE_H
