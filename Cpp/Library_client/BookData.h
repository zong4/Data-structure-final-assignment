/*****************************************************
*   程序名：BookData.h                               *
*   功能：  图书数据以set、get操作                   *
******************************************************/

class BookData: public object 
{
private:
	long BookID;
	char name[40];
	State state;    //enum State {READER, LIB, SHELF} 
	long PIN;
public:
	BookData(long BookID, const char * name, State state=SHELF, long PIN=0)
	{
		SetID(BookID);
		SetName(name);
		SetState(state);
		SetPIN(PIN);
	}
	BookData() {BookID=0; PIN=0; }
	const long GetID() { return BookID;}
	const char * GetName() { return name;}
    State GetState() { return state;}
    long GetPIN() { return PIN;}
	void ShowData() {cout<<BookID<<"\t"<<name<<"\t"
		<<state<<"\t"<<PIN<<endl;}
	void SetID(long BookID) {this->BookID=BookID;}
	void SetName(const char *i_name) {strcpy(name, i_name);}
	void SetState(State state) { this->state=state;}
	void SetPIN(long PIN) {this->PIN=PIN;}
};