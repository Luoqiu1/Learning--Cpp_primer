#include <bits/stdc++.h>
using namespace std;
int sign[100010];

struct arc{
	int x,y,w;
}arcs[500010];

bool cmp(arc a,arc b)
{
	return a.w<b.w;
}

int get(int x){
	if(x==sign[x]) return x;
	return sign[x]=get(sign[x]);
}

int main()
{
	int n,m;
	int Max=-0x3f3f3f3f;
	int gogogo;
	cin>>n>>m>>gogogo;
	for(int i=1;i<=m;i++) cin>>arcs[i].x>>arcs[i].y>>arcs[i].w;//读入数据 
	sort(arcs+1,arcs+1+m,cmp);//将最小生成树的边按非递减排序，简化操作 
	for(int i=1;i<=n;i++) sign[i]=i;//
	for(int i=1;i<=m;i++){	//第一次循环时，假设arcs[1].x=4,arcs[1].y=8;
										//即无向网的两端点是 4 8	
										//第一次循环中，sign[i]==i是成立的
										//故第一次循环中有 x=4;y=8;	
		int x=get(arcs[i].x); 
		int y=get(arcs[i].y);			
		if(x==y) continue;				//倘若已被压缩为同一标志（下一条语句是进行状态压缩的语句） 

		sign[x]=y;	//即将 4 同 8 等效，这一步是状态压缩思想！ //将不同的点并入为同一标志确定！ 
					//而这个标志必然可以被找到！ 
					//一开始必然有一点是 sign[x]==x 的！
					//因为在初始化时，for初始化了sign[i]=i！
					//所以必然能在通过函数 get 递归找到这个 同一代表标志！ 

		Max=max(Max,arcs[i].w);//比较，更新 
	}
	cout<<Max;
	return 0;
}
