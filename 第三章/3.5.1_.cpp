#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;
int text[88];
string sa[10];
int ia[10];
int main ()
{
//	string sa2[10];
//	const size_t a=23;
//	int ia2[a];
//	for(auto x:ia2)cout<<x<<' ';
//	int i=-1;
//	vector<int> ivec;
//	while(++i<10){
//		ivec.push_back(i);
//	}
//	for(auto x:ivec)cout<<x;
//	int a[8];
//	for(auto &i:a)i=2;
//	for(auto i:a)cout<<i<<' ';
//	auto pbeg=begin(a),pend=end(a);
//	while(pbeg!=pend){
//		*pbeg=0;pbeg++;
//	}
//	for(auto i:a)cout<<i<<' ';

//	int a[5]={2,3,4,5},b[7]={2,3,4,5};
//	auto abeg=begin(a),aend=end(a);
//	auto bbeg=begin(b),bend=end(b);
//	bool flag=true;
//	if(abeg-aend!=bbeg-bend)flag=!flag;
//	else while(abeg!=aend&&bbeg!=bend){
//		if(*abeg!=*bbeg){
//			flag=!flag;break;
//		}
//		++abeg;++bbeg;
//	}
//	if(flag)cout<<"Yes";else cout<<"No";
	
	vector<int> avec;
	avec[2]=2;avec[1]=1;avec[0]=0;cout<<avec[2];
	for(int i=0;i<3;i++)cout<<avec[i]<<' ';
	cout<<endl<<avec.cend()-avec.cbegin();
//	avec={1,2,3,4,5};avec={1};avec[77]=92123;cout<<avec[77];
//	for(auto i:avec)cout<<i<<' ';cout<<endl;
//	avec={3,3,1,4};
//	vector<int> bvec{3,3,1,4};
//	if(avec==bvec)cout<<"Yes";else cout<<"No";
	return 0;
}
