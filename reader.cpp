#define _CRT_SECURE_NO_WARNINGS 1
#include<iomanip>
#include"reader.h"
#include<iostream>
char* Reader::getname()
{
	return name;
}
int Reader::getnote()
{
	return note;
}
int Reader::getnumber()
{
	return number;
}
int Reader::getnum()
{
	return num;
}
void Reader::setname(char na[])
{
	strcpy(name, na);
}
void Reader::addreader(int n, char* na)
{
	note = 0;
	num = 0;//��ʼ��������Ϊ0
	number = n;
	strcpy(name, na);
	for (int i = 0; i < Maxbor; i++)borbook[i] = 0;
}
void Reader::delreader()
{
	note = 1;
	cout << "ɾ���ɹ�" << endl;
}
void Reader::delbook()
{
	note = 1;
}
void Reader::borrowbook(int bookid,Book *b)
{
	if (num == Maxbor)
	{
		cout << "�˶��߽��������Ѵ����ޣ�����ʧ�ܣ�";
		return;
	}
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] == 0)
		{
			borbook[i] = bookid;
			b->setonshelf(0);
			num++;
			return;
		}
	}
}
int Reader::retbook(int bookid,Book*b)
{
	
	for (int i = 0; i < Maxbor; i++)
	{
		if (borbook[i] == bookid)
		{
			borbook[i] = 0;
			b->setonshelf(1);
			num--;
			return 1;
		}
	}
	return 0;
}
void Reader::list()
{
	cout <<"���߱�ţ�" << setw(5) << number <<"  ����������" << setw(10) << name << "  �����ţ�[";
	for (int i = 0; i < Maxbor; i++)
		if (borbook[i] != 0)cout << borbook[i] << " ";//�޸ģ���==��Ϊ!=
		cout << "]" << endl;
}