// #include"stdafx.h"
#include<fstream>
#include<iostream>
#include"rdatabase.h"
using namespace std;
RDatabase::RDatabase()
{
	Reader s;
	top = -1;
	ifstream file;	// ����һ�������ļ�
	file.open("reader.dat",ios::in|ios::binary);  // ���ı��ܹ���������������
	while(1){
		file.read((char*)&s,sizeof(s));
		if(!file) break;
		top++;
		read[top]=s;
	}
	file.close();
}

void RDatabase::clear()
{top=-1;}
Reader *RDatabase::query(int readerid){
	for(int i=0;i<=top;i++)
		if(read[i].getnumber()==readerid&&read[i].getnote()==0)
			return &read[i];
	return NULL;
}
void RDatabase::delreader(Reader &r){
	r.delreader();
}
int RDatabase::addreader(int n,char *na)
{
	Reader *p=query(n);
	if(p==NULL){
		top++;
		if(top>99){
			cout<<"������Ϣ���������޷�������µĶ��ߣ�"<<endl;return 0;
		}
		read[top].addreader(n,na);
		return 1;
	}
	return 0;
}

void RDatabase::list(){
	for (int i = 0; i <= top; i++) {
		if(read[i].getnote()==0) read[i].list();
	}
}

RDatabase::~RDatabase()
{
	fstream file;
	file.open("reader.dat",ios::out|ios::binary);
	for(int i=0;i<=top;i++)
		if(read[i].getnote()==0)
			file.write((char*)&read[i],sizeof(read[i]));
	file.close();
}

void RDatabase::readerdata(){
	int choice = 1;
	char readername[20];
	int readerid;
	Reader *r;
	while(choice!=0){
		cout<<"�˴��Ƕ���ά������ģ�飺"<<endl;
		cout<<"------------------------------------------------------"<<endl;
		cout<<"1:���� 2������ 3��ɾ�� 4������ 5����ʾ 6��ȫɾ 0���˳�"<<endl;
		cout << "����ѡ���ǣ�";
		cin>>choice;
		while (choice > 6) {
			cout << "ʵ�ڱ�Ǹ������������һЩ���⣬������0��6�е���һ���֣�";
			cin >> choice;
		}
		cout<<"------------------------------------------------------"<<endl<<endl;
		switch(choice){
		case 1:cout<<"������߱�ţ�";
			cin>>readerid;
			cout<<"�������������";
			cin>>readername;
			addreader(readerid,readername);break;
		case 2:cout<<"������߱�ţ�";
			cin>>readerid;
			r=query(readerid);
			if(r==NULL){
			cout<<"�ö��߲����ڣ�"<<endl;
			break;
			}
			cout<<"�����µ�������";
			cin>>readername;
			r->setname(readername);
			break;
		case 3:cout<<"������߱�ţ�";
			cin>>readerid;
			r=query(readerid);
			if(r==NULL){
			cout<<"�ö��߲����ڣ�"<<endl<<endl;
			break;}
			else{
				r->delreader();
				break;
			}
		case 4:cout<<"������߱�ţ�";
			cin>>readerid;
			r=query(readerid);
			if(r==NULL){
			cout<<"�ö��߲����ڣ�"<<endl<<endl;
			break;
			}
			r->list();
			break;
		case 5:list();break;
		case 6:clear();break;
		case 0:break;
		default: cout<<"�����ѡ����ȷ�����������룡"<<endl<<endl;
		
		}
	}
}