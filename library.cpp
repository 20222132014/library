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
	cout << "��ӭ���롰ССͼ��ݡ��������" << endl;
	cout << "---------------------------------------" << endl;
	while (choice != 0)
	{
		cout << "--------------------------------------" << endl;
		cout << "1������ 2������ 3��ͼ����� 4������ά�� 0���뿪" << endl;
		cin >> choice;
		cout << "--------------------------------------" << endl;
		switch (choice)
		{
		case 1:
			cout << "���������߱��";
			cin >> readerid;
			cout << "����ͼ����";
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ����ܽ��飡" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ����ܽ��飡" << endl;
				break;
			}
			if (b->borrowbook() == 0)
			{
				cout << "��ͼ���ѽ�������ܽ��飡" << endl;
				break;
			}
			r->borrowbook(b->getnumber(),b);
			cout << "����ɹ���" << endl;//��ӵģ�����ʹ����
			break;
		case 2:
			cout << "���뻹����߱��";
			cin >> readerid;
			cout << "����ͼ����";
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << "�ö��߲����ڣ����ܻ��飡" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << "��ͼ�鲻���ڣ����ܻ��飡" << endl;
				break;
			}
			if (r->getnum() == 0)
			{
				cout << "�˶������޽��飬����ʧ�ܣ�";
				break;
			}
			b->retbook();
			r->retbook(b->getnumber(),b);
			cout << "����ɹ���" << endl;//��ӵģ�����ʹ����
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