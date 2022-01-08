/**************************************************
*   程序名：reader.h                              *
*   功能：  读者选书与借书                        *
**************************************************/

class Reader: public object 
{
private:
	long PIN;           //读者借书卡号
	long BookID[LIMIT];	//书车中存储的书号
	int num;            //书车中书的数目
public:		
	Reader(long PIN=0, const int num=0):PIN(PIN),num(num) {}
	int AddBook(const long BookID) //将书选入书车中
	{
		if(num<LIMIT) 
		{
			this->BookID[num]=BookID;
			cout<<"Book "<<BookID<<" added!"<<endl;
			num++;
			return 1;
		} else
			cout<<"Cart full!"<<endl;
		return 0;
	}
	long CheckOut() {             //借书
		--num;
        return BookID[num];
	}
	void ShowCart() 
	{
		for(int i=0; i<num; ++i) 
			cout<<BookID[i]<<endl;
	}
	int GetNum() {return num;}
};