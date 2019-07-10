#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <deque>
using namespace std;

void print(const deque<int> &queue)
{
	for(auto i:queue)cout<<i<<' ';
}

int main ()
{
//	deque<string> queue1;
//	list<string> list1;
//	string s;
//	while(cin>>s){
//		list1.push_back(s);
//	}
//	for(auto it1=list1.cbegin(),it2=list1.cend();it1!=it2;++it1){
//		cout<<*it1<<' ';
//	}
//	cout<<endl;
	
//	list<int> list1;
//	int a;
//	while(cin>>a){
////		list1.push_back(a);
//		list1.emplace_back(a);
//	}
//	deque<int> queue1,queue2;
//	for(auto i:list1){
////		if(!(i%2))queue2.push_back(i);
////		else queue1.push_back(i);
//		if(!(i%2))queue2.emplace_back(i);
//		else queue1.emplace_back(i);
//	}
//	print(queue1);cout<<endl; 
//	print(queue2);cout<<endl;

	vector<int> iv;
	int a;
	while(cin>>a){
		iv.emplace_back(a);
	}
	cin.clear();
	int same_val;
	cin>>same_val;
	vector<int>::iterator it1=iv.begin(),mid=iv.begin()+iv.size()/2;
	while(it1!=mid){
		if(*mid==same_val){
			mid=iv.emplace(mid,same_val*2);
		}
		else --mid;
	}
	for(auto i:iv)cout<<i<<' ';
	
	return 0;
 } 
