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
DataBase::DataBase(Book *B){
    this->book=new Book[this->size]; // '*<unknown>.DataBase::size' is used uninitialized in this function [-Wuninitialized]
    for(int i=1;i<size;i++){
        this->book[i]=B[i];
    }

}
int DataBase::insert(Book b)
{
    int i = 1; // unused variable 'i' [-Wunused-variable]
    if (book[b.id].num == 0)
    {
        book[b.id] = b;
    }
    else
    {
        book[b.id].num += b.num;
    }
    return 1;
}
int DataBase::Delete(int id, int n)
{
    if (Idsearch(id).num == 0 || !judgeId(id))
    {
        return 0;
    }
    book[id].num = book[id].num - n;
    if (book[id].num <= 0)
    {
        book[id].num = 0;
    }
    return 1;
}
Book DataBase::Idsearch(int id)
{
    if (!judgeId(id))
    {
        cout<<"输入的id不在搜索范围内"<<endl;
    }
    if (book[id].num != 0)
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
void quickSort(Book s[], int l, int r, int choice,int *a)
{
    if (!a)
    {
        a = new int[r + 1];
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
        int i = l, j = r, x = a[l];
        while (i < j)
        {
            while (i < j && a[j] >= x) // 从右向左找第一个小于x的数
                j--;
            if (i < j) // this 'if' clause does not guard... [-Wmisleading-indentation]
                a[i++] = a[j];
                s[i++] = s[j];
            while (i < j && a[i] < x) // 从左向右找第一个大于等于x的数
                i++;
            if (i < j) // this 'if' clause does not guard... [-Wmisleading-indentation]
                s[j--] = s[i];
                a[j--] = a[i];
        }
        a[i] = x;
        s[i] = s[l];
        quickSort(s, l, i - 1, choice,a); // 递归调用
        quickSort(s, i + 1, r, choice,a);
    }
}
DataBase DataBase::Savesort()
{
    int *a;
    quickSort(book, 1, size - 1, 0,a); // 'a' is used uninitialized in this function [-Wuninitialized]
    return DataBase(this->book);
}
DataBase DataBase::Pricesort()
{
    int *a;
    quickSort(book, 1, size - 1, 1,a); // 'a' is used uninitialized in this function [-Wuninitialized]
    return DataBase(this->book);
}
DataBase DataBase::Idsort()
{
    int *a;
    quickSort(book, 1, size - 1, 2,a); // 'a' is used uninitialized in this function [-Wuninitialized]
    return DataBase(this->book);
}
DataBase DataBase::Idsearch(int id1, int id2)
{
    DataBase D(id2 + 1);
    if (!judgeId(id1) || !judgeId(id2))
    {
        cout<<"输入的id不在搜索范围内"<<endl;
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
        if (book[i].SaveTime.getDate() > t1.getDate() && book[i].SaveTime.getDate() < t2.getDate())
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