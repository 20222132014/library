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
void RDatabase::clear() { top = -1; cout << "ɾ���ɹ���" << endl; }
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
		cout << "��ӳɹ���" << endl;//��ӵģ�����ʹ����
		return 1;
	}
	else
	{
		cout << "�ö��߱������ͼ�飬���ʧ�ܣ�" << endl;
	}
	return 0;
}
void RDatabase::list()
{
	bool b = false;
	for (int i = 0; i <= top; i++)
	{
		if (read[i].getnote() != 1)//��ӵģ��������û��ɾ�����
		{
			read[i].list();
			b = true;
		}
	}
	if (b == false)cout << "���޶��ߣ�" << endl;//��ӵģ��޶���ʱ����ʹ����
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
		cout << "����ά����" << endl;
		cout << "----------------------------------------------------------" << endl;
		cout << "1������ 2������ 3��ɾ�� 4������ 5����ʾ 6��ȫɾ 0���˳�" << endl;
		cin >> choice;
		cout << "------------------------------------------------------------" << endl;
		switch (choice)
		{
		case 1:cout << "������߱�ţ�";
			cin >> readerid;
			cout << "�������������";
			cin >> readername;
			addreader(readerid, readername);
			break;
		case 2:cout << "������߱�ţ�";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
			cout << "�����µ�������";
			cin >> readername;
			r->setname(readername);
			break;
		case 3:cout << "������߱�ţ�";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
			r->delreader(); break;//��ӵģ�ɾ������
		case 4:cout << "������߱�ţ�";
			cin >> readerid;
			r = query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ�" << endl;
				break;
			}
			cout << "���ҳɹ���������Ϣ���£�" << endl;//��ӵģ�����ʹ����
			r->list(); break;
		case 5:list(); break;
		case 6:clear(); break;//��ӵģ�ȫɾ
		}
	}
}
