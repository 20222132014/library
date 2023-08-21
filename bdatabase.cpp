#define _CRT_SECURE_NO_WARNINGS 1
#include<fstream>
#include<iostream>
#include"bdatabase.h"
using namespace std;
BDatabase::BDatabase()
{
	Book s;
	top = -1;
	fstream file;
	file.open("book.dat", ios::in | ios::binary);
	while (1)
	{
		file.read((char*)&s, sizeof(s));
		if (!file)break;
		top++;
		book[top] = s;
	}
	file.close();
}
void BDatabase::clear()
{
	top = -1;
}
Book* BDatabase::query(int bookid)
{
	for (int i = 0; i <= top; i++)
		if (book[i].getnumber() == bookid && book[i].getnote() == 0)
			return &book[i];
	return NULL;
}
int BDatabase::addbook(int n, char* na)
{
	Book* p = query(n);
	if (p == NULL)
	{
		top++;
		book[top].addbook(n, na);
		cout << "添加成功！" << endl;//增加的
		return 1;
	}
	else
	{
		cout << "该图书编号已有图书，添加失败！" << endl;
	}
	return 0;
}
void BDatabase::list()
{
	bool a = false;
	for (int i = 0; i <= top; i++)
	{
		if (book[i].getnote() != 1)//添加的，如果图书没被删则输出
		{
			book[i].list();
			a = true;
		}
	}
	if (!a)cout << "暂无图书！" << endl;//添加的，无图书时提醒使用者
}
BDatabase::~BDatabase()
{
	fstream file;
	file.open("book.dat", ios::out | ios::binary);
	for (int i = 0; i <= top; i++)
		if (book[i].getnote() == 0)
			file.write((char*)&book[i], sizeof(book[i]));
	file.close();
}
void BDatabase::bookdata()
{
	int choice = 1;
	char bookname[20];
	int bookid;
	Book* b;
	while (choice != 0)
	{
		cout << "------------------------------------------------------" << endl;
		cout << "图书维护：" << endl;
		cout << "------------------------------------------------------" << endl;
		cout << "1：新增 2：更改 3：删除 4：查找 5：显示 6：全删 0：退出" << endl;
		cin >> choice;
		cout << "--------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:cout << "输入图书编号：";
			cin >> bookid;
			cout << "输入图书名：";
			cin >> bookname;
			addbook(bookid, bookname); break;
		case 2:cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在！" << endl;
				break;
			}
			cout << "输入新的图书名：";
			cin >> bookname;
			b->setname(bookname); break;
		case 3:cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在！" << endl;
				break;
			}
			else b->delbook(); break;
		case 4:cout << "输入图书编号：";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "该图书不存在！" << endl;
				break;
			}
			b->list(); break;
		case 5:list(); break;
		case 6:top = -1; cout <<"删除成功！"<<endl; break;//修改为top=-1
		}
	}
}