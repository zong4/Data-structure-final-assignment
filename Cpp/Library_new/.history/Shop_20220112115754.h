//购物车类
#ifndef Shop_H
#define Shop_H
#include <iostream>

#include "DataBase.h"
#include "Collect.h"

using namespace std;
class Collect;
class Shop : virtual public DataBase
{
private:
    int Allnum;
    double Allprice;

public:
    Shop(int size) : DataBase(size)
    {
        Allnum = 0;
        Allprice = 0;
    };
    // ~Shop(){delete []book;}
    int Countnum();
    double Countprice();
    friend int CollecttoShop(int, Shop &s, Collect &);
    void show();
    int changeNum(int, int);
    void showpay(int);
};

#endif