#include <string>
#include <iostream>
using namespace std;

string &fun(string &s,const string &oldVal,const string &newVal)
{
	auto it=s.begin();
	auto sz=oldVal.size();
	while(it!=s.end()){
		if(s.end()-it>=sz){
		
			string tmp(it,it+sz);
			if(tmp==oldVal){
		
		//	if(s.substr(it-s.begin(),sz)==oldVal){
			//别忘了 s.substr()这个函数！
			//截取string中的一段子字符串序列！ 
				
//				auto beg=it-s.begin();
//				s.erase(it,it+sz);
//				s.insert(beg,newVal);
				
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

string &Name(string &name,const string &front,const string &back)
{
//	name.append(back);
////	name.insert(name.begin(),front);没有这种写法！
//	name.insert(name.begin(),front.cbegin(),front.cend());

	name.insert(name.size(),back,0,back.size());//
	name.insert(0,front,0,front.size());//这两条语句均可省略len，即后面两个参数 
	return name; 
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
	
//	string name,front,back;
//	cin>>name>>front>>back;
//	Name(name,front,back);
//	cout<<name<<endl;
	
	return 0; 
}
