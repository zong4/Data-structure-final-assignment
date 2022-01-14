#include<iostream>
#include<fstream>

#include"DataBase.h"
#include"Collect.h"
#include"Set.h"

// Shop shop(1);

int main()
{
    Book b1(1,"ee", "rr", "ee", 2020, 3, 0, 35, 1);
    Book b2(2,"r", "rt", "r", 2014, 7, 0, 39.3, 1);
    Book b3(3,"r", "rt", "rwq", 2018, 8, 0, 36.8, 1);
    Book b4(4,"r", "rrt", "rrr", 2014, 7, 0, 47.6, 1);
    Shop shop(100);
    Set set(100);
    Collect col(100);

    shop.insert(b1);
    set.insert(b1);
    //�ղؼ���ϵͳ���ܲ���
    //2.1.1�ղ�ָ��ͼ��
    col.insert(b1);
    b1.setSaveTime(2020, 1, 7);
    col.insert(b2);
    b2.setSaveTime(2020, 1, 10);
    col.insert(b3);
    b3.setSaveTime(2020, 1, 9);
    col.insert(b4); 
    b4.setSaveTime(2020, 1, 8);
    col.show();
    // //2.1.2��ѯָ��ͼ��
    //  col.Authorsearch("rr").show();//������������
    // col.Idsearch(1).ShowData();//���������������ΪIDΨһ������ֻ�����һ����
    // col.Timesearch(Time(2020, 1, 7), Time(2020, 1, 8)).show();//�����ղ�ʱ������
    // //2.1.3��������ʾ����ͼ��
    // col.Savesort().show();//�����ղ�ʱ������
    // //2.1.4���۸��С��ʾ����ͼ��
    // col.Pricesort().show();
    // //2,1,5�Ƴ��ղؼ�
    // col.Delete(1);//ɾ��id���Ϊ1��ͼ��
    // col.show();
    // //2.1.6���빺�ﳵ
    // CollecttoShop(2, shop, col);//��id���Ϊ2��ͼ���ƶ������ﳵ
    // col.show();
    // shop.show();
    // //���ﳵ��ϵͳ���ܲ���
    // //2.2.1ֱ�Ӽ��빺�ﳵ
    // shop.insert(b1);
    // b1.setSaveTime(2020, 1, 7);
    // shop.insert(b2);
    // b2.setSaveTime(2020, 1, 8);
    // shop.insert(b3);
    // b3.setSaveTime(2020, 1, 9);
    // shop.insert(b4);
    // b4.setSaveTime(2020, 1, 10);
    // shop.show();
    // //2.2.2��ѯָ��ͼ��
    // shop.Authorsearch("fsf").show();//������������
    // shop.Idsearch(1).ShowData();//���������������ΪIDΨһ������ֻ�����һ����
    // shop.Timesearch(Time(2020, 1, 7), Time(2020, 1, 8)).show();//�����ղ�ʱ������
    // //2.2.3�޸Ĺ�������
    // shop.changeNum(2, 10);//��2����Ŀ�Ĺ��������޸�Ϊ10��
    // shop.showpay(2);
    // //2.2.4ɾ��ָ���鵽�ղؼ�
    // ShoptoCollect(2, shop, col);//��id���Ϊ2��ͼ���ƶ����ղؼ�
    // shop.show();
    // col.show();
    // //2.2.5ֱ��ɾ��ָ��ͼ��
    // shop.Delete(1);
    // shop.show();//ֱ��ɾ��id���Ϊ1��ͼ��
    // //2.2.6��ͼ�����ʾ����ͼ��
    // shop.Idsort();
    // shop.show();
    // cout << "sgg" << shop.Countnum() << "gdeg" << "  " << "fsf:" << shop.Countprice() << endl;
    // //�����ϵͳ
    // //2.3.1����ָ��ͼ��
    // set.insert(b1);
    // b1.setSaveTime(2020, 1, 7);
    // set.insert(b2);
    // b2.setSaveTime(2020, 1, 7);
    // set.insert(b3);
    // b3.setSaveTime(2020, 1, 9);
    // set.insert(b4);
    // b4.setSaveTime(2020, 1, 10);
    // set.show();
    // //2.3.2��������ͼ��
    // fstream file("book.txt");
    // set.readfile(file);
    // set.show();
    // //2.3.3ɾ��ָ��ͼ��
    // set.Delete(2);//ɾ��IDΪ2��ͼ��
    // set.show();
    // //2.3.4����ɾ��ͼ��
    // Time t(2020, 1, 9);
    // Time t1(2020, 1, 10);
    // set.deleteAll(t);
    // set.show();
    // //2.3.5��ʾͼ��
    // set.Idsearch(4, 5);
    // set.show();//����ͼ�����ʾ
    // set.Timesearch(t, t1);
    // set.show();//���ݽ��빺�ﳵʱ������ʾ
    // set.Authorsearch("sgs");
    // set.show();
    system("pause");
    return 0;
}
