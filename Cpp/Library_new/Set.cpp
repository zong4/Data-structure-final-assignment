#include "Set.h"
#include "Collect.h"
#include <fstream>
int Set::deleteAll(Time t)
{
    cout << "将要删除的图书有:" << endl;
    for (int i = 1; i < 500; i++)
    {
        if (this->book[i].getSave().getYear() == t.getYear() && this->book[i].getSave().getMonth() == t.getMonth() && this->book[i].getSave().getDay() == t.getDay())
        {
            book[i].ShowData();
        }
    }
    cout << "是否要删除这些图书，是输入yes:";
    string choice;
    cin >> choice;
    if (choice == "yes" || choice == "YES" || choice == "Yes")
    {
        for (int i = 1; i < 500; i++)
        {
            if (this->book[i].getSave().getYear() == t.getYear() && this->book[i].getSave().getMonth() == t.getMonth() && this->book[i].getSave().getDay() == t.getDay())
            {
                book[i].setNum(0);
            }
        }
        cout << "图书删除成功" << endl;
        return 1;
    }
    else
    {
        cout << "未删除该图书" << endl;
        return 0;
    }
}
void Set::show()
{
    cout << "书库信息:" << endl;
    int num = 0;
    for (int i = 1; i < 500; i++) // size
    {
        num += book[i].getNum();
        if (book[i].getNum() != 0)
        {
            cout << "图书号为:" << book[i].getid() << "  "
                 << "书名为:" << book[i].getName() << "  "
                 << "作者为:" << book[i].GetAuthor() << "  "
                 << "出版社为:" << book[i].getAddress() << "  "
                 << "出版日期为:";
            book[i].getWrite().show();
            cout << "  "
                 << "价格为:" << book[i].getPrice() << "  "
                 << "数量为:" << book[i].getNum() << "  "
                 << "购买金额为:" << book[i].getNum() * book[i].getPrice() << "  "
                 << "加入书库日期为:";
            book[i].getSave().show();
            cout << endl;
        }
    }
    if (!num)
        cout << "=================================空===========================================" << endl;
}
int Set::readfile(string filename)
{
    fstream file(filename);
    int id;
    string name;    //书名
    string author;  //作者姓名
    string address; //出版社名称
    double price;   //价格
    int year, month, day, num;
    cout << "请统一输入进入时间:";
    int year1, month1, day1;
    cin >> year >> month >> day;
    while (file >> id)
    {
        file >> name >> author >> address >> year1 >> month1 >> day1 >> price >> num;
        Book b(id, name, author, address, year1, month1, day1, price, num);
        b.setTime(year, month, day);
        if (year > 2022 || year < 0 || month > 12 || month < 0 || day < 0 || day > 30)
        {
            cout << "输入日期不合法，请重新输入：";
            cin >> year >> month >> day;
            b.setTime(year, month, day);
        }
        if (b.getWrite().getDate() > b.getSave().getDate())
        {
            cout << "输入的收藏日期小于出版日期，不合法请重新输入:";
            cin >> year >> month >> day;
            b.setTime(year, month, day);
        }
        if (book[b.getid()].getNum() == 0)
        {
            book[b.getid()] = b;
        }
        else
        {
            if(book[b.getid()].getSave().getDate()<b.getSave().getDate())
            {
                book[b.getid()].setTime(b.getSave().getYear(),b.getSave().getMonth(),b.getSave().getDay());
            }
            book[b.getid()].setNum(book[b.getid()].getNum() + b.getNum());
        }
    }
    cout << "文件读取成功" << endl;
    return 1;
}

int SettoCollect(int id, Set &s, Collect &c)
{
    if (!s.judgeId(id))
    {
        cout << "输入的ID有误,请重新输入ID：" << endl;
        cin >> id;
    }
    if (s.book[id].getNum() == 0)
        cout << "插入失败,该书库内内没有该图书号对应的图书" << endl;
    else
    {
        cout<<"该图书的信息为:"<<endl;
        s.book[id].ShowData();
        if (c.book[id].getNum() != 0)
        {
            cout << "收藏夹内已包含该本书，无需再次插入" << endl;
            cout << "已有图书信息:";
            c.book[id].ShowData();
            return 0;
        }
        cout << "请输入进入时间(输入的进入时间需大于书库的进入时间):";
        int year, month, day;
        cin >> year >> month >> day;
        c.book[id].setTime(year, month, day);
        if (year > 2022 || year < 0 || month > 12 || month < 0 || day < 0 || day > 30)
        {
            cout << "输入日期不合法，请重新输入：";
            cin >> year >> month >> day;
            c.book[id].setTime(year, month, day);
        }
        if (s.book[id].getSave().getDate() > c.book[id].getSave().getDate())
        {
            cout << "输入的日期不合法请重新输入:";
            cin >> year >> month >> day;
            c.book[id].setTime(year, month, day);
        }
        if (c.book[id].getNum() == 0)
        {
            c.book[id] = s.book[id];
        }
        else
        {
            c.book[id].setNum(c.book[id].getNum() + s.book[id].getNum());
        }
        cout << "成功插入" << endl;
        return 1;
    }
    return 1;
}