/***************************************
*   AutoLibrary.cpp
*     自助图书馆                       *
****************************************/
// #pragma warning(disable : 4786) //屏蔽4786类型的警告显示
#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <map>

#include "global.h"
#include "date.h"
#include "BookData.h"
#include "ReaderData.h"
#include "database.h"
#include "librarian.h"
#include "reader.h"

#ifdef __cplusplus
extern "C" {
#endif



	using namespace std;
	int main()
	{
		Database<BookData> BookBase("books.dat");		//打开书籍数据库
		Database<ReaderData> ReaderBase("readers.dat"); //打开读者数据库
		char choice = 'X';
		while (!(choice == 'E' || choice == 'e'))
		{
			cout << "(L)ibrarian entry, (R)eader entry, Re(t)urn book, (E)xit:";
			cin >> choice;
			Librarian *mgr = NULL;
			Reader *rdr = NULL;
			switch (choice)
			{
				//==================Librarian's entry=========================
			case 'L':
			case 'l':
			{
				mgr = new Librarian(101, "yjc");
				choice = mgr->login(); //success return 'X', else return 'E'
				while (!(choice == 'E' || choice == 'e'))
				{
					cout << "(A)dd reader, Add (B)ooK, (Q)uery Reader,"
						 << "(P)ut book to shelf.(E)xit:";
					cin >> choice;
					switch (choice)
					{
						long ID;
						char name[40];
					case 'A':
					case 'a': //add reader
					{
						cout << "Give a reader PIN and input a name:";
						cin >> ID;
						cin.ignore();
						cin.get(name, 20, '\n');
						ReaderData reader(ID, name);
						ReaderBase.Insert(reader);
						break;
					}
					case 'B':
					case 'b': //add book
					{
						cout << "Input a book ID and name:";
						cin >> ID;
						cin.ignore();
						cin.get(name, 40, '\n');
						BookData book(ID, name);
						BookBase.Insert(book);
						break;
					}
					case 'Q':
					case 'q':
					{
						cout << "Input a reader's PIN:";
						cin >> ID;
						if (ReaderBase.Query(ID) == NULL)
							cout << "No such a reader!" << endl;
						else
							ReaderBase.Query(ID)->ShowData();
						break;
					}
					case 'P':
					case 'p':
						cout << "Input a book ID:";
						cin >> ID;
						if (BookBase.Query(ID) == NULL)
							cout << "No such a book!" << endl;
						else
							BookBase.Query(ID)->SetState(SHELF);
						break;
					case 'S':
					case 's':
						ReaderBase.ShowAllData();
						BookBase.ShowAllData();
						break;
					case 'e':
					case 'E':
						break;
					default:
						cout << "Unavailable function !\n";
					} //end switch
				}	  //while
				delete mgr;
				choice = 'X';
				break;
			}
			//------------------Librarian's end-----------------------
			//==================Reader' entry=========================
			case 'R':
			case 'r':
				long PIN, BookID;
				int i, t1, t2;
				char name[40];
				for (i = 0; i < 3; ++i)
				{
					cout << "Input PIN:";
					cin >> PIN;
					if (ReaderBase.Query(PIN) != NULL)
					{
						rdr = new Reader(PIN);
						break;
					}
				}
				if (i == 3)
				{
					cout << "Check in failed!" << endl;
					choice = 'E';
				}
				while (!(choice == 'E' || choice == 'e'))
				{
					cout << "(A)dd book to cart, check (O)ut, (Q)uery book by name,"
						 << "(L)ist my books (E)xit:";
					cin >> choice;
					switch (choice)
					{
					case 'A':
					case 'a': //add book to cart
						cout << "Input a book ID:";
						cin >> BookID;
						if ((BookBase.Query(BookID) != NULL) && (BookBase.Query(BookID)->GetState() == SHELF))
							if (rdr->AddBook(BookID))
								BookBase.Query(BookID)->SetState(LIB);
						break;
					case 'O':
					case 'o':								  //check out
						t1 = rdr->GetNum();					  //book number in cart
						t2 = ReaderBase.Query(PIN)->GetNum(); //book number in reader
						if (t1 > 0 && t2 < LIMIT)
						{
							cout << PIN << " " << ReaderBase.Query(PIN)->GetName()
								 << " book list" << endl;
							for (i = 0; i < t1 && i < (LIMIT - t2); ++i)
							{
								BookID = ReaderBase.Query(PIN)->BorrowBook(rdr->CheckOut());
								BookBase.Query(BookID)->SetState(READER);
								BookBase.Query(BookID)->SetPIN(PIN);
								cout << i + 1 << "\t"
									 << BookBase.Query(BookID)->GetName() << endl;
							}
							Date().display();
						}
						break;
					case 'Q':
					case 'q':
						cout << "Input a book name(part):";
						cin.ignore();
						cin.get(name, 40, '\n');
						if (BookBase.QueryName(name) != NULL)
							BookBase.QueryName(name)->ShowData();
						break;
					case 'L':
					case 'l':
						ReaderBase.Query(PIN)->ShowData();
						break;
					case 'c':
					case 'C':			 //show cart
						rdr->ShowCart(); //book number in cart
						break;
					case 'e':
					case 'E':
						break;
					default:
						cout << "Unavailable function !\n";
					} //end switch
				}	  //while
				delete mgr;
				choice = 'X';
				break;
			//-------------------Reader's End-----------------------
			//==================Return Book=========================
			case 't':
			case 'T':
				cout << "Input a book ID:";
				cin >> BookID;
				if (BookBase.Query(BookID) != NULL)
				{
					BookBase.Query(BookID)->SetState(LIB);
					if ((PIN = BookBase.Query(BookID)->GetPIN()) > 0)
						ReaderBase.Query(PIN)->ReturnBook(BookID);
				}
				break;
			//-----------------Return Book End --------------------
			case 'E':
			case 'e':
				break;
			default:
				cout << "Unavailable function !\n";
			}
		}
		return 0;
	}

#ifdef __cplusplus
}  // end extern "C"
#endif