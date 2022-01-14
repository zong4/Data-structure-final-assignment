#ifndef Book_H
#define Book_H

//图书类
#include <string>
#include <iostream>

#include "Time.h"

using namespace std;
class Book
{
public: 
    int id;      //图书号 
    string name;    //书名
    string author;  //作者姓名
    string address; //出版社名称
    Time WriteTime;   //出版日期
    double price;       //价格
    Time SaveTime;
    int num;
    double Allprice;
public: 
    Book(int id = 0,string name = "", string author = "", string address = "", int year = 0, int month = 0, int day = 0, double price = 0,int num=0)
    {
        this->name            = name;
        this->author          = author;
        this->address         = address;
        this->WriteTime.year  = year;
        this->WriteTime.month = month;
        this->WriteTime.day   = day;
        this->price           = price;
        this->SaveTime        = this->WriteTime;
        this->num             = num;
    }
    // ~Book();
    void Set(Book &b){
        this->name            = b.name;
        this->author          = b.author;
        this->address         = b.address;
        this->WriteTime  = b.WriteTime;
        this->price           = b.price;
        this->SaveTime        = b.WriteTime;
        this->num             = b.num;
    }
    void setPrice(double price) { this->price = price; }
    void setNum(int num){this->num=num;}
    void setSaveTime(int year, int month, int day) 
    { 
        SaveTime.SetYear(year);
        SaveTime.SetMonth(month);
        SaveTime.SetDay(day);
    }
    int getid() {return id;}
    int getNum(){return num;}
    Time getSave(){return SaveTime;}
    string getName() { return name; }
    string GetAuthor() { return author; }
    string getAddress() { return address; }
    Time getWrite() { return WriteTime; }
    double getPrice() { return price; }
    // friend class DataBase;
     void ShowData()
     {
         cout << "图书号为:" << id << endl;
         cout << "书名为:" << name << endl;
         cout << "作者姓名为:" << author << endl;
         cout << "出版社名称为:" << address << endl;
         cout << "价格为:" << price << endl;
     }
};

#endif
