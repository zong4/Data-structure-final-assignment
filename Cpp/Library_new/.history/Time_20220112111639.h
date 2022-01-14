#ifndef Time_H
#define Time_H

//日期类的设置
//TODO:
#include <iostream>

using namespace std;
class Time
{
private:
    int year, month, day;

public:
    Time()
    {
        year = 0;
        month = 0;
        day = 0;
    }
    Time(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    void SetDate(int y, int m, int d)
    {
        this->year = y;
        this->month = m;
        this->day = d;
    }
    // void ShowTime(){
    //     cout<<"日期为:"<<year<<"年"<<month<<"月"<<day<<"日"<<endl;
    // }
    int getYear() { return year; }
    int getMonth() { return month; }
    int getDay() { return day; }
    int getDate() { return 10000 * year + 100 * month + day; }
    void SetYear(int y) { this->year = y; }
    void SetMonth(int m) { this->month = m; }
    void SetDay(int d) { this->day = d; }
    void show()
    {
        cout << year << "年" << month << "月" << day << "日";
    }
    friend class Book;
};

#endif