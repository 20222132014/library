#ifndef _bdatabase_h_
#define _bdatabase_h_
#include"book.h"
#include<iostream>
using namespace std;
const int Maxb = 100;
class BDatabase
{
private:
	int top;//ͼ���¼ָ��
	Book book[Maxb];//ͼ���¼
public:
	BDatabase();//���캯����ʼ�������ļ�
	void clear();//ȫ��ɾ��
	int addbook(int n, char* na);//���ͼ��
	Book* query(int bookid);//����ͼ��
	void list();//���ͼ����Ϣ
	void bookdata();//ͼ���ά��
	~BDatabase();//����������д�ļ�
};
#endif