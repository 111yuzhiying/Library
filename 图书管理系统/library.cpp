// #include"stdafx.h"
#include"bdatabase.h"
#include"reader.h"
#include"rdatabase.h"
#include"book.h"
#include<iostream>
using namespace std;
int main(){
	int choice=1,bookid,readerid;
	RDatabase ReaderDB;
	BDatabase BookDB;
	Reader *r;
	Book *b;
	cout<<"��ӭ���롰ССͼ��ݡ��������"<<endl;
	cout<<"-----------------------------------------------------"<<endl;
	while(choice!=0){
		cout<<"----------------------------------------------------"<<endl;
		cout<<"1:���� 2������ 3��ͼ��ά�� 4������ά�� 0���뿪"<<endl;
		cout << "����ѡ���ǣ�";
		cin>>choice;
		while (choice > 4) {
			cout << "ʵ�ڱ�Ǹ������������һЩ���⣬������0��4�е���һ���֣�";
			cin >> choice;
		}
		cout<<"----------------------------------------------------"<<endl;
		switch(choice){
		case 1:
			cout<<"�����������߱�ţ�";
			cin>>readerid;
			cout<<"������ͼ���ţ�";
			cin>>bookid;
			r=ReaderDB.query(readerid);
			if(r==NULL)
			{cout<<"��ͼ�鲻���ڣ����ܽ��飡"<<endl<<endl;
			break;}
			b=BookDB.query(bookid);
			if(b==NULL){cout<<"��ͼ�鲻���ڣ����ܽ��飡"<<endl<<endl;
			break;}
			if(b->borrowbook()==0)
			{
				cout<<"��ͼ���ѽ�������ܽ��飡"<<endl<<endl;
				break;
			}
			r->borrowbook(b->getnumber());break;
		case 2:
			cout<<"�����뻹����߱�ţ�";
			cin>>readerid;
			cout<<"������ͼ���ţ�";
			cin>>bookid;
			r=ReaderDB.query(readerid);
			if(r==NULL){
			cout<<"�ö��߲����ڣ����ܻ��飡"<<endl<<endl;
			break;
			}
			b=BookDB.query(bookid);
			if(b==NULL)
			{cout<<"��ͼ�鲻���ڣ����ܻ��飡"<<endl<<endl;
			break;}
			b->retbook();
			r->retbook(b->getnumber());
			break;
		case 3:
			BookDB.bookdata();break;
		case 4:
			ReaderDB.readerdata();break;
		case 0:
			break;
		default: cout<<"�������Ϣ�������������룡"<<endl<<endl;
		}
	}
	return 0;
}