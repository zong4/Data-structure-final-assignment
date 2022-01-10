#include "DataBase.h"
#include "time.h"

#include <cstring>
using namespace std;
double d[1000];


DataBase::DataBase(int size)
{
    book = new Book[size];
}

DataBase::~DataBase()
{
    delete[] book;
}
DataBase::DataBase(Book *B, int size)
{
    this->book = new Book[size];
    for (int i = 1; i < 500; i++)
    {
        this->book[i] = B[i];
    }
}
int DataBase::insert(Book b)
{
    cout<<"请输入进入时间（输入的进入时间需大于书本的出版时间）:";
    int year,month,day;
    cin>>year>>month>>day;
    b.setTime(year,month,day);
    if(year>2022||year<0||month>12||month<0||day<0||day>30)
        {
                cout<<"输入日期不合法，请重新输入：";
                cin>>year>>month>>day;
                b.setTime(year,month,day);
        }
    if(b.getWrite().getDate()>b.getSave().getDate())
    {
        cout<<"输入的收藏日期小于出版日期，不合法请重新输入:";
        cin>>year>>month>>day;
        b.setTime(year,month,day);
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
    cout<<"成功插入"<<endl;
    return 1;
}
int DataBase::Delete(int id)
{
    if (Idsearch(id).getNum() == 0 || !judgeId(id))
    {
        cout<<"删除失败"<<endl;
        return 0;
    }
    else{
        cout<<"所删图书信息为:"<<endl;
        book[id].ShowData();
        cout<<"是否确定选择删除，是请输入yes:";
        string choice;
        cin>>choice;
        if(choice=="yes"||choice=="YES"||choice=="Yes"){
            book[id].setNum(0);
            cout<<"删除成功"<<endl;
        }
        else{
            cout<<"未删除该图书"<<endl;
            return 0;
        }
    }
    return 1;
}
Book DataBase::Idsearch(int id)
{
    if (!judgeId(id))
    {
        cout << "输入的ID有误,请重新输入ID：" << endl;
        cin>>id;
    }
    if (book[id].getNum() != 0)
    {
        return book[id];
    }
    else
    {
        cout<<"该书本没找到!"<<endl;
        Book b;
        return b;
    }
}
//快速排序
//当输入0时，收藏时间排序，当输入1时，价格排序，当输入其他数字时，ID来排序
void quickSort(Book s[], int l, int r, int choice)
{
        // double a[100000];
        // for (int i = l; i <= r; i++)
        // {
        //     if (choice == 0)
        //         a[i] = s[i].getSave().getDate();
        //     else if (choice == 1)
        //         {a[i] = s[i].getPrice();
        //         cout<<s[i].getPrice()<<endl;}
        //     else
        //         a[i] = s[i].getid();
        // }
    double temp;
    Book book_temp;
    // for(int n=l;n<r;n++)s
    r=4;
    for(int i=l;i<r;i++)
    {
        for(int j=l;j<r-i+l;j++)
        {
            if(d[j]<d[j+1])
            {
                temp=d[j];
                d[j]=d[j+1];
                d[j+1]=temp;
                book_temp=s[j];
                s[j]=s[j+1];
                s[j+1]=book_temp;
            }
        }
    }
}
void DataBase::Savesort()
{
    for(int i=1;i<500;i++){
        d[i]=book[i].getSave().getDate();
    }

    quickSort(book, 1, 499, 0);
    show();
}
void DataBase::Pricesort()
{
     for(int i=1;i<500;i++){
        d[i]=book[i].getPrice();
    }
    quickSort(book, 1, 499, 1);
    show();
}
void DataBase::Idsort()
{
     for(int i=1;i<500;i++){
        d[i]=book[i].getid();
    }
    quickSort(book, 1, 499, 2);
    show();
}
void DataBase::Idsearch(int id1, int id2)
{
    bool flag=false;
    if (!judgeId(id1) || !judgeId(id2))
    {
        cout << "输入的ID有误,请重新输入两个ID：" << endl;
        cin>>id1>>id2;
    }
    for (int i = id1; i <= id2; i++)
    {
        book[i].ShowData();
        flag=true;
    }
    if(!flag)cout<<"ID查找失败"<<endl;
}
void DataBase::Timesearch(Time t1, Time t2)
{
    bool flag=false;
    for (int i = 1; i < 500; i++) // size
    {
        if (book[i].getSave().getDate() >= t1.getDate() && book[i].getSave().getDate() <= t2.getDate())
        {
            book[i].ShowData();
            flag=true;
        }
    }
    if(!flag)cout<<"时间查找失败"<<endl;
    
}
void DataBase::Authorsearch(string name)
{
    bool flag=false;
    for (int i = 1; i < 500; i++) // size
    {
        if (book[i].GetAuthor() == name)
        {
            book[i].ShowData();
            flag=true;
        }
    }
    if(!flag)cout<<"作者查找失败"<<endl;
}

bool DataBase::judgeId(int id)
{
    if (id >= 1 && id <= 500)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void DataBase::show()
{
    int num=0;
    for (int i = 1; i < 500; i++) // size
    {
        num+=book[i].getNum();
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
                 << "加入购物车日期为:";
            book[i].getSave().show();
            cout << endl;
        }
    }
    if(!num)cout<<"=================================空==========================================="<<endl;
}
