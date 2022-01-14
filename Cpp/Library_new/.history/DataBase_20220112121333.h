#ifndef DataBase_H
#define DataBase_H

//数据库类

#include "Book.h"

using namespace std;
class DataBase
{
public:
    int size;
    Book *book;

public:
    DataBase(int);
    ~DataBase();
    DataBase(Book *, int);
    int insert(Book);
    int Delete(int);
    Book Idsearch(int);
    DataBase Savesort();
    DataBase Pricesort();
    DataBase Idsort();
    DataBase Idsearch(int, int);
    DataBase Timesearch(Time, Time);
    int Authorsearch(string);
    bool judgeId(int);
    void show();
};

#endif