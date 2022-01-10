#include<iostream>
#include<fstream>

#include"DataBase.h"
#include"Collect.h"
#include"Set.h"

DataBase test(1000);

int main()
{
    Book b1(1,"习近平总书记教育重要论述讲义", "杨晓慧", "高等教育出版社", 2020, 3, 0, 35, 1);
    Book b2(2,"高等数学第七版下册", "王强", "高等教育出版社", 2014, 7, 0, 39.3, 1);
    Book b3(3,"高等数学辅导及习题精解", "张天德", "浙江教育出版社", 2018, 8, 0, 36.8, 1);
    Book b4(4,"高等数学第七版上册", "王强", "高等教育出版社", 2014, 7, 0, 47.6, 1);
    Shop shop(1000);
    Set set(1000);
    Collect col(1000);
    //收藏夹子系统功能测试
    //2.1.1收藏指定图书
    col.insert(b1);
    b1.setSaveTime(2020, 1, 7);
    col.insert(b2);
    b2.setSaveTime(2020, 1, 8);
    col.insert(b3);
    b3.setSaveTime(2020, 1, 9);
    col.insert(b4); 
    b4.setSaveTime(2020, 1, 10);
    col.show();
    //2.1.2查询指定图书
    col.Authorsearch("杨晓慧").show();//根据作者搜索
    col.Idsearch(1).ShowData();//根据书号搜索，因为ID唯一，所以只会出来一本书
    col.Timesearch(Time(2014, 6, 0), Time(2018, 0, 0)).show();//根据收藏时间搜索
    //2.1.3按日期显示所有图书
    col.Savesort().show();//根据收藏时间排序
    //2.1.4按价格大小显示所有图书
    col.Pricesort().show();
    //2,1,5移出收藏夹
    col.Delete(1);//删除id序号为1的图书
    col.show();
    //2.1.6加入购物车
    CollecttoShop(2, shop, col);//将id序号为2的图书移动到购物车
    col.show();
    shop.show();
    //购物车子系统功能测试
    //2.2.1直接加入购物车
    shop.insert(b1);
    b1.setSaveTime(2020, 1, 7);
    shop.insert(b2);
    b2.setSaveTime(2020, 1, 8);
    shop.insert(b3);
    b3.setSaveTime(2020, 1, 9);
    shop.insert(b4);
    b4.setSaveTime(2020, 1, 10);
    shop.show();
    //2.2.2查询指定图书
    shop.Authorsearch("杨晓慧").show();//根据作者搜索
    shop.Idsearch(1).ShowData();//根据书号搜索，因为ID唯一，所以只会出来一本书
    shop.Timesearch(Time(2014, 6, 0), Time(2018, 0, 0)).show();//根据收藏时间搜索
    //2.2.3修改购买数量
    shop.changeNum(2, 10);//将2号数目的购买数量修改为10本
    shop.showpay(2);
    //2.2.4删除指定书到收藏夹
    ShoptoCollect(2, shop, col);//将id序号为2的图书移动到收藏夹
    shop.show();
    col.show();
    //2.2.5直接删除指定图书
    shop.Delete(1);
    shop.show();//直接删除id序号为1的图书
    //2.2.6按图书号显示所有图书
    shop.Idsort();
    shop.show();
    cout << "一共有" << shop.Countnum() << "本书" << "  " << "总金额为:" << shop.Countprice() << endl;
    //书库子系统
    //2.3.1增加指定图书
    set.insert(b1);
    b1.setSaveTime(2020, 1, 7);
    set.insert(b2);
    b2.setSaveTime(2020, 1, 7);
    set.insert(b3);
    b3.setSaveTime(2020, 1, 9);
    set.insert(b4);
    b4.setSaveTime(2020, 1, 10);
    set.show();
    //2.3.2批量增加图书
    fstream file("book.txt");
    set.readfile(file);
    set.show();
    //2.3.3删除指定图书
    set.Delete(2);//删除ID为2的图书
    set.show();
    //2.3.4批量删除图书
    Time t(2020, 1, 7);
    Time t1(2020, 1, 9);
    set.deleteAll(t);
    set.show();
    //2.3.5显示图书
    set.Idsearch(2, 3);
    set.show();//根据图书号显示
    set.Timesearch(t, t1);
    set.show();//根据进入购物车时间来显示
    set.Authorsearch("杨晓慧");
    set.show();
    return 0;
}
