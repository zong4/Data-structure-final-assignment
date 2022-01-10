#ifndef Book_H
#define Book_H

//图书类
#include <string>
#include <iostream>

#include "Time.h"

using namespace std;
class Book
{
private:
    int id;         //图书号
    string name;    //书名
    string author;  //作者姓名
    string address; //出版社名称
    Time WriteTime; //出版日期
    double price;   //价格
    Time SaveTime;
    int num;
    double Allprice;

public:
    Book(int id = 0, string name = "1", string author = "1", string address = "1", int year = 0, int month = 0, int day = 0, double price = 0, int num = 0)
    {
        this->id = id;
        this->name = name;
        this->author = author;
        this->address = address;
        this->WriteTime.year = year;
        this->WriteTime.month = month;
        this->WriteTime.day = day;
        this->price = price;
        this->num = num;
    }
    // ~Book();
    void Set(Book &b)
    {
        this->name = b.name;
        this->author = b.author;
        this->address = b.address;
        this->WriteTime = b.WriteTime;
        this->price = b.price;
        this->SaveTime = b.WriteTime;
        this->num = b.num;
    }
    void setPrice(double price) { this->price = price; }
    void setNum(int num) { this->num = num; }
    void setTime(int year, int month, int day)
    {
        SaveTime.SetYear(year);
        SaveTime.SetMonth(month);
        SaveTime.SetDay(day);
    }
    int getid() { return id; }
    Time getSave() { return SaveTime; }
    string getName() { return name; }
    string GetAuthor() { return author; }
    string getAddress() { return address; }
    Time getWrite() { return WriteTime; }
    double getPrice() { return price; }
    int getNum() { return num; }
    void ShowData()
    {
        cout << "图书号为:" << id << "--";
        cout << "书名为:" << name << "--";
        cout << "作者姓名为:" << author << "--";
        cout << "出版社名称为:" << address << "--";
        cout <<"出版日期为:";
        WriteTime.show();
        cout<<"--"<<"收藏日期为:";
        SaveTime.show();
        cout<<"--";
        cout << "价格为:" << price << endl;
    }
};

#endif
