#define _CRT_SECURE_NO_WARNINGS 1
#include"rdatabase.h"
#include<fstream>
#include<iostream>
using namespace std;
RDatabase::RDatabase()
{
	Reader s;
	top = -1;
	ifstream file;
	file.open("reader.dat", ios::in | ios::binary);
	while (1)
	{
		file.read((char*)&s, sizeof(s));
		if (!file)break;
		top++;
		read[top] = s;
	}
	file.close();
}
void RDatabase::clear() { top = -1; cout << "删除成功！" << endl; }
Reader* RDatabase::query(int readerid)
{
	for (int i = 0; i <= top; i++) 
	{
		if (read[i].getnumber() == readerid && read[i].getnote() == 0)
			return &read[i];
	}
	return NULL;
}
int RDatabase::addreader(int n, char* na)
{
	Reader* p = query(n);
	if (p == NULL)
	{
		top++;
		read[top].addreader(n, na);
		cout << "添加成功！" << endl;//添加的，提醒使用者
		return 1;
	}
	else
	{
		cout << "该读者编号已有图书，添加失败！" << endl;
	}
	return 0;
}
void RDatabase::list()
{
	bool b = false;
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnote() != 1)//添加的，如果读者没被删则输出
		{
			read[i].list();
			b = true;
		}
	}
	if (b == false)cout << "暂无读者！" << endl;//添加的，无读者时提醒使用者
}
RDatabase::~RDatabase()
{
	fstream file;
	file.open("reader.dat", ios::out | ios::binary);
	for (int i = 0; i <= top; i++)
		if (read[i].getnote() == 0)
			file.write((char*)&read[i], sizeof(read[i]));
		file.close();
}
void RDatabase::readerdata()
{
	int choice = 1;
	char readername[20];
	int readerid;
	Reader* r;
	while (choice != 0)
	{
		cout << "读者维护：" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "1：新增 2：更改 3：删除 4：查找 5：显示 6：全删 0：退出" << endl;
		cin >> choice;
		cout << "------------------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:cout << "输入读者编号：";
			cin >> readerid;
			cout << "输入读者姓名：";
			cin >> readername;
			addreader(readerid, readername);
			break;
		case 2:cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在！" << endl;
				break;
			}
			cout << "输入新的姓名：";
			cin >> readername;
			r->setname(readername);
			break;
		case 3:cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在！" << endl;
				break;
			}
			r->delreader(); break;//添加的，删除读者
		case 4:cout << "输入读者编号：";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "该读者不存在！" << endl;
				break;
			}
			cout << "查找成功！读者信息如下：" << endl;//添加的，提醒使用者
			r->list(); break;
		case 5:list(); break;
		case 6:clear(); break;//添加的，全删
		}
	}
}
