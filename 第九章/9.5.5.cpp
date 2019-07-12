#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "date.h"
using namespace std;

int main () 
{
//	vector<string> svec;
//	string s;
//	while(cin>>s){
//		svec.emplace_back(s);
//	}
//	int ans=0;
//	for(const auto &i:svec){
//		ans+=stoi(i,0,10);
//	}
//	cout<<ans<<endl;

//	date date1("1/1/1900");
//	date1.print();
	
//	string s("January/3/1900");
//	string::size_type pos1=0,pos2=0,cnt=0;
//	for(auto i:s){
//		if(!isalnum(i)){
//			if(pos1)pos2=cnt;
//			else pos1=cnt;
//		}
//		++cnt;
//	}
//	cout<<pos1<<' '<<pos2<<endl;
//	string s1(s.cbegin(),s.cbegin()+pos1),s2(s.cbegin()+pos1+1,s.cbegin()+pos2),s3(s.cbegin()+pos2+1,s.cend());
//	cout<<s1<<endl<<s2<<endl<<s3<<endl;
	
	ifstream ifs("date.txt");
	string str_date;
	while(getline(ifs,str_date)){
		date dateNow(str_date);
		dateNow.print();cout<<endl;
	}
	
	return 0;
}
