#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main()
{
//	int a,b;
//	while(cin>>a>>b){
//		cout<<a%b<<endl;
//	}
//	int val;
//	while(cin>>val&&val!=42);
//	double val{2.4};cout<<val<<endl;
//	int val2{val};cout<<val2;//被警告了
//	vector<int> vi{1,2,3};
//	vi={0,1,2,3,4,5}; for(auto x:vi)cout<<x<<' ';
//	int i;
//	if(42=i)cout<<"yes";需要左值 
//	if(i=123124)cout<<"yes";

//	int i;double d;
//	d=i=3.5; 
//	cout<<d<<' '<<i<<endl;
//	double b=3.0;
////	cout<<b;
////	printf("%f",b);
//	int c;
//	if(!(c=0))cout<<"yes";
	
//	vector<int> ivec;
//	decltype(ivec.size()) x;
//	while(cin>>x)ivec.push_back(x);
//	for(auto &x:ivec)if(x%2==1)x*=2;
//	for(auto x:ivec)cout<<x<<' ';
	
	int grade;while(cin>>grade){
//	string s1=grade>75?grade>90?"high pass":"low pass":grade>=60?"pass":"fail";cout<<s1<<endl;
	string s1;if(grade>=60){
		if(grade>75){
			if(grade>90)s1="high pass";
			else s1="low pass";
		}
		else s1="pass";
	}
	else s1="fail";cout<<s1<<endl;}
	return 0;
 }
