#include <iostream>
#include <string>
using namespace std;

int main ()
{
//	string s1;
//	for(auto ch:s1){
//		cout<<ch<<' ';
//	}
//	int cnt=0;不太好
//	decltype(s1.size()) cnt=0; 
//	for(auto ch:s1){
//		if(ispunct(ch))cnt++;
//	}
//	cout<<cnt;
//	getline(cin,s1);
//	for(auto &ch:s1){
//		if(ch>='a'&&ch<='z')ch+='A'-'a';
//	} 
//	cout<<s1;
//	int a[5]={1,2,3};
//	for(auto x:a){
//		cout<<x<<' ';
//	}
//	cout<<endl;
//	const char *p="nihao";
//	p=p+2;
//	int i=-1;
//	cout<<p[i];
//	string s2;
//	getline(cin,s2);
//	for(decltype(s2.size()) index=0;index<s2.size()&&!isspace(s2[index]);index++){
//		if(s2[index]>='a'&&s2[index]<='z')s2[index]+='A'-'a';
//	}
//	cout<<s2;
	string s1;
	getline(cin,s1);// s1.size()类型是 string::size_type ! 
//	for(auto &ch:s1){ //!!！要注意语法格式！是 " ：" 而不是" ，"或者" ；" 
		//auto也要常用！   多去习惯使用 auto 和 decltype()！ 
//		if(ch==' ')continue;
//		ch='x';
//	}

//	int i=0;
//	while(i<s1.size()){
//		if(s1[i]==' '){i++;continue;}
//		s1[i]='x';
//		i++;
//	}
	
//	for(int i=0;i<s1.size();i++){
//		if(s1[i]==' ')continue;
//		s1[i]='x';
//	}

//	string s;
//	cout<<s[0]<<endl; 
	for(char &ch:s1){
		if(ispunct(ch))ch=' ';
	}
	cout<<s1;
	return 0;
}
