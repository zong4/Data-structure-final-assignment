//购物车类

#include <iostream>

#include "DataBase.h"
using namespace std;

class Shop:public DataBase
{
private:
    int Allnum;
    double Allprice;
public:
    Shop(int size):DataBase(size){};
    ~Shop(){delete []book;}
    int Countnum(){return Allnum;}
    double Countprice(){return Allprice;}
    friend bool CollecttoShop(int);
    friend bool ShoptoCollect(int);
};