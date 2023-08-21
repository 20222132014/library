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
		cout << "��ӳɹ���" << endl;//���ӵ�
		return 1;
	}
	else
	{
		cout << "��ͼ��������ͼ�飬���ʧ�ܣ�" << endl;
	}
	return 0;
}
void BDatabase::list()
{
	bool a = false;
	for (int i = 0; i <= top; i++)
	{
		if (book[i].getnote() != 1)//��ӵģ����ͼ��û��ɾ�����
		{
			book[i].list();
			a = true;
		}
	}
	if (!a)cout << "����ͼ�飡" << endl;//��ӵģ���ͼ��ʱ����ʹ����
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
		cout << "ͼ��ά����" << endl;
		cout << "------------------------------------------------------" << endl;
		cout << "1������ 2������ 3��ɾ�� 4������ 5����ʾ 6��ȫɾ 0���˳�" << endl;
		cin >> choice;
		cout << "--------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:cout << "����ͼ���ţ�";
			cin >> bookid;
			cout << "����ͼ������";
			cin >> bookname;
			addbook(bookid, bookname); break;
		case 2:cout << "����ͼ���ţ�";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ�" << endl;
				break;
			}
			cout << "�����µ�ͼ������";
			cin >> bookname;
			b->setname(bookname); break;
		case 3:cout << "����ͼ���ţ�";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ�" << endl;
				break;
			}
			else b->delbook(); break;
		case 4:cout << "����ͼ���ţ�";
			cin >> bookid;
			b = query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ�" << endl;
				break;
			}
			b->list(); break;
		case 5:list(); break;
		case 6:top = -1; cout <<"ɾ���ɹ���"<<endl; break;//�޸�Ϊtop=-1
		}
	}
}