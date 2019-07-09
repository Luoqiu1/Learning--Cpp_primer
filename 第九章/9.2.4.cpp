#include <iostream>
#include <vector>
#include <list>
#include <array>
using namespace std;

int main () 
{
	vector<int> v1;
//	int a;
//	while(cin>>a){
//		v1.push_back(a);
//	}
//	list<double> v2(v1.rbegin(),v1.rend());
//	for(auto i:v2)cout<<i<<' ';
	array<int,6> a1{1,2,3,4,5};
//	array<int,9> a2{0};		//std中的数组array，其大小也属于类型的一部分！ 
	array<int,6> a2{6,7,8,9,10};
	array<int,0>::iterator it1=a1.begin()+1;//似乎对迭代器来说，数组的大小没有影响？ 
	for(auto i:a1)cout<<i<<' ';cout<<endl;
	for(auto i:a2)cout<<i<<' ';cout<<endl;
	cout<<*it1<<endl;
	swap(a1,a2);
	for(auto i:a1)cout<<i<<' ';cout<<endl;
	for(auto i:a2)cout<<i<<' ';cout<<endl;
	cout<<*it1<<endl;
	vector<const char*> s1{"hello!","zai ma","gogoGO!"};
	vector<string> s{10,"www"};
	for(auto i:s1)cout<<i<<' ';cout<<endl;
	for(auto i:s)cout<<i<<' ';cout<<endl;
	s.assign(s1.begin()+1,s1.end());
	for(auto i:s1)cout<<i<<' ';cout<<endl;
	for(auto i:s)cout<<i<<' ';cout<<endl;
	cout<<v1.max_size()<<endl;
	return 0;
}
