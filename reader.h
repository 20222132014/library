#ifndef _reader_h_
#define _reader_h_
#include<iostream>
#include"book.h"
using namespace std;
const int Maxbor = 5;//��������
class Reader
{
private:
	int note;
	int number;
	char name[10];
	int borbook[Maxbor];
	int num;//��¼��������
public:
	Reader() {}
	char* getname();//�������
	int getnote();//���ɾ�����
	int getnumber();//��ö��߱��
	void setname(char na[]);//��������
	int getnum();//��ӵģ���ý�������
	void delbook();//����ɾ�����
	void addreader(int n, char* na);//��Ӷ���
	void delreader();//��ӵģ�ɾ������
	void borrowbook(int bookid,Book *b);//�������
	int retbook(int bookid,Book *b);//�������
	void list();//���������Ϣ
};
#endif 