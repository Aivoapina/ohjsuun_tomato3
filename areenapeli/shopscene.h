#ifndef shopscene_H
#define shopscene_H
#include "shop.h"
#include <QDialog>
#include <QMainWindow>
#include <QtWidgets>
#include <vector>
#include <string>
#include <QtGui>
#include <QDialog>
#include "arenateam.h"
#include "arenamember.h"

using namespace std;
namespace Ui {
class shopscene;
}


class shopscene : public QWidget
{
    Q_OBJECT

public:
    explicit shopscene(ArenaTeam *myteam, QWidget *parent = 0);
    ~shopscene();

signals:
    void tavara_ostettu();

private slots:
    void refresh_plebs();
    void on_ButtonBuy_clicked();

private:
    Ui::shopscene *ui;
    vector<item_struct> list_shopobjects;
    ArenaTeam *myteam_;
    QTreeWidgetItem *aseet;
    QTreeWidgetItem *panssarit;
};

#endif // shopscene    _H
