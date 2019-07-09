#include <iostream>
#include <vector>
#include <list>
#include <array>
using namespace std;

int main () 
{
//	vector<int> v1;
//	int a;
//	while(cin>>a){
//		v1.push_back(a);
//	}
//	list<double> v2(v1.rbegin(),v1.rend());
//	for(auto i:v2)cout<<i<<' ';
	array<int,10> a1{1,2,3,4,5};
//	array<int,9> a2{0};		//std中的数组array，其大小也属于类型的一部分！ 
	array<int,10> a2{0};
	for(auto i:a1)cout<<i<<' ';cout<<endl;
	for(auto i:a2)cout<<i<<' ';cout<<endl;
	swap(a1,a2);
	for(auto i:a1)cout<<i<<' ';cout<<endl;
	for(auto i:a2)cout<<i<<' ';cout<<endl;
	return 0;
}
