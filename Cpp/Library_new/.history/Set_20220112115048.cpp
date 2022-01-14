#include "Set.h"
#include <fstream>
int Set::deleteAll(Time &t)
{
    bool flag = false;
    for (int i = 1; i < size; i++)
    {
        if (this->book[i].getSave().getYear() == t.getYear() && this->book[i].getSave().getMonth() == t.getMonth() && this->book[i].getSave().getDay() == t.getDay())
        {
            book[i].setNum(0); //将数量置0，表示删除
            flag = true;
        }
    }
    if(flag){
        return 1;
    }else{
        return 0;
    }
}
void Set::show() {
    cout << "书库信息:";
    DataBase::show();
}
int Set::readfile(fstream& file) {
    int id;
    string name;    //书名
    string author;  //作者姓名
    string address; //出版社名称
    double price;       //价格
    int year,month,day,num;
    while (cin >> id) {
        cin >> name >> author >> address >> year >> month >> day >> price >> num;
        Book b1(id, name, author, address, year, month, day, price, num);
        b1.setSaveTime(2020, 1, 11);
        insert(b1);
    }
    return 1;
}