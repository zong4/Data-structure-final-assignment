//书库类
#ifndef Set_H
#define Set_H
#include <iostream>

#include "DataBase.h"

using namespace std;

class Set :public DataBase
{
public:
    Set(int size) : DataBase(size){};
    // ~Set(){delete []book;}
    int deleteAll(Time t);
    void show();
    int readfile(string);
};
#endif