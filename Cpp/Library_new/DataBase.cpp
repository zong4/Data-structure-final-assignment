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
int DataBase::insert(Book b)
{
    int i = 1;
    if(book[b.id].num==0){
        book[b.id]=b;
    }
    else{
        book[b.id].num+=b.num;
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
        return;
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
void quickSort(int s[], int l, int r)
{
	if (l< r)
	{      
		int i = l, j = r, x = s[l];
		while (i < j)
		{
			while(i < j && s[j]>= x) // 从右向左找第一个小于x的数
				j--; 
			if(i < j)
				s[i++] = s[j];
			while(i < j && s[i]< x) // 从左向右找第一个大于等于x的数
				i++; 
			if(i < j)
				s[j--] = s[i];
		}
		s[i] = x;
		quickSort(s, l, i - 1); // 递归调用
		quickSort(s, i + 1, r);
	}
}
DataBase DataBase::Savesort(){
    quickSort(book->SaveTime.getDate(),1,size-1);
    return DataBase;
}
DataBase DataBase::Pricesort(){
    quickSort(book->price,1,size-1);
    return DataBase;
}
DataBase DataBase::Idsort(){
    quickSort(book->id,1,size-1);
    return DataBase;
}
DataBase DataBase::Idsearch(int id1, int id2)
{
    DataBase D(id2 + 1);
    if (!judgeId(id1) || !judgeId(id2))
    {
        return;
    }
    for (int i = id1; i <= id2; i++)
    {
        D.book[i]=this->book[i];
    }
    return D;
}
DataBase DataBase::Timesearch(Time t1, Time t2)
{
    DataBase D(this->size);
    for(int i=1;i<size;i++){
        if(book[i].SaveTime.getDate()>t1.getDate()&&book[i].SaveTime.getDate()<t2.getDate()){
            D.insert(book[i]);
        }
    }
    return D;
}
DataBase DataBase::Authorsearch(string name)
{
    DataBase D(this->size);
    for(int i=1;i<size;i++){
        if(book[i].author==name){
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