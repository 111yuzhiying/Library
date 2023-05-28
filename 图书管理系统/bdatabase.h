#ifndef _bdatabase_h_
#define _bdatabase_h_
#include"book.h"
#include<iostream>
using namespace std;
const int Maxb=100;
class BDatabase{
private:
	int top;
	Book book[Maxb];
public:
	BDatabase();
	void clear();
	int addbook(int n,char *na);
	Book *query(int bookid);
	void list();
	void bookdata();
	void delbook(Book &);		// 缺了如何删除单本图书
	~BDatabase();
};
#endif