#ifndef _book_h_
#define _book_h_
#include<iostream>
using namespace std;
class Book{
private:
	int note;
	int number;
	char name[10];
	int onshelf;
public:
	Book(){}
	char *getname();
	int getnote();
	int getnumber();
	void setname(char na[]);
	void delbook();
	void addbook(int n,char *na);
	int borrowbook();
	void retbook();
	void list();
};


#endif