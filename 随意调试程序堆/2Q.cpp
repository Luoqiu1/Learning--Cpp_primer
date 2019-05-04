#include <iostream>
using namespace std;

int main ()
{
	int r,y,g;
	int n;
	int k,t;
	int ans=0;//进行到当前道路下的总时间
	cin>>r>>y>>g;cin>>n;
	int loop=r+y+g;//红黄绿三灯循环一次的时间 
	while(n--){
		cin>>k>>t;
		if(ans==0){//出发时刻 
			if(k==1||k==0){
			ans+=t;
			}
			else if(k==2){
				ans+=t+r;
			}
		}
		else{
	//		int cur=(T+t)%loop;//表示当下显示牌的时间（未换算为具体某灯，是循环时间内的绝对时间） 
							//基于的是当下指示灯颜色下的绝对时间！
			int cur=ans%loop;
			if(k==0){//无灯，直接加上耗时 
				ans+=t;
			}
			else if(k==1){//红灯 
				if(cur>=t){//超过了红灯亮起时间 
					if(cur-t>=g){//超过了绿灯亮起时间 
						if(cur-t-g>=y){//超过了黄灯亮起时间
							ans+=r-(cur-t-g-y);
						}
						else{//未超过黄灯亮起时间 
							ans+=(y-(cur-t-g))+r;
						}
					}
					else{//处于绿灯期 
					}
				}
				else{//处于红灯期 
					ans+=t-cur;
				}
			}
			else if(k==2){//黄灯 
				if(cur>=t){//超过了黄灯亮起时间 
					if(cur-t-r<=0){//处于红灯期 
						ans+=r-(cur-t);
					}
					else{//绿灯区 
					}
				}
				else{//处于黄灯期
					ans+=t-cur+r;
				}
			}
			else{//绿灯时 
				if(cur>=t){//超过了绿灯亮起时间
					if(cur-t>=y){//超过了黄灯亮起时间 
						 if(cur-t-y>=r){//超过了红灯亮起时间，仍处于绿灯 
						 }
						 else{//红灯期 
						 	ans+=r-(cur-t-y);
						 }
					}
					else{//处于黄灯期
						ans+=y-(cur-t);
					}
				}
				else{//绿灯期 
				}
			}
		}
//		cout<<"now "<<ans<<endl;
	}
	cout<<ans;
	return 0;
}
