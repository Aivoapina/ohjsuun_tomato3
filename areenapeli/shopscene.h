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
using namespace std;
namespace Ui {
class shopscene;
}


class shopscene : public QWidget
{
    Q_OBJECT

public:
    explicit shopscene(QWidget *parent = 0);
    ~shopscene();

private slots:
    //void on_TextRACE_textChanged();

    void on_ButtonEXIT_clicked();

    //void on_tableWidget_activated(const QModelIndex &index);

private:
    Ui::shopscene *ui;
    vector<shobject> list_shopobjects;
};

#endif // shopscene    _H
