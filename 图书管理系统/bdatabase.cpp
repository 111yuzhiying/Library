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
			cout<<"ͼ������ݿ��������޷������ͼ�飡"<<endl;return 0;
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
		cout<<"�˴���ͼ��ά������ģ�飺"<<endl;
		cout<<"-------------------------------------------------------"<<endl;
		cout<<"1:���� 2������ 3��ɾ�� 4������ 5����ʾ 6��ȫɾ 0���˳�"<<endl;
		cout << "����ѡ���ǣ�";
		cin>>choice;
		while (choice >6) {
			cout << "ʵ�ڱ�Ǹ������������һЩ���⣬������0��6�е���һ���֣�";
			cin >> choice;
		}
		cout<<"-------------------------------------------------------"<<endl<<endl;
		switch(choice){
		case 1:cout<<"���ͼ���ţ�";
			cin>>bookid;
			cout<<"����ͼ������";
			cin>>bookname;
			addbook(bookid,bookname);
			break;

		case 2:cout<<"����ͼ���ţ�";
			cin>>bookid;
			b=query(bookid);
			if(b==NULL){
			cout<<"��ͼ�鲻���ڣ�"<<endl;
			break;
			}
			cout<<"�����µ�ͼ������";
			cin>>bookname;
			b->setname(bookname);break;
		case 3:cout<<"����ͼ���ţ�";
			cin>>bookid;
			b=query(bookid);
			if (b == NULL) {
				cout << "��ͼ�鲻���ڣ�" << endl<<endl;
				break;
			}
			else { b->delbook(); break; }
		case 4:cout<<"����ͼ���ţ�";
			cin>>bookid;
			b=query(bookid);
			if(b==NULL){
				cout<<"��ͼ�鲻���ڣ�"<<endl<<endl;
				break;
			}
			b->list();
			break;
		case 5:list();break;
		case 6:clear();break;
		case 0:break;
		default:cout<<"����������������룡"<<endl<<endl;break;

		}
	}
}