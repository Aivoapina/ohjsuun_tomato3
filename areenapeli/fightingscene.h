#ifndef FIGHTINGSCENE_H
#define FIGHTINGSCENE_H

#include <QWidget>
#include <QtQuickWidgets/QQuickWidget>
#include <QtQuick/qquickitem.h>
#include <QtQuick/qquickview.h>

namespace Ui {
class FightingScene;
}

class FightingScene : public QWidget
{
    Q_OBJECT

public:
    explicit FightingScene(QWidget *parent = 0);
    ~FightingScene();

private:
    Ui::FightingScene *ui;
    //QQuickView qmlView;
};

#endif // FIGHTINGSCENE_H
