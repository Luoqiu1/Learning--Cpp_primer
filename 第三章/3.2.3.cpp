#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string s1;
//	for(auto ch:s1){
//		cout<<ch<<' ';
//	}
//	int cnt=0;²»Ì«ºÃ
//	decltype(s1.size()) cnt=0; 
//	for(auto ch:s1){
//		if(ispunct(ch))cnt++;
//	}
//	cout<<cnt;
	getline(cin,s1);
	for(auto &ch:s1){
		if(ch>='a'&&ch<='z')ch+='A'-'a';
	} 
	cout<<s1;
	int a[5]={1,2,3};
	for(auto x:a){
		cout<<x<<' ';
	}
	cout<<endl;
	const char *p="nihao";
	p=p+2;
	int i=-1;
	cout<<p[i];
	return 0;
}
