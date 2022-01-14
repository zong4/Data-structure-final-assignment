//书库类
#include <iostream>

#include "DataBase.h"

using namespace std;

class Set:virtual public DataBase{
public: 
    Set():DataBase(){};
    // ~Set(){delete []book;}
    int deleteAll(Time &t);
    void show();
    int readfile(fstream&);
};