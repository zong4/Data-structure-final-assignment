//收藏夹类

#include <iostream>


#include "DataBase.h"

using namespace std;

class Collect:public DataBase{
private: 
    Collect(int size):DataBase(size){};
    ~Collect(){delete []book;};
    friend bool CollecttoShop(int);
    friend bool ShoptoCollect(int);
};
