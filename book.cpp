#define _CRT_SECURE_NO_WARNINGS 1
#include<iomanip>
#include"book.h"
char* Book::getname()
{
	return name;
}
int Book::getnote()
{
	return note;
}
int Book::getnumber()
{
	return number;
}
void Book::setname(char na[])
{
	strcpy(name, na);
}
void Book::setonshelf(int x)
{
	onshelf = x;
}
void Book::addbook(int n, char* na)
{
	note = 0;
	number = n;
	strcpy(name, na);
	onshelf = 1;
}
void Book::delbook()
{
	note = 1;
	cout << "删除成功！" << endl;
}
int Book::borrowbook()
{
	return onshelf;
}
void Book::retbook()
{
	onshelf = 1;
}
void Book::list()
{
	cout << "图书编号：" << setw(5) << number << "图书名称：" << setw(10) << name;
	if (onshelf == 1)cout << setw(10) << "未借" << endl;
	else cout << setw(10) << "已借" << endl;//添加的，优化UI界面
}