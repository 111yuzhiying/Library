#ifndef _rdatabase_h_
#define _rdatabase_h_
#include "reader.h"
#include<iostream>
using namespace std;
const int Maxr=100;
class RDatabase{
private:
	int top;
	Reader read[Maxr];
public:
	RDatabase();
	void clear();
	int addreader(int n,char *na);
	Reader *query(int readerid);
	void list();
	void readerdata();
	void delreader(Reader &);
	~RDatabase();
};
#endif