/*****************************************************
*   ��������librarian.h                              *
*   ���ܣ�  ͼ�����Ա��¼                           *
******************************************************/

class Librarian: public object 
{
private:
	long ID;         //��ʶ
	char name[20];   //����
	char passwd[9];  //����
public:
	Librarian(long ID, const char * name):ID(ID) 
	{
		strcpy(this->name,name);
		strcpy(passwd,"abc");
	}
	char login() //��¼
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