#include "Collect.h"
#include "Shop.h"

int CollecttoShop(int id, Shop &s, Collect &c)
{
    if (!c.judgeId(id))
    {
        cout << "输入的ID有误,请重新输入ID：" << endl;
        cin>>id;
    }
    if(c.book[id].getNum()==0)cout<<"插入失败,该收藏夹内没有该图书号对应的图书"<<endl;
    else{
        cout<<"找到该图书:";
        c.book[id].ShowData();
        s.insert(c.book[id]);
    }
    // c.Delete(id);
    return 1;
}
void Collect::show()
{
    cout << "收藏夹:"<<endl;
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
                 << "加入收藏夹日期为:";
            book[i].getSave().show();
            cout << endl;
        }
    }
    if(!num)cout<<"=================================空==========================================="<<endl;
}
