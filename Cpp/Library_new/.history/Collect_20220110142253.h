//收藏夹类
#ifndef Collect_H
#define Collect_H
#include <iostream>


#include "DataBase.h"
#include "Shop.h"

using namespace std;

class Collect:public DataBase
{
private: 
    Collect(int size):DataBase(size){};
    ~Collect(){delete []book;};
    friend class Shop;
    friend int CollecttoShop(int,Shop&,Collect&);
    friend int ShoptoCollect(int,Shop&,Collect&);
};
#endif