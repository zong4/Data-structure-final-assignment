/*****************************************************
*   程序名：librarian.h                              *
*   功能：  图书管理员登录                           *
******************************************************/

class Librarian: public object 
{
private:
	long ID;         //标识
	char name[20];   //姓名
	char passwd[9];  //口令
public:
	Librarian(long ID, const char * name):ID(ID) 
	{
		strcpy(this->name,name);
		strcpy(passwd,"abc");
	}
	char login() //登录
	{
		char pw[9];
		for(int i=0; i<3; ++i)
		{
			cout<<"Enter password:";
			cin>>pw;
			if(strcmp(pw,passwd)==0) 
				return 'X';
		}
		cout<<"Login fail!"<<endl;
		return 'E';
	}
};