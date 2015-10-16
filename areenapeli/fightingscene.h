#ifndef FIGHTINGSCENE_H
#define FIGHTINGSCENE_H

#include <QWidget>
#include <QtQuickWidgets/QQuickWidget>

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
    QQuickWidget *qmlView;
};

#endif // FIGHTINGSCENE_H
