#include <iostream>
using namespace std;

int main ()
{
	int r,y,g;
	int n;
	int k,t;
	int ans=0;
	cin>>r>>y>>g;cin>>n; 
	while(n--){
		cin>>k>>t;
		if(k==1||k==0){
			ans+=t;
		}
		else if(k==2){
			ans+=t+r;
		}
	}
	cout<<ans;
	return 0;
 }
