#ifndef _book_h_
#define _book_h_
#include<iostream>
using namespace std;
class Book
{
private:
	int note;//ɾ����ǣ�1����ɾ 0��δɾ��
	int number;//ͼ����
	char name[10];//����
	int onshelf;//�ϼܱ�־
public:
	Book() {}
	char* getname();//�������
	int getnote();//���ɾ�����
	int getnumber();//���ͼ����
	void setonshelf(int x);//��ӵģ�����ϼܱ�־
	void setname(char na[]);//��������
	void delbook();//ɾ��ͼ��
	void addbook(int n, char* na);//���ͼ��
	int borrowbook();//�������
	void retbook();//�������
	void list();//���ͼ��
};
#endif