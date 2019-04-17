#include <iostream>
#include <string>
using namespace std;

int main ()
{
	string s1="nihou,aw!@>>>..wea";
//	for(auto ch:s1){
//		cout<<ch<<' ';
//	}
//	int cnt=0;²»Ì«ºÃ
	decltype(s1.size()) cnt=0; 
	for(auto ch:s1){
		if(ispunct(ch))cnt++;
	}
	cout<<cnt;
	return 0;
}
