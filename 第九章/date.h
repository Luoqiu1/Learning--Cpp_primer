#ifndef DATE
#define DATE
#include <string>
#include <vector>
#include <iostream>
using namespace std;
class date{
	public:
		inline date(string s);
		inline void print();
	private:
		unsigned year;
		unsigned month;
		unsigned day;
};

void date::print()
{
	cout<<year<<'.'<<month<<'.'<<day;
}

date::date(string s)
{
	string::size_type pos1=0,pos2=0,cnt=0;
	for(auto i:s){
		if(!isalnum(i)){
			if(pos1)pos2=cnt;
			else pos1=cnt;
		}
		++cnt;
	}
	string s1(s.cbegin(),s.cbegin()+pos1),s2(s.cbegin()+pos1+1,s.cbegin()+pos2),s3(s.cbegin()+pos2+1,s.cend());
	string::size_type flag=0;
	const string cmpNum("123456789");
	if((flag=s1.find_first_not_of(cmpNum,flag))!=string::npos){
		const vector<string> cmp{"0","January","February","March","April","May",
		"June","July","August","September","October","November","December"};
		for(decltype(cmp.size()) i=1,sz=cmp.size();i!=sz;++i){
			if(cmp[i]==s1||cmp[i].find(s1)!=string::npos){
				flag=i;break;
			}
		}
	}
	else{
		flag=stoi(s1,0,10);
	}
	year=stoi(s3,0,10);
	month=flag;
	day=stoi(s2,0,10);
}
#endif
