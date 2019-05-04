#include <vector>
#include <iostream>
using namespace std;

int main ()
{
	vector<int> ivec{1,2,3,4};
	int i=0;
	for(auto it=ivec.begin();it!=ivec.end();){
		if(it+1!=ivec.end()){
			if(ivec[i]==2){
				it=ivec.erase(it+1);
				it=it-1;
				cout<<' '<<*it;
			}
			else ++it,++i;
		}
		else ++it,++i;
	}
	for(auto x:ivec)cout<<x;
	return 0;
 } 
