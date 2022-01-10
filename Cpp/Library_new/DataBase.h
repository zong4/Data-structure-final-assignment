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
    virtual ~DataBase();
    DataBase(Book *, int);
    int insert(Book);
    int Delete(int);
    Book Idsearch(int);
    void Savesort();
    void Pricesort();
    void Idsort();
    void Idsearch(int, int);
    void Timesearch(Time, Time);
    void Authorsearch(string);
    bool judgeId(int);
    void show();
};

#endif