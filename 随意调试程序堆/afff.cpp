#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct rec{
	int x,y,z;
}edge[500010];
int fa[100010];
bool operator < (rec a,rec b){
	return a.z<b.z;
}
int get(int x){
	if(x==fa[x]) return x;
	else return fa[x]=get(fa[x]);
}
int main()
{
	int n,m,ans=0,root;
	cin>>n>>m>>root;
	for(int i=1;i<=m;i++){
		cin>>edge[i].x>>edge[i].y>>edge[i].z;
	}
	sort(edge+1,edge+1+m);
	for(int i=1;i<=n;i++) fa[i]=i;
	for(int i=1;i<=m;i++){
		int x=get(edge[i].x);
		int y=get(edge[i].y);
		if(x==y) continue;
		fa[x]=y;
		ans=max(ans,edge[i].z);
	}
	cout<<ans;
}

