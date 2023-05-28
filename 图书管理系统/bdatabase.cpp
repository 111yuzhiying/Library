// #include "stdafx.h"
#include<fstream>
#include<iostream>
#include"bdatabase.h"
using namespace std;
BDatabase::BDatabase(){
	Book s;
	top=-1;
	fstream file;
	file.open("book.dat",ios::in|ios::binary);
	while(1)
	{
		file.read((char*)&s,sizeof(s));
		if(!file) break;
		top++;
		book[top] = s;
	}
	file.close();
}
void BDatabase::clear(){
	top=-1;
}
Book *BDatabase::query(int bookid){
	for(int i=0;i<=top;i++)
		if(book[i].getnumber()==bookid&&book[i].getnote()==0)
			return &book[i];
	return NULL;
}
int BDatabase::addbook(int n,char *na){
	Book *p=query(n);
	if(p==NULL){
		top++;
		if(top>99){
			cout<<"图书馆数据库已满，无法再添加图书！"<<endl;return 0;
		}
		book[top].addbook(n,na);
		return 1;
	}
	return 0;
}
void BDatabase::list(){
	for (int i = 0; i <= top; i++) {
		if(book[i].getnote()==0) book[i].list();
	}
			
}
BDatabase::~BDatabase()
{
	fstream file;
	file.open("book.dat",ios::out|ios::binary);
	for(int i=0;i<=top;i++)
		if(book[i].getnote()==0)
			file.write((char*)&book[i],sizeof(book[i]));
		file.close();
}
void BDatabase::delbook(Book &b){
	b.delbook();
}
void BDatabase::bookdata()
{
	int choice=1;
	char bookname[20];
	int bookid;
	Book *b;
	while(choice!=0){
		cout<<"此处是图书维护功能模块："<<endl;
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"1:新增 2：更改 3：删除 4：查找 5：显示 6：全删 0：退出"<<endl;
		cout << "您的选择是：";
		cin>>choice;
		while (choice >6) {
			cout << "实在抱歉，您的输入有一些问题，请输入0到6中的任一数字：";
			cin >> choice;
		}
		cout<<"-------------------------------------------------------"<<endl<<endl;
		switch(choice){
		case 1:cout<<"输出图书编号：";
			cin>>bookid;
			cout<<"输入图书名：";
			cin>>bookname;
			addbook(bookid,bookname);
			break;

		case 2:cout<<"输入图书编号：";
			cin>>bookid;
			b=query(bookid);
			if(b==NULL){
			cout<<"该图书不存在！"<<endl;
			break;
			}
			cout<<"输入新的图书名：";
			cin>>bookname;
			b->setname(bookname);break;
		case 3:cout<<"输入图书编号：";
			cin>>bookid;
			b=query(bookid);
			if (b == NULL) {
				cout << "该图书不存在！" << endl<<endl;
				break;
			}
			else { b->delbook(); break; }
		case 4:cout<<"输入图书编号：";
			cin>>bookid;
			b=query(bookid);
			if(b==NULL){
				cout<<"该图书不存在！"<<endl<<endl;
				break;
			}
			b->list();
			break;
		case 5:list();break;
		case 6:clear();break;
		case 0:break;
		default:cout<<"输入错误，请重新输入！"<<endl<<endl;break;

		}
	}
}