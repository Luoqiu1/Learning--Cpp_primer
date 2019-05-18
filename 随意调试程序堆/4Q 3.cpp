#include<iostream>
#include<cstring>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
struct arc{
	int x,y,w;
}arcs[500010];
int sign[100010];
//bool operator < (rec a,rec b){
//	return a.z<b.z;
//}
bool cmp(arc a,arc b)
{
	return a.w<b.w;
}
int get(int x){
	if(x==sign[x]) return x;
	else return sign[x]=get(sign[x]);
}
int main()
{
	int n,m,ans=0,root;
	cin>>n>>m>>root;
	for(int i=1;i<=m;i++){
		cin>>arcs[i].x>>arcs[i].y>>arcs[i].w;
	}
	sort(arcs+1,arcs+1+m,cmp);
	for(int i=1;i<=n;i++) sign[i]=i;
	for(int i=1;i<=m;i++){
		int x=get(arcs[i].x);
		int y=get(arcs[i].y);
		if(x==y) continue;
		sign[x]=y;
		ans=max(ans,arcs[i].w);
	}
	cout<<ans;
}

