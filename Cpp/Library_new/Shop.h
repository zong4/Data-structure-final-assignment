//购物车类
#ifndef Shop_H
#define Shop_H
#include <iostream>

#include "DataBase.h"
#include "Collect.h"

using namespace std;
class Collect;
class Shop:public DataBase
{
private:
    int Allnum;
    double Allprice;
public:
    Shop(int size):DataBase(size){};
    ~Shop(){delete []book;}
    int Countnum();
    double Countprice();
    friend int CollecttoShop(int,Shop&,Collect&);
    friend int ShoptoCollect(int,Shop&,Collect&);
};

#endif