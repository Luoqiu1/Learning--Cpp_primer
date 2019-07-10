#include <iostream>
#include <forward_list>
#include <vector>
#include <list>
using namespace std;

int main ()
{
//	forward_list<string> lst1{"hello"," !"," world."};
//	for(auto i:lst1)cout<<i;cout<<endl;
//	lst1.pop_front();//forward_list中有pop_front函数 
////	lst1.pop_back(); forward_list中无pop_back函数 
//						//不难理解为什么！结合数据结构的知识。 
//	for(auto i:lst1)cout<<i;cout<<endl;
//	
//	vector<int> v1{1,2,3,4,5,6,7,8,9,10};
//	vector<int>::iterator it1=v1.begin()+1;
//	vector<int>::iterator it2=v1.begin()+2;
//	vector<int>::iterator it3=v1.begin()+5;
//	cout<<endl<<*it1<<endl;
//	cout<<endl<<*it2<<endl;
//	cout<<endl<<*it3<<endl;
//	cout<<endl<<*(v1.end()-1)<<endl;
////	v1.erase(v1.begin()+2,v1.end()-1);
//	v1.erase(v1.begin()+2,v1.begin()+4);
//	for(auto i:v1)cout<<i<<' ';
//	cout<<endl;
//	cout<<*it1<<endl;
//	cout<<*it2<<endl;
//	cout<<*it3<<endl;
//	for(auto i:v1)cout<<i<<' ';cout<<endl;
//	vector<int>::iterator elem1=v1.end();
//	vector<int>::iterator elem2=v1.end();
////	vector<int>::iterator elem1=v1.begin();
////	vector<int>::iterator elem2=v1.begin();
//	cout<<*(elem1-1)<<endl;
//	elem1=v1.erase(elem1,elem2);
//	cout<<*elem1<<endl;
//	for(auto i:v1)cout<<i<<' ';cout<<endl;
//	cout<<*elem1<<endl;

	int ia[]={0,1,1,2,3,5,8,13,21,55,89};
	vector<int> v1(begin(ia),end(ia));
	list<int> lst1(begin(ia),end(ia));
	for(auto i:v1)cout<<i<<' ';cout<<endl;
	for(auto i:lst1)cout<<i<<' ';cout<<endl;
	auto it1=v1.begin(),it2=v1.end();
	auto it3=lst1.begin(),it4=lst1.end();
//	int cnt=0;
//	while(it1!=it2){
	//经典错误！ 
	while(it1!=v1.end()){
	//	++cnt;
	//	cout<<"here1";
		if(*it1%2==1)it1=v1.erase(it1);
		else ++it1;
	//	cout<<' '<<cnt<<' ';
	}
//	cout<<"here3"<<' '<<cnt;

//	while(it3!=it4){
	//经典错误！ 
	while(it3!=lst1.end()){
	//	cout<<"here2";
		if(*it3%2==0)it3=lst1.erase(it3);
		else ++it3;
	}
	for(auto i:v1)cout<<i<<' ';cout<<endl;
	for(auto i:lst1)cout<<i<<' ';cout<<endl;
	
	return 0;
}
