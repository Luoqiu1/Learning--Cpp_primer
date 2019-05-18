#include <bits/stdc++.h>
using namespace std;
typedef int Status;
typedef char VertexType;
typedef int InfoType;
typedef int VRType;
int Max,root;

typedef struct mini{
	VertexType adjvex;
	VRType lowcost;
}closedge[5000];

typedef struct ArcNode{
	int adjvex; 
	InfoType *info;
	struct ArcNode *nextarc;
}ArcNode;
typedef struct VNode{
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[5000];
typedef struct ALGraph{
	AdjList vertices;
	int vexnum,arcnum;
}ALGraph;

Status CreateUDN(ALGraph &G)
{
	int i,j,k,w;
	VertexType v1,v2;
	ArcNode *pi,*pj;
	scanf("%d",&G.vexnum);
	scanf("%d",&G.arcnum);
	scanf("%d",&root);
	root-=1;
	for(i=0;i<G.vexnum;++i){
		G.vertices[i].firstarc=NULL;
	}
	for(k=0;k<G.arcnum;++k){
		scanf("%d %d %d",&i,&j,&w);
		i-=1;j-=1;
		if(!(pi=(ArcNode*)malloc(sizeof(ArcNode))));
		if(!(pi->info=(InfoType*)malloc(sizeof(InfoType))));
		*pi->info=w;
		pi->adjvex=j;pi->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=pi;
		if(!(pj=(ArcNode*)malloc(sizeof(ArcNode))));
		if(!(pj->info=(InfoType*)malloc(sizeof(InfoType))));
		*pj->info=w;
		pj->adjvex=i;pj->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=pj;
	}
	return 1;
}

Status MiniSpanTree_PRIM(ALGraph G)
{
	closedge Aid;
	int k=root;
	ArcNode *p=G.vertices[root].firstarc;
	while(p){
		Aid[p->adjvex].lowcost=*p->info;
		p=p->nextarc;
	}
	Aid[root].lowcost=0;
	for(int i=1;i<G.vexnum;++i){
		int min=0x3f3f3f3f;
		for(int j=0;j<G.vexnum;++j){					//找出最小的邻边！ 
			if(Aid[j].lowcost<min&&Aid[j].lowcost!=0){
				min=Aid[j].lowcost;k=j;
			}
		}
		if(Max<Aid[k].lowcost)Max=Aid[k].lowcost;
		Aid[k].lowcost=0;
		
//		for(int i=0;i<G.vexnum;++i){
//			if(Aid[i].lowcost>G.arcs[k][i].adj){
//				Aid[i].lowcost=G.arcs[k][i].adj;
//				Aid[i].adjvex=G.vexs[k];
//			}
//		}
		p=G.vertices[k].firstarc;
		while(p){
			if(Aid[p->adjvex].lowcost>*p->info){
				Aid[p->adjvex].lowcost=*p->info;
			}
			p=p->nextarc;
		}
		
	}
	printf("%d",Max);
	return 1;
}

int main()
{
	printf("here");
	ALGraph G;
	CreateUDN(G);
	MiniSpanTree_PRIM(G);
	return 0;
}

