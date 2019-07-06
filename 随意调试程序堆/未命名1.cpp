#include<iostream>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int f[3000],f1[1500];
int get(int x){
	if(x==f[x]) return x;
	else return f[x]=get(f[x]);
}
struct node{
	int a,b;
	int v;
}s[20000];
bool cmp(node a,node b){
	return a.v<b.v;
}
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		memset(s,0,sizeof(s));
		for(int i=0;i<m;i++){
			cin>>s[i].a>>s[i].b>>s[i].v;
		}
		sort(s,s+m,cmp);
		memset(f,0,sizeof(f));
		for(int i=1;i<=n;i++) f[i]=i;
		memset(f1,0,sizeof(f1));
		int ans=0,l=0,Max,k=0;
		for(int i=0;i<m;i++){
			int x=get(s[i].a),y=get(s[i].b);
		//	printf("%d\n",Max);
			if(Max==s[i].v) l=i+1;
		//	printf("f1[%d]=%d\n",i,f1[i]);
		//	printf("%d\n",l);
		    if(k>n-1) continue;
			if(x==y) continue;
			printf("%d %d\n",s[i].a,s[i].b);
			f[x]=y;
			Max=s[i].v;
			ans+=s[i].v;
			f1[i]=1;
			k++;
			l=i+1;
		//	printf("f1[%d]=%d\n",i,f1[i]);
		}
		printf("%d\n",l);
		int ans2=0;
		bool flag=true;
	//	printf("%d\n",l);
		for(int i=0;i<l;i++){
			if(!f1[i]){
				printf("%d %d %d\n",s[i].a,s[i].b,s[i].v);
				int x=get(s[i].a),y=get(s[i].b);
				int z=get(s[0].a);
			//	printf("x=%d y=%d z=%d\n",x,y,z);
				if(x==z&&y==z||x!=y){
					flag=false;
					break;
				}
	            if(x==y) continue;
				f[x]=y; 
				ans2+=s[i].v;
				f[x]=y;
			}
		}
		if(flag) printf("%d\n",ans);
		else printf("Not Unique!\n");
	}
}
