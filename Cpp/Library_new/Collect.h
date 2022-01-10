//收藏夹类
#ifndef Collect_H
#define Collect_H
#include <iostream>

#include "DataBase.h"
#include "Shop.h"
#include "Set.h"

using namespace std;
class Shop;
class Collect : virtual public DataBase
{
public:
    Collect(int size) : DataBase(size){};
    // ~Collect(){delete []book;};
    friend int ShoptoCollect(int, Shop &, Collect &);
    friend int SettoCollect(int ,Set&,Collect&);
    void show();
};

#endif