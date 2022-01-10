#include "Shop.h"
#include "Collect.h"

int ShoptoCollect(int id, Shop &s, Collect &c)
{
    if (!s.judgeId(id))
    {
        cout << "输入的ID有误,请重新输入ID：" << endl;
        cin>>id;
    }
    if(s.book[id].getNum()==0)cout<<"插入失败，该购物车内没有该图书号对应的图书"<<endl;
    else{
        if(c.book[id].getNum()!=0){
            cout<<"收藏夹内已包含该本书，无需再次插入"<<endl;
            cout<<"已有图书信息:";
            c.book[id].ShowData();
            return 0;
        }
        c.insert(s.book[id]);
        s.Delete(id);
    }
    return 1;
}
int Shop::Countnum()
{
    for (int i = 1; i < size; i++)
    {
        if (book[i].getNum() != 0)
        {
            Allnum += book[i].getNum();
        }
    }
    return Allnum;
}
double Shop::Countprice()
{
    for (int i = 1; i < size; i++)
    {
        if (book[i].getNum() != 0)
        {
            Allprice += book[i].getNum() * book[i].getPrice();
        }
    }
    return Allprice;
}
void Shop::show()
{
    cout << "购物车:"<<endl;
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
int Shop::changeNum(int id, int num)
{
    if (!judgeId(id))
    {
        cout << "输入的ID有误,请重新输入ID：" << endl;
        cin>>id;
    }
    
    this->book[id].setNum(num);
    cout<<"数量修改成功"<<endl;
    return 1;
}
void Shop::showpay(int id)
{
    cout << "金额为:" << book[id].getNum() * book[id].getPrice() << endl;
}
