#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
	string s0,pre,maxs;
	unsigned cur=0,maxCnt=0;
	while(cin>>s0){
		if(s0==pre)cur++;
		else {
			if(cur>maxCnt){
				maxCnt=cur;maxs=pre;
			}
			cur=0;
		}
		pre=s0;
	}
	if(cur>maxCnt){
				maxCnt=cur;maxs=pre;
	}
	if(maxCnt==0)cout<<"No"<<endl;
	else cout<<"The max is "<<maxs<<" lianxu occurs "<<maxCnt+1<<" times"<<endl;
	return 0;
}
