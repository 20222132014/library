#include"reader.h"
#include"rdatabase.h"
#include"bdatabase.h"
#include"book.h"
#include"reader.h"
#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int choice = 1, bookid, readerid;
	RDatabase ReaderDB;
	BDatabase BookDB;
	Reader* r;
	Book* b;
	cout << "欢迎进入“小小图书馆”管理软件" << endl;
	cout << "---------------------------------------" << endl;
	while (choice != 0)
	{
		cout << "--------------------------------------" << endl;
		cout << "1：借书 2：还书 3：图书管理 4：读者维护 0：离开" << endl;
		cin >> choice;
		cout << "--------------------------------------" << endl;
		switch (choice)
		{
		case 1:
			cout << "输入借书读者编号";
			cin >> readerid;
			cout << "输入图书编号";
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在，不能借书！" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在，不能借书！" << endl;
				break;
			}
			if (b->borrowbook() == 0)
			{
				cout << "该图书已借出，不能借书！" << endl;
				break;
			}
			r->borrowbook(b->getnumber(),b);
			cout << "借书成功！" << endl;//添加的，提醒使用者
			break;
		case 2:
			cout << "输入还书读者编号";
			cin >> readerid;
			cout << "输入图书编号";
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在，不能还书！" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在，不能还书！" << endl;
				break;
			}
			if (r->getnum() == 0)
			{
				cout << "此读者暂无借书，还书失败！";
				break;
			}
			b->retbook();
			r->retbook(b->getnumber(),b);
			cout << "还书成功！" << endl;//添加的，提醒使用者
			break;
		case 3:
			BookDB.bookdata(); 
			break;
		case 4:
			ReaderDB.readerdata(); 
			break;
		}
	}
	return 0;
}