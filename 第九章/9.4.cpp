#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main ()
{
	vector<string> svec;
	svec.reserve(512);
	for(int i=0;i<511;++i){
		string s="a";
		auto tmp1=svec.capacity();
		svec.push_back(s);
		auto tmp2=svec.capacity();
		if(tmp1!=tmp2)cout<<"here i="<<i<<",changes="<<tmp2-tmp1<<",capacity="<<svec.capacity()<<endl;
	}
	svec.resize(svec.size()+svec.size()*2);
	cout<<svec.capacity()<<endl;
	for(int i=0;i<511;++i){
		string s="a";
		auto tmp1=svec.capacity();
		svec.push_back(s);
		auto tmp2=svec.capacity();
		if(tmp1!=tmp2)cout<<"here i="<<i<<",changes="<<tmp2-tmp1<<",capacity="<<svec.capacity()<<endl;
	}
	cout<<svec.capacity()<<endl;
	return 0;
 } 
