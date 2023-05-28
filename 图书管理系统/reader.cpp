#include<iomanip>
#include "reader.h"
// #include "stdafx.h"
const int Maxbar=5;
#include<iostream>
char *Reader::getname()
{return name;}
int Reader::getnote(){
return note;}
int Reader::getnumber(){
return number;}
void Reader::setname(char na[])
{strcpy_s(name,na);}
void Reader::addreader(int n,char *na){
	note =0;
	number=n;
	strcpy_s(name,na);
	for(int i=0;i<Maxbor;i++) borbook[i]=0;
}
void Reader::delreader(){
	note=1;
	number = 0;
	name[0]='/0';
}
void Reader::borrowbook(int bookid){
	int i;
	for( i=0;i<Maxbar;i++){
		if(borbook[i]==0) {borbook[i]= bookid;return;}
	}
	if(i==5){
		cout<<"已经超出最大借阅书数量，无法借书！"<<endl<<endl;
	}
	else cout<<"借书成功！"<<endl<<endl;      // 要反馈借书成不成功的信息
}
int Reader::retbook(int bookid){
	for(int i=0;i<Maxbar;i++){
		if(borbook[i]==bookid){borbook[i]=0;return 1;}
	}
	return 0;
}
void Reader::list()
{
	cout<<setw(5)<<number<<setw(10)<<name<<"借书编号：[";
	for(int i=0;i<Maxbor;i++)
		if(borbook[i]!=0) cout<<borbook[i]<<" ";
	cout<<"]"<<endl;
}
