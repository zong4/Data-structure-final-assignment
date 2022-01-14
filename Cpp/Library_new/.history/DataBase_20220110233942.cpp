#include "DataBase.h"
#include "time.h"

#include <cstring>
using namespace std;

DataBase::DataBase(int size)
{
    book = new Book[size];
}

DataBase::~DataBase()
{
    delete[] book;
}
DataBase::DataBase(Book *B,int size){
    this->book=new Book[size];
    for(int i=1;i<size;i++){
        this->book[i]=B[i];
    }

}
int DataBase::insert(Book b)
{

    if (book[b.getid()].getNum() == 0)
    {
        book[b.getid()] = b;
    }
    else
    {
        book[b.getid()].getNum() += b.getNum();
    }
    return 1;
}
int DataBase::Delete(int id)
{
    if (Idsearch(id).getNum() == 0 || !judgeId(id))
    {
        return 0;
    }
    book[id].getNum() = 0;
    return 1;
}
Book DataBase::Idsearch(int id)
{
    if (!judgeId(id))
    {
        cout << "输入的ID有误" << endl;
    }
    if (book[id].getNum() != 0)
    {
        return book[id];
    }
    else
    {
        Book b;
        return b;
    }
}
//快速排序
//当输入0时，收藏时间排序，当输入1时，价格排序，当输入其他数字时，ID来排序
void quickSort(Book s[], int l, int r, int choice)
{
    double* a = NULL;
    if (!a)
    {
        a = new double[r + 1];
        for (int i = 1; i <= r; i++)
        {
            if (choice == 0)
                a[i] = s[i].getSave().getDate();
            else if (choice == 1)
                a[i] = s[i].getPrice();
            else
                a[i] = s[i].getid();
        }
    }
    if (l < r)
    {
        int i = l, j = r;
        double  x = a[l];
        while (i < j)
        {
            while (i < j && a[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if (i < j){
                a[i++] = a[j];
                s[i++] = s[j];
            }
            while (i < j && a[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if (i < j){
                s[j--] = s[i];
                a[j--] = a[i];
            }
        }
        a[i] = x;
        s[i] = s[l];
        quickSort(s, l, i - 1, choice); // 递归调用
        quickSort(s, i + 1, r, choice);
    }
}
DataBase DataBase::Savesort()
{
    quickSort(book, 1, size - 1, 0);
    return DataBase(this->book,this->size);
}
DataBase DataBase::Pricesort()
{
    quickSort(book, 1, size - 1, 1);
    return DataBase(this->book,this->size);
}
DataBase DataBase::Idsort()
{
    quickSort(book, 1, size - 1, 2);
    return DataBase(this->book,this->size);
}
DataBase DataBase::Idsearch(int id1, int id2)
{
    DataBase D(id2 + 1);
    if (!judgeId(id1) || !judgeId(id2))
    {
        cout << "输入的ID有误" << endl;
    }
    for (int i = id1; i <= id2; i++)
    {
        D.book[i] = this->book[i];
    }
    return D;
}
DataBase DataBase::Timesearch(Time t1, Time t2)
{
    DataBase D(this->size);
    for (int i = 1; i < size; i++)
    {
        if (book[i].SaveTime.getDate() >= t1.getDate() && book[i].SaveTime.getDate() <=t2.getDate())
        {
            D.insert(book[i]);
        }
    }
    return D;
}
DataBase DataBase::Authorsearch(string name)
{
    DataBase D(this->size);
    for (int i = 1; i < size; i++)
    {
        if (book[i].author == name)
        {
            D.insert(book[i]);
        }
    }
    return D;
}

bool DataBase::judgeId(int id)
{
    if (id >= 1 && id <= 10000)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void DataBase::show(){
    for(int i=1;i<size;i++){
        if(book[i].getNum()!=0){
            cout << "图书号为:" << book[i].getid() << "  " << "书名为:" << book[i].getName() << "  " << "作者为:" << book[i].GetAuthor() << "  " << "出版社为:" << book[i].getAddress() << "  " << "出版日期为:"; 
            book[i].getWrite().show();
            cout << "  " << "价格为:" << book[i].getPrice() << "  " << "数量为:" << book[i].getNum() << "  " << "购买金额为:" << book[i].getNum()*book[i].getPrice() << "  " << "加入购物车日期为:";
            book[i].getSave().show();
            cout << endl;
        }
    }
}
