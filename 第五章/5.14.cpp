#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
	
	
//	string s0,pre,maxs;
//	unsigned cur=0,maxCnt=0;
//	while(cin>>s0){
//		if(s0==pre)cur++;
//		else {
//			if(cur>maxCnt){
//				maxCnt=cur;maxs=pre;
//			}
//			cur=0;
//		}
//		pre=s0;
//	}
//	if(cur>maxCnt){
//				maxCnt=cur;maxs=pre;
//	}
//	if(maxCnt==0)cout<<"No"<<endl;
//	else cout<<"The max is "<<maxs<<" lianxu occurs "<<maxCnt+1<<" times"<<endl;

	vector<int>ivec1,ivec2;
	int i;
	while(cin>>i&&i!=999){
		ivec1.push_back(i);
	} 
	while(cin>>i){
		ivec2.push_back(i);
	}
	bool t1=true; 
	bool flag=true;
	bool eq=false;
	if(ivec1.size()<ivec2.size()){
		for(decltype(ivec1.size())i=0,sz=ivec1.size();i!=sz;i++){
			if(ivec1[i]!=ivec2[i]){
				flag=!flag;break;
			}
		}
	}
	else if(ivec2.size()<ivec1.size()){
		t1=!t1;
		for(decltype(ivec1.size())i=0,sz=ivec2.size();i!=sz;i++){
			if(ivec1[i]!=ivec2[i]){
				flag=!flag;break;
			}
		}
	}
	else{
		eq=true;
		for(decltype(ivec1.size())i=0,sz=ivec2.size();i!=sz;i++){
			if(ivec1[i]!=ivec2[i]){
				flag=!flag;break;
			}
		}
	}
	if(flag){
		if(eq)cout<<"两者相等";
		else if(t1)cout<<"ivec1 is 前缀";
		else cout<<"ivec2 is 前缀";
	}
	else{
		cout<<"两者非前缀关系";
	}
	return 0;
}
