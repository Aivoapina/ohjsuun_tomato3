#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include <iomanip>
#include <QString>
#include <QList>


struct item_struct{
    QString name;
    QString price;
    QString damain;
    QString damout;
};

class Shopobject{
public:

    Shopobject();
    Shopobject(QString data);//tälle toteutus
    ~Shopobject();

    QString r_name() const;
    QString r_price() const;
    QString r_damin() const;
    QString r_damout() const;
    QString toQString() const; // tälle toteutus shobject->Qstring

    void buyobject();
    void sellobject();
    QList<Shopobject> refreshresults();
    unsigned int countobjects(QList<Shopobject> list_shopobjects);
private:
    /*string objectname_;
    int objectprice_;
    int objectdamagein_;
    int objectdamageout_;
    */
    item_struct x;
};

void getobjects();
#endif // SHOP_H
