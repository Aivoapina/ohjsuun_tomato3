#ifndef SHOP_H
#define SHOP_H
#include <iostream>
#include <iomanip>
#include <QString>
#include <vector>

using namespace std;

struct shobject{
    QString name;
    QString price;
    QString damain;
    QString damout;
};

class Shopobject{
public:

    Shopobject();
    ~Shopobject();
    void buyobject();
    void sellobject();
    vector<shobject> refreshresults();
    unsigned int countobjects(vector<shobject> list_shopobjects);
private:
    /*string objectname_;
    int objectprice_;
    int objectdamagein_;
    int objectdamageout_;
    */
    shobject x;
};

void getobjects();
#endif // SHOP_H
