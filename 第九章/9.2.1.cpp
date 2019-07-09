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

vector<int>::iterator findIntP(vector<int>::iterator beg,vector<int>::iterator end,int a)
{
	for(;beg!=end;++beg){
		if(*beg==a)return beg;
	}
	return end;
}

int main ()
{
	vector<int> v1;
	int a;
	while(cin>>a){
		v1.push_back(a);
	}
	cin.clear();
	int f;
	cin>>f;
	bool flag=findInt(v1.cbegin(),v1.cend(),f);
	if(flag)cout<<"Yes!";
	else cout<<"None!";
	cout<<endl;
	vector<int>::iterator p;
	p=findIntP(v1.begin(),v1.end(),f);
	if(p!=v1.end())cout<<"This point's address is "<<&p<<'.';
	else cout<<"Sorry.Don't find its address.";
	cout<<endl;
	return 0;
}
