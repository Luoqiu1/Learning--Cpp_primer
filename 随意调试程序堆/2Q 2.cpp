#include <iostream>
using namespace std;

int main ()
{
	int r,y,g;
	int n;
	int k,t;
	long long ans=0;//进行到当前道路下的总时间
	cin>>r>>y>>g;cin>>n;
	int loop=r+y+g;//红黄绿三灯循环一次的时间
	while(n--){
		cin>>k>>t;
		if(k==0)ans+=t;
		else{
			if(ans-t<=0){//还在该灯的时间内 
				if(k==1) ans=t;//红灯等待时间 
				else if(k==3) ;//绿灯通过 
				else ans=t+r;//黄灯+红灯等待时间 
			}
			else{
				int cur=(ans-t)%loop;//从该灯的下一个灯开始
				if(k==1){//绿 
					if(cur<g);//处于绿
					else ans+=r+(y-(cur-g)); 
				}
				else if(k==2){//红
					if(cur<r)ans+=r-cur;//处于红 
					else if(cur>=r&&cur<r+g);//处于绿
					else{//处于黄 
						ans+=loop-cur+r;
					}
				}
				else{//黄 
					if(cur<y)ans+=y-cur+r;
					else if(cur>=y&&cur<y+r)ans+=y+r-cur;
				}
			}
		}
	}
	cout<<ans;
	return 0;
 } 
