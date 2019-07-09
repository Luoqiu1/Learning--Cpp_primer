#include <iostream>
#include <vector>
using namespace std;

bool findInt(vector<int>::const_iterator beg,vector<int>::const_iterator end,int a)
{
	for(;beg!=end;++beg){
		if(*beg==a)return 1;
	}
	return 0;
}

//vector<int>::iterator &findIntP(vector<int>::iterator &beg,vector<int>::iterator &end,int a)
vector<int>::iterator findIntP(vector<int>::iterator beg,vector<int>::iterator end,int a)
{
	for(;beg!=end;++beg){
		if(*beg==a)return beg;
	}
	return end;
}

int main ()
{
//	vector<int> v1;
//	int a;
//	while(cin>>a){
//		v1.push_back(a);
//	}
//	cin.clear();
//	int f;
//	cin>>f;
//	bool flag=findInt(v1.cbegin(),v1.cend(),f);
//	if(flag)cout<<"Yes!";
//	else cout<<"None!";
//	cout<<endl;
////	vector<int>::iterator &p=findIntP(v1.begin(),v1.end(),f);
//	vector<int>::iterator p=findIntP(v1.begin(),v1.end(),f);
//	if(p!=v1.end())cout<<"This point's address is "<<&p<<'.';
//	else cout<<"Sorry.Don't find its address.";
//	cout<<endl;

	vector<int> v1{1,2,3};
	const vector<int> v2{4,5,6};
	auto it1=v1.begin();auto it2=v2.begin();
	auto it3=v1.cbegin(),it4=v2.cbegin();
	for(;it1!=v1.end();++it1)cout<<*it1<<' ';
	cout<<endl;
	for(;it2!=v2.end();++it2)cout<<*it2<<' ';
	cout<<endl;
	for(;it3!=v1.end();++it3)cout<<*it3<<' ';
	cout<<endl;
	for(;it4!=v2.end();++it4)cout<<*it4<<' ';
	cout<<endl;
	
	
	return 0;
}
