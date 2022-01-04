/*****************************************************
*   ��������date.h                                   *
*   ���ܣ�  ����ǰ���ڡ��ж������Ƿ���Ч             *
******************************************************/
#include<ctime>

#ifdef __cplusplus
extern "C" {
#endif


using namespace std;
class Date : public object //����һ��Date�࣬  
{  
    int year,month,day;//   
    int DayOfMonth(int y,int m) const;//����һ���µ�������  
public:  
    Date() //���캯������ʼ��Ĭ�ϵ�����   
    { 
		time_t curtime=time(NULL); 
		tm tim =*localtime(&curtime);  
		day=tim.tm_mday; 
		month=tim.tm_mon+1; 
		year=tim.tm_year+1900; 
    }  
    Date(int y,int m,int d)  
        :year(y),month(m),day(d)//�����ڸ�ֵ���ж���Ч�����ڡ�  
    {  
        if((y<=0)||(m<=0 || m>12)||(d<=0 || d>DayOfMonth(y,m)))  
        {  
			cout<<"Invalid date, data has been set to 1900-1-1"<<endl; 
			year = 1900;  
            month = day = 1;  
        }  
    }  
    virtual ~Date()//������������  
    {  
    }  
    int GetYear()const//�������  
    {  
        return year;  
    }  
    int GetMonth()const   //�����·�  
    {  
        return month;  
    }  
    int GetDay()const   //��������  
    {  
        return day;  
    }  
    bool IsLeapyear() const    //�ж��Ƿ�Ϊ���ꡣ  
    {  
	   return year%400?(year%100?(year%4?false:true):false):true; 
    }  
    bool IsLeapyear(const int y) const //�ж��Ƿ�Ϊ���ꡣ  
    {  
        return y%400?(y%100?(y%4?false:true):false):true;  
    }  
    void display() const  //�������ֵ  
    {  
        std::cout<<year<<"-"<<month<<"-"<<day<<std::endl;  
    }
};
  
int Date::DayOfMonth(int y,int m) const  
{  
    int d = 0;  
    switch(m)  
    {  
	 case 1: case 3: case 5: case 7: case 8: case 10: case 12:  
        d = 31;  
        break;  
	 case 4: case 6: case 9: case 11:  
        d = 30;  
        break;  
	 case 2:  
        d = 28 + IsLeapyear(y);  
        break;  
    }  
    return d;  
}

#ifdef __cplusplus
}  // end extern "C"
#endif