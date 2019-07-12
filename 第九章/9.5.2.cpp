#include <string>
#include <iostream>
using namespace std;

string &fun(string &s,const string &oldVal,const string &newVal)
{
	auto it=s.begin();
	auto sz=oldVal.size();
	while(it!=s.end()){
		if(s.end()-it>sz){
			string tmp(it,it+sz);
			if(tmp==oldVal){
				
//				it=s.erase(it,it+sz);
//				s.insert(it-s.begin(),newVal);
				
//				auto beg=it-s.begin();
//				s.erase(beg,sz);
//				s.insert(beg,newVal);

				auto beg=it-s.begin();
				s.replace(beg,sz,newVal);
				
			}
		}
		++it;
	}
	return s;
}

int main ()
{
//	string s;
//	const char *cp="Stately, plump Buck";
//	s.assign(cp,7);
//	cout<<s<<endl;
//	s.insert(s.size(),cp+7);
//	cout<<s<<endl;
	
//	string s="some thing",s2="some other string";
//	s.insert(0,s2,0,s2.size());
//	cout<<s<<endl;
	
	string s,oldVal,newVal;
	getline(cin,s);
	cin>>oldVal>>newVal;
	fun(s,oldVal,newVal);
	cout<<s<<endl;
	
	return 0; 
}
