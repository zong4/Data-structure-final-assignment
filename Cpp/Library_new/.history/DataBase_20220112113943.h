#ifndef DataBase_H
#define DataBase_H

//数据库类

#include "Book.h"

using namespace std;
class DataBase
{
public:
    int size;
    Book book[100];

public:
    DataBase(){size=100;};
    // ~DataBase();
    DataBase(DataBase &d);
    int insert(Book);
    int Delete(int);
    Book Idsearch(int);
    int Savesort();
    int Pricesort();
    int Idsort();
    int Idsearch(int, int);
    int Timesearch(Time, Time);
    int Authorsearch(string);
    bool judgeId(int);
    void show();
};

#endif