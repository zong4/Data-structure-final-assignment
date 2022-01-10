#ifndef Time_H
#define Time_H

//日期类的设置
//TODO:
#include <iostream>

using namespace std;
class Time{
private: 
    int year,month,day;
public: 
    Time();
    Time(int,int,int);
    void SetDate(int year,int month,int day){
        this->year  = year;
        this->month = month;
        this->day   = day;
    }
    // void ShowTime(){
    //     cout<<"日期为:"<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
    // }
    int getYear(){return year;}
    int getMonth(){return month;}
    int getDay(){return day;}
    int getDate(){return 10000*year+100*month+day;}
    void SetYear(int year){this->year=year;}
    void SetMonth(int month){this->month=month;}
    void SetDay(int day){this->day=day;}
    void show() {
        cout << year << "年" << month << "月" << day << "日";
    }
    friend class Book;
};

#endif