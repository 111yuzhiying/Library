#include<iomanip>
#include "book.h"
// #include "stdafx.h"
char *Book::getname()
{return name;}
int Book::getnote(){
	return note;
}
int Book::getnumber(){
	return number;
}
void Book::setname(char na[]){strcpy_s(name,na);}
void Book::addbook(int n,char *na){
	note=0;
	number=n;
	strcpy_s(name,na);
	onshelf=1;
}
void Book::delbook(){
	note=1;
	name[0]='/0';
	number = 0;
}
int Book::borrowbook(){		// 借书后，该书的上架标记应改为0
	int onshelfNow = onshelf;
	onshelf = 0;
	return onshelfNow;
}
void Book::retbook(){
	onshelf=1;
}
void Book::list(){
	cout<<setw(5)<<number<<setw(10)<<name<<setw(10)<<onshelf<<endl<<endl;
}
// #endif