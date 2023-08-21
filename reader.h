#ifndef _reader_h_
#define _reader_h_
#include<iostream>
#include"book.h"
using namespace std;
const int Maxbor = 5;//最大借阅量
class Reader
{
private:
	int note;
	int number;
	char name[10];
	int borbook[Maxbor];
	int num;//记录借书数量
public:
	Reader() {}
	char* getname();//获得姓名
	int getnote();//获得删除标记
	int getnumber();//获得读者编号
	void setname(char na[]);//设置姓名
	int getnum();//添加的，获得借书数量
	void delbook();//设置删除标记
	void addreader(int n, char* na);//添加读者
	void delreader();//添加的，删除读者
	void borrowbook(int bookid,Book *b);//借书操作
	int retbook(int bookid,Book *b);//还书操作
	void list();//输出读者信息
};
#endif 