#ifndef DataBase_H
#define DataBase_H

//数据库类

#include "Book.h"

using namespace std;
class DataBase
{
public:
    Book book[100];

public:
    DataBase();
    // ~DataBase();
    DataBase(DataBase &d);
    int insert(Book);
    int Delete(int);
    Book Idsearch(int);
    DataBase Savesort();
    DataBase Pricesort();
    DataBase Idsort();
    DataBase Idsearch(int, int);
    DataBase Timesearch(Time, Time);
    DataBase Authorsearch(string);
    bool judgeId(int);
    void show();
};

#endif