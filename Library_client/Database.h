/********************************************************
*   程序名：database.h                                   *
*   功能：  数据库打开与保存，数据的插入、查询、删除    *
*********************************************************/

template <class T>
class Database: public object
{
private:
	fstream File;
	char FileName[40];         //文件名
	long FileLen, rec_size;    //文件长度，记录大小
	typedef map<long,T,less<long> > mtype;
	mtype RecMap;              //数据记录库
public:
	Database(const char * FileName);
	~Database() {SaveMap();}
	void Insert(T &);
	void Delete(long);
	T * Query(long);
	T * QueryName(const char *);
	void SaveMap();
	void ShowAllData();
};

template <class T>
Database<T>::Database(const char * FileName)
{
	strcpy(this->FileName, FileName);
	File.open(FileName,ios::in|ios::binary);
	rec_size=sizeof(T);
	if(File.is_open()) {
		File.seekg(0,ios::end);
		if((FileLen=File.tellg())>0)
		{
			T Object;
			File.seekg(0,ios::beg);
			do {
				File.read((char *) & Object, rec_size);
				RecMap.insert(typename mtype::value_type(Object.GetID(), Object));
			} while(File.tellg()<FileLen);
		}
		File.close();
	}
}

template <class T>
void Database<T>::SaveMap()
{
	typename mtype::const_iterator iter;
	T Object;
	File.open(FileName,ios::out|ios::binary|ios::trunc);
	for(iter = RecMap.begin(); iter!=RecMap.end();++iter)
		File.write((char *) & iter->second,rec_size);
	File.close();
}

template <class T>
void Database<T>::Insert(T & Object)
{

	RecMap.insert(typename mtype::value_type(Object.GetID(), Object));
	cout<<typeid(T).name()<<" inserted"<<endl;
}

template <class T>
T * Database<T>::Query(long ObjID)
{
	typename mtype::iterator iter;
	iter=RecMap.find(ObjID);
	if(iter==RecMap.end())
	{
		cout<<typeid(T).name()<<" not found!"<<endl;
		return NULL;
	} else
		return &(iter->second);
}

template <class T>
T * Database<T>::QueryName(const char * ObjName)
{
	typename mtype::iterator iter;
    for(iter=RecMap.begin(); iter!=RecMap.end();++iter)
		if(strstr((iter->second).GetName(),ObjName)!=NULL)
		{
			//cout<<"find a name: "<<(iter->second).GetName()<<endl;
			return &(iter->second);
		}
    cout<<ObjName<<" in "<<typeid(T).name()<<" not found!"<<endl;
	return NULL;
}
template <class T>
void Database<T>::Delete(long ObjID)
{
	Query(ObjID);
	RecMap.erase(ObjID);
}

template <class T>
void Database<T>::ShowAllData()
{
	typename mtype::iterator iter;
	T Object;
	cout<<"Data in "<<typeid(T).name()<<":"<<endl;
	for(iter=RecMap.begin(); iter!=RecMap.end(); ++iter) {
		(iter->second).ShowData();
	}
}
