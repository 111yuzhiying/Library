// #include"stdafx.h"
#include<fstream>
#include<iostream>
#include"rdatabase.h"
using namespace std;
RDatabase::RDatabase()
{
	Reader s;
	top = -1;
	ifstream file;	// 定义一个输入文件
	file.open("reader.dat",ios::in|ios::binary);  // 这文本能够流出或流入数据
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
			cout<<"读者信息库已满，无法再添加新的读者！"<<endl;return 0;
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
		cout<<"此处是读者维护功能模块："<<endl;
		cout<<"------------------------------------------------------"<<endl;
		cout<<"1:新增 2：更改 3：删除 4：查找 5：显示 6：全删 0：退出"<<endl;
		cout << "您的选择是：";
		cin>>choice;
		while (choice > 6) {
			cout << "实在抱歉，您的输入有一些问题，请输入0到6中的任一数字：";
			cin >> choice;
		}
		cout<<"------------------------------------------------------"<<endl<<endl;
		switch(choice){
		case 1:cout<<"输入读者编号：";
			cin>>readerid;
			cout<<"输入读者姓名：";
			cin>>readername;
			addreader(readerid,readername);break;
		case 2:cout<<"输入读者编号：";
			cin>>readerid;
			r=query(readerid);
			if(r==NULL){
			cout<<"该读者不存在！"<<endl;
			break;
			}
			cout<<"输入新的姓名：";
			cin>>readername;
			r->setname(readername);
			break;
		case 3:cout<<"输入读者编号：";
			cin>>readerid;
			r=query(readerid);
			if(r==NULL){
			cout<<"该读者不存在！"<<endl<<endl;
			break;}
			else{
				r->delreader();
				break;
			}
		case 4:cout<<"输入读者编号：";
			cin>>readerid;
			r=query(readerid);
			if(r==NULL){
			cout<<"该读者不存在！"<<endl<<endl;
			break;
			}
			r->list();
			break;
		case 5:list();break;
		case 6:clear();break;
		case 0:break;
		default: cout<<"输入的选择不正确，请重新输入！"<<endl<<endl;
		
		}
	}
}