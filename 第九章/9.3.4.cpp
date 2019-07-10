#include <iostream>
#include <forward_list>
#include <list>
#include <string>
using namespace std;

void fun(forward_list<string> &flst,const string &s1,const string &s2)
{
	auto prev=flst.before_begin();
	auto curr=flst.begin();
	while(curr!=flst.end()){
		if(*curr==s1){
			flst.insert_after(curr,s2);
			return;
		}
		else{
			++prev;++curr;
		//	++curr;
		}
	}
	flst.emplace_after(prev,s2);
}

int main (int argc,char *argv[])
{
//	forward_list<int> flst1{1,2,3,4,5,6,7};
//	auto it=flst1.before_begin();
//	while(it!=flst1.end()-1){
//		if(*(it+1)%2)flst1.erase_after(it);
//		else ++it;
//	}

//	auto prev=flst1.before_begin(),curr=flst1.begin();
//	while(curr!=flst1.end()){
//		if(*curr%2){
//			curr=flst1.erase_after(prev);
//		}
//		else{
//			++prev;++curr;
//		}
//	}
//	for(auto i:flst1)cout<<i<<' ';cout<<endl;

	forward_list<string> flst1;
	string s;
	decltype(flst1.before_begin()) text;
	while(cin>>s){
		text=flst1.insert_after(flst1.before_begin(),s);
		//emplace°æ±¾¸üºÃ 
	}
	cout<<endl<<*text<<endl;
	for(const auto &i:flst1)cout<<i<<' ';cout<<endl;
	cin.clear();
	string s1,s2;
	cin>>s1>>s2;
	fun(flst1,s1,s2);
	for(const auto &i:flst1)cout<<i<<' ';cout<<endl;
	return 0;
 } 
