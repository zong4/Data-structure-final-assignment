#include <iostream>
#include <fstream>

#include "DataBase.h"
#include "Collect.h"
#include "Set.h"

Shop shop(500);
Collect col(500);
Set set(500);

void printCommand();
void handleCommand();

int main()
{
    while (true)
    {
        handleCommand();
    }

    return 0;
}
void handleCommand()
{
    string command;
    // command="";
    // cout<<command<<endl;Col
    cout << "==================" << endl;
    cout << "| [1]收藏夹子系统  |" << endl;
    cout << "| [2]购物车子系统  |" << endl;
    cout << "| [3]书库子系统    |" << endl;
    cout << "| [4]退出          |" << endl;
    cout << "=================" << endl;
    cout<<"请输入选项:";
    getline(cin, command);
    if(command==""){
        getline(cin, command);
    }
    if (command == "1")
    {
        while(1)
        {
        cout << "============================收藏夹子系统====================================" << endl;
        cout << "| [1]Collect add          : 将书库指定图书号的图书加入到收藏夹里                    |" << endl;
        cout << "| [2]Collect IDsearch1    : 搜索指定图书号的图书                              |" << endl;
        cout << "| [3]Collect IDsearch2    : 搜索指定图书号范围的图书                            |" << endl;
        cout << "| [4]Collect Timesearch   : 搜索指定收藏时间范围内的图书                        |" << endl;
        cout << "| [5]Collect Authorsearch : 搜索指定作者的图书                                  |" << endl;
        cout << "| [6]Collect Timesort     : 按日期从大到小显示所有图书                                  |" << endl;
        cout << "| [7]Collect Pricesort    : 按价格从大到小显示所有图书                                  |" << endl;
        cout << "| [8]Collect Delete       : 移出收藏夹                                         |" << endl;
        cout << "| [9]Collect show         : 展示收藏夹信息                                     |" << endl;
        cout << "| [10]Collect addtoShop   : 加入购物车内                                      |" << endl;
        cout << "| [11]Collect IDsort      : 根据ID从大到小显示                                      |" << endl;
        cout << "| [12]exit                ： 退出                                              |" << endl;
        cout << "============================================================================="<<endl;
        cout<<"请输入选项:";
        cin >> command;
        if (command == "1")
        {
            // int id;         //图书号
            // string name;    //书名
            // string author;  //作者姓名
            // string address; //出版社名称
            // Time WriteTime; //出版日期
            // double price;   //价格
            // Time SaveTime;
            // int year, month, day;
            // int num;
            // cout << "请输入图书号（输入小于500大于0的整数）:";
            // cin >> id;
            // cout << "请输入书名:";
            // cin >> name;
            // cout << "请输入作者";
            // cin >> author;
            // cout << "请输入出版社:";
            // cin >> address;
            // cout << "请输入出版年月日（如年 月 日）:";
            // cin >> year >> month >> day;
            // if(year>2022||year<0||month>12||month<0||day<0||day>30)
            // {
            //     cout<<"输入日期不合法，请重新输入：";
            //     cin>>year>>month>>day;
            // }
            // cout << "请输入价格：";
            // cin >> price;
            // cout << "请输入添加数量:";
            // cin >> num;
            // WriteTime.SetYear(year);
            // WriteTime.SetMonth(month);
            // WriteTime.SetDay(day);
            // col.insert(Book(id, name, author, address, year, month, day, price, num));
            int id;
            cout << "输入从书库要转移到购物车的图书号（1-500）:";
            cin >> id;
            SettoCollect(id, set, col);
        }
        else if (command == "2")
        {
            cout << "请输入要查找的单个ID号（1-500）:";
            int id;
            cin >> id;
            col.Idsearch(id).ShowData();
        }
        else if (command == "3")
        {
            cout << "请输入要查找的ID范围（1-500）:";
            int id1, id2;
            cin >> id1 >> id2;
            col.Idsearch(id1, id2);
        }
        else if (command == "4")
        {
            cout << "请输入要查找的时间范围(如：2020 2 1  2020 2 2):";
            int year, month, day, year2, month2, day2;
            cin >> year >> month >> day >> year2 >> month2 >> day2;
            col.Timesearch(Time(year, month, day), Time(year2, month2, day2));
        }
        else if (command == "5")
        {
            cout << "请输入要查找的作者名称:";
            string Author;
            cin >> Author;
            col.Authorsearch(Author);
        }
        else if (command == "6")
        {
            col.Savesort();
        }
        else if (command == "7")
        {
            col.Pricesort();
        }
        else if (command == "8")
        {
            int id;
            cout << "输入要删除的图书号(1-500):";
            cin >> id;
            col.Delete(id);
        }
        else if (command == "10")
        {
            int id;
            cout << "输入从收藏夹要转移到购物车的图书号（1-500）:";
            cin >> id;
            CollecttoShop(id, shop, col);
        }
        else if (command == "9")
        {
            col.show();
        }
        else if (command == "11")
        {
            col.Idsort();
        }
        else if (command == "12")
        {
            break;
        }
        else
        {
            cout << "输入的命令有误请重新输入"<<endl;
        }
        }
    }
    else if (command == "2")
    {
        while(1)
        {
        cout << "============================购物车子系统====================================" << endl;
        cout << "| [1]Shop add             :指定图书号的图书加入到购物车内                       |" << endl;
        cout << "| [2]Shop IDsearch1       :搜索书号的图书                                          |" << endl;
        cout << "| [3]Shop IDsearch2       :搜索书号范围的图书                                       |" << endl;
        cout << "| [4]Shop Timesearch      :搜索指定定收藏时间范围内的图书                                |" << endl;
        cout << "| [5]Shop Authorsearch    :搜索指定作者的图书                                     |" << endl;
        cout << "| [6]Shop changenum       :修改购买数量                                         |" << endl;
        cout << "| [7]Shop deleteAndmove   :删除指定图书并移到收藏夹                             |" << endl;
        cout << "| [8]Shop delete          :删除指定图书                                         |" << endl;
        cout << "| [9]Shop show            :按图书号显示所有图书                                  |" << endl;
        cout << "| [10]exit                :退出                                                |" << endl;
        cout << "===============================================================================" <<endl;
         cout<<"请输入选项:";
        cin >> command;
        if (command == "1")
        {
            int id;         //图书号
            string name;    //书名
            string author;  //作者姓名
            string address; //出版社名称
            Time WriteTime; //出版日期
            double price;   //价格
            Time SaveTime;
            int year, month, day;
            int num;
            cout << "请输入图书号:";
            cin >> id;
            cout << "请输入书名:";
            cin >> name;
            cout << "请输入作者：";
            cin >> author;
            cout << "请输入出版社:";
            cin >> address;
            cout << "请输入出版年月日（如2020 2 2）:";
            cin >> year >> month >> day;
            cout << "请输入价格：";
            cin >> price;
            cout << "请输入添加数量:";
            cin >> num;
            WriteTime.SetYear(year);
            WriteTime.SetMonth(month);
            WriteTime.SetDay(day);
            shop.insert(Book(id, name, author, address, year, month, day, price, num));
        }
        else if (command == "2")
        {
            cout << "请输入要查找的单个ID号(1-500):";
            int id;
            cin >> id;
            shop.Idsearch(id).ShowData();
        }
        else if (command == "3")
        {
            cout << "请输入要查找的ID范围（如 1 2 ）:";
            int id1, id2;
            cin >> id1 >> id2;
            shop.Idsearch(id1, id2);
        }
        else if (command == "4")
        {
            cout << "请输入要查找的时间范围(如：2020 2 1  2020 2 2):";
            int year, month, day, year2, month2, day2;
            cin >> year >> month >> day >> year2 >> month2 >> day2;
            shop.Timesearch(Time(year, month, day), Time(year2, month2, day2));
        }
        else if (command == "5")
        {
            cout << "请输入要查找的作者名称:";
            string Author;
            cin >> Author;
            shop.Authorsearch(Author);
        }
        else if (command == "6")
        {
            int id, num;
            cout << "输入要修改购买数量的图书号（1-500):";
            cin>>id;
            cout<<"该书的信息为:";
            shop.book[id].ShowData();
            cout<<"是否需要修改，若是则输入yes:";
            string choice;
            cin>>choice;
            if(choice=="yes"||choice=="Yes"||choice=="YES"){
                cout<<"输入要修改的购买数量:";
                cin>>num;
                shop.changeNum(id, num);
            }else{
                cout<<"取消修改数量"<<endl;
            }
        }
        else if (command == "7")
        {
            int id;
            cout << "输入要转移到收藏夹的图书号（1-500）:";
            cin >> id;
            ShoptoCollect(id, shop, col);
        }
        else if (command == "8")
        {
            int id;
            cout << "输入要删除的图书号（1-500）:";
            cin >> id;
            shop.Delete(id);
        }
        else if (command == "9")
        {
            shop.show();
        }
        else if (command == "10")
        {
            break;
        }
        else
        {
            cout << "输入的命令有误请重新输入"<<endl;
        }
    }
    }
    else if (command == "3")
    {
        while(1)
        {
        cout << "============================书库子系统====================================" << endl;
        cout << "| [1]Set add              : 将指定图书号的图书加入到书库内                        |" << endl;
        cout << "| [2]Set readFile         : 批量增加图书                                         |" << endl;
        cout << "| [3]Set Delete           : 删除指定图书                                         |" << endl;
        cout << "| [4]Set deleteAll        : 批量删除图书                                          |" << endl;
        cout << "| [5]Set IDsearch         : 把书库中某个范围的图书号的图书列表显示                  |" << endl;
        cout << "| [6]Set Timesearch       : 把书库中某个时间段（某个入库日期范围）入库的图书列表显示。|" << endl;
        cout << "| [7]Set Authorsearch     : 把书库中某个作者（指第一作者）的图书列表显示             |" << endl;
        cout << "| [8]Set show             : 展示书库信息                                          |" << endl;
        cout << "| [9]exit                 : 退出程序                                              |" << endl;
        cout << "=============================================================================  "<<endl;
        cout<<"请输入选项:";
        cin>>command;
        if (command == "1")
        {
            int id;         //图书号
            string name;    //书名
            string author;  //作者姓名
            string address; //出版社名称
            Time WriteTime; //出版日期
            double price;   //价格
            Time SaveTime;
            int year, month, day;
            int num;
            cout << "请输入图书号:";
            cin >> id;
            cout << "请输入书名:";
            cin >> name;
            cout << "请输入作者:";
            cin >> author;
            cout << "请输入出版社:";
            cin >> address;
            cout << "请输入出版年月日（如2020 2 2）:";
            cin >> year >> month >> day;
            cout << "请输入价格:";
            cin >> price;
            cout << "请输入添加数量:";
            cin >> num;
            WriteTime.SetYear(year);
            WriteTime.SetMonth(month);
            WriteTime.SetDay(day);
            set.insert(Book(id, name, author, address, year, month, day, price, num));
        }
        else if (command == "2")
        {
            cout << "输入要读取的文件名（如:book.txt）:";
            string filename;
            cin >> filename;
            set.readfile(filename);
        }
        else if (command == "3")
        {
            int id;
            cout << "输入要删除的图书号（1-500）:";
            cin >> id;
            set.Delete(id);
        }
        else if (command == "4")
        {
            cout << "输入要删除图书的所属日期:(如2020 2 2)";
            int year, month, day;
            cin >> year >> month >> day;
            set.deleteAll(Time(year, month, day));
        }
        else if (command == "5")
        {
            cout << "请输入要查找的ID范围（如1 2）:";
            int id1, id2;
            cin >> id1 >> id2;
            set.Idsearch(id1, id2);
        }
        else if (command == "6")
        {
            cout << "请输入要查找的时间范围(如：2020 2 1  2020 2 2):";
            int year, month, day, year2, month2, day2;
            cin >> year >> month >> day >> year2 >> month2 >> day2;
            set.Timesearch(Time(year, month, day), Time(year2, month2, day2));
        }
        else if (command == "7")
        {
            cout << "请输入要查找的作者名称(输入字符串如：海明威):";
            string Author;
            cin >> Author;
            set.Authorsearch(Author);
        }
        else if (command == "8")
        {
            set.show();
        }
        else if (command == "9")
        {
            break;
        }
        else
        {
            cout << "输入的命令有误请重新输入"<<endl;
        }
    }
    }
    else if (command == "4")
    {
        exit(0);
    }
    else
    {
        cout << "输入的命令有误请重新输入"<<endl;
    }
}
