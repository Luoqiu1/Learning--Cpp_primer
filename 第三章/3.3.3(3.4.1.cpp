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

//	vector<int> ivec;
//	decltype(ivec.size()) a;
//	while(cin>>a){
//		ivec.push_back(a);
//	}
//	for(int x=0;x<=ivec.size()-x-1;x++){
//		if(x!=ivec.size()-x-1){
//			cout<<ivec[x]+ivec[ivec.size()-1-x]<<' ';
//		}
//		else{
//			cout<<ivec[x];break;
//		}
//	}
//	const vector<int> ivec;
//	vector<const int> ivec2; const应像上一行语句一样，写在尖括号外面，vector前面 
//	return 0;
	
//	vector<string>s1;
//	string s;
//	while(cin>>s){
//		s1.push_back(s);
//	} 
//	for(auto &ss:s1){
//	//	ss.
//		for(auto it=ss.begin();it!=ss.end();it++){
//			*it=toupper(*it);cout<<*it;
//		}
//		cout<<' ';
//	}
//	return 0;
	
//	vector<int> ivec;
//	decltype(ivec.size()) a;
//	while(cin>>a){
//		ivec.push_back(a);
//	}
//	for(auto it=ivec.begin();it!=ivec.end();it++){
//		(*it)*=2;
//	}
//	for(auto &a:ivec)a*=2;
//	for(auto it=ivec.cbegin();it!=ivec.cend();it++){
//		cout<<*it<<' ';
	//	cout<<it->difference_type<<endl;
//	}
//	for(auto a:ivec)cout<<a<<' ';

//	vector<int> ivec(11,0);
//	decltype(ivec.size()) a;
//	while(cin>>a){
//		if(a>=0&&a<=100){
//			auto it=ivec.begin();it+=a/10;
//			(*it)++;
//		}
//	}
//	for(auto x:ivec)cout<<x<<' ';
	
//	for(auto it=ivec.cbegin(),it2=ivec.cend()-1;it<=it2;++it,--it2){
//		if(it!=it2)cout<<*it+*it2<<' ';
//		else cout<<*it;
//	}
	vector<int> ivec;
	int a;
	int i=0;
	for(;i<5;i++){
		cin>>a;ivec.push_back(a);
	}
//	sort(&ivec[0],&ivec[0]+ivec.size());
//	unsigned loc;
	int x;
	cin>>x;
	auto beg=ivec.cbegin(),end=ivec.cend(),mid=beg+(end-beg)/2;
								// mid=(end+beg)/2 是有问题的！  vector并没有定义迭代器之间的加法！ 
	for(;mid!=end&&*mid!=x;){
		if(x<*mid)end=mid;
		else beg=mid+1;
		mid=beg+(end-beg)/2; ////////////刷新中点位置啊！ 仔细 
	}
	auto jugde=mid-ivec.cbegin()+1;
	if(jugde>ivec.size())cout<<"没有";
	else cout<<mid-ivec.cbegin()+1;
	return  0;
 }
