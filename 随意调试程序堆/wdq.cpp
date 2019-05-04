#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int main()
{
	int r,y,g;
	cin>>r>>y>>g;
	int n;
	cin>>n;
	int k=r+y+g;
	long long sum=0,num,t,m;
	for(int i=0;i<n;i++){
		cin>>num>>t;
		if(num==0) sum+=t;
		else{
			if(sum-t<=0){
				if(num==1) sum+=(t-sum);
				else if(num==3) sum+=0;
				else sum+=(t-sum+r); 
			}
			else{
				m=(sum-t)%k;
				if(num==1){
					if(m<g) sum+=0;
					else if(m>=g) sum+=(k-m);
				}
				else if(num==2){
					if(m<r) sum+=(r-m);
					else if(m>=r&&m<r+g) sum+=0;
					else sum+=((k-m)+r);
				}
				else {
					if(m<r+y) sum+=(r+y)-m;
					else sum+=0;
				}
			}
		}
		//printf("%d\n",sum);
	}
	printf("%lld",sum);
}
