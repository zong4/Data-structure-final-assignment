/*****************************************************
*   程序名：ReaderData.h                               *
*   功能：  读者数据以及借书、还书操作                   *
******************************************************/

class ReaderData: public object 
{
protected:
	long PIN;                //借书证号
	char name[20];
	long BookList[LIMIT];   //书列表
	Date BorrowDate[LIMIT]; //借书日期
	int num;                //借阅图书数
public:
	ReaderData(int PIN, const char * name)
	{
		SetID(PIN);
		SetName(name);
		num=0;
		for(int i=0; i<LIMIT; ++i)
			BookList[i]=0;
	}
	ReaderData() 
	{
		PIN=0;
		num=0;
		for(int i=0; i<LIMIT; ++i)
			BookList[i]=0;
	}
	void SetID(long PIN ){this->PIN=PIN;}
	void SetName(const char * i_name) {strcpy(name, i_name);}
	long GetID() { return PIN;}
	const char * GetName() { return name;}
	int GetNum() { return num;}
	long BorrowBook(long);
	void ShowData();
	long ReturnBook(long);
};
long ReaderData::ReturnBook(long BookID)//还书
{
	for(int i=0; i<LIMIT; ++i)
		if(BookList[i]==BookID)
		{
			BookList[i]=0;
			--num;
			return BookID;
		}
	return 0;
}
void ReaderData::ShowData()
{ 
	cout<<PIN<<"\t"<<name<<endl;
	for(int i=0; i<LIMIT; ++i) 
	{
		if(BookList[i]) 
		{
			cout<<i+1<<": "<<BookList[i]<<"\t";
			BorrowDate[i].display();
		}
	}
}
long ReaderData::BorrowBook(long BookID)//借书
{
	for(int i=0; i<LIMIT; ++i)
		if(BookList[i]==0) 
		{
			BookList[i]=BookID;
            BorrowDate[i]=Date();
			num++;
			return BookID;
		}
	cout<<"Book reach the limit!"<<endl; //图书超过了限额
	return 0;
}