#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
//	vector<string> s1(10,'c');
//	vector<int> v1;
//	vector<int> v2(10);
//	vector<int> v3(10,42);
//	vector<int> v4{10};
//	vector<int> v5 {10,42};
//	vector<string> v6{10};
//	vector<string> v7{10,"hi"};
//	cout<<v1<<endl<<v2<<endl<<v3<<endl<<v4<<endl<<v5<<endl;
//	cout<<v6<<endl<<v7<<endl;
//	vector<int> v1;
//	vector<string> s1;
//	int a;
//	string s;
//	while(getline(cin,s)){
//		s1.push_back(s);
//	}
//	cout<<s1.size()<<endl; 
//	cout<<s1[0];
//	cout<<s1[0].size();
//	if(s1[0]>s1[1])cout<<"yes";else cout<<"no";

//	vector<unsigned > scores(11,0);
//	decltype(scores.size()) grade;
//	while(cin>>grade){
//		if(grade<=100&&grade>=0)scores[grade/10]++;
//	}
//	for(auto x:scores)cout<<x<<' ';
//	vector<string> s1;
//	cout<<s1[0];
//	vector<string> s1;
//	string s;
//	while(cin>>s){
//		s1.push_back(s);
//	}
//	for(auto &a1:s1)for(auto &c:a1)if(islower(c))c+='A'-'a';
//	for(auto a1:s1)cout<<a1<<endl;
	vector<int> ivec;
	decltype(ivec.size()) a;
	while(cin>>a){
		ivec.push_back(a);
	}
	for(int x=0;x<=ivec.size()-x-1;x++){
		if(x!=ivec.size()-x-1){
			cout<<ivec[x]+ivec[ivec.size()-1-x]<<' ';
		}
		else{
			cout<<ivec[x];break;
		}
	} 
	return 0;
 } 
