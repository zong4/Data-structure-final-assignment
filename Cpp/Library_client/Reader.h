/**************************************************
*   ��������reader.h                              *
*   ���ܣ�  ����ѡ�������                        *
**************************************************/

class Reader: public object 
{
private:
	long PIN;           //���߽��鿨��
	long BookID[LIMIT];	//�鳵�д洢�����
	int num;            //�鳵�������Ŀ
public:		
	Reader(long PIN=0, const int num=0):PIN(PIN),num(num) {}
	int AddBook(const long BookID) //����ѡ���鳵��
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
	long CheckOut() {             //����
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