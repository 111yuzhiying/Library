#ifndef _reader_h_
#define _reader_h_
#include<iostream>
using namespace std;
const int Maxbor=5;
class Reader{
private:
	int note;
	int number;
	char name[10];
	int borbook[Maxbor];
public:
	Reader(){}
	char *getname();
	int getnote();
	int getnumber();
	void setname(char na[]);
	void delreader();	// 此处应该为删除读者
	void addreader(int n,char *na);
	void borrowbook(int bookid);
	int retbook(int bookid);
	void list();
};
#endif