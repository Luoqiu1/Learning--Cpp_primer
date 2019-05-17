#include <iostream>
#include <cstdio>
using namespace std;
#define Ok 1
#define Error 0
#define Overflow -2
#define True 1
#define INFINITY 0x3f3f3f3f
#define MAX_VERTEX_NUM 500
typedef int Status;
typedef char VertexType;
typedef int InfoType;
typedef int VRType;
typedef enum{DG,DN,UDG,UDN}GraphKind; 
int Max,root;

typedef struct AdjCell{
	VRType adj;
	InfoType *info;
}AdjCell,AdjMatrix[MAX_VERTEX_NUM][MAX_VERTEX_NUM];
typedef struct MGraph{
	GraphKind kind;
	int vexnum,arcnum;
	AdjMatrix arcs;
	VertexType vexs[MAX_VERTEX_NUM];
}MGraph; 

Status CreateUDN(MGraph &G)
{
	int i,j,k,w;
	VertexType v1,v2;
//	printf("输入顶点数 G.vexnum: ");
	scanf("%d",&G.vexnum);
//	printf("输入边数 G.arcnum: ");
	scanf("%d",&G.arcnum);
	scanf("%d",&root);
	root-=1;
//	getchar();//吸收缓冲区的回车
//	for(i=0;i<G.vexnum;++i){
//		printf("输入顶点G.vexs[%d]: ",i);
//		scanf("%c",&G.vexs[i]);getchar();
//	}
	for(i=0;i<G.vexnum;++i){
		for(j=0;j<G.vexnum;++j){
			G.arcs[i][j].adj=INFINITY;
			G.arcs[i][j].info=nullptr;
		}
	}
	for(k=0;k<G.arcnum;++k){
	//	printf("输入第 %d 条边的顶点 vi、vj 以及权值 w (int):\n",k+1);
		scanf("%d %d %d",&i,&j,&w);//getchar();
		i-=1;j-=1;
		G.arcs[i][j].adj=G.arcs[j][i].adj=w;//无向网 
		//if(Inclnfo)scanf(G.arcs[i][j].info)//输入弧含有的相关信息 
	}
	return Ok; 
}


typedef struct mini{
	VertexType adjvex;//理解这个辅助数组的数据结构！
					//这个adjvex 代表的是弧尾的值了！ 
	VRType lowcost;
}closedge[MAX_VERTEX_NUM];

//bool cmp(closedge a,closedge b)
//{
//	return a->lowcost>b->lowcost;
//}

Status MiniSpanTree_PRIM(MGraph G)
{
	closedge Aid;
	int k=root;
	for(int i=0;i<G.vexnum;++i){
		if(i!=k){
			Aid[i].lowcost=G.arcs[k][i].adj;
			Aid[i].adjvex=G.vexs[k];
		}
	}
	Aid[k].lowcost=0;//Aid[k].adjvex=u;
//	cout<<endl;
//	for(int i=0;i<G.vexnum;++i)if(Aid[i].lowcost!=INFINITY)cout<<Aid[i].lowcost;else cout<<"s"; 
	for(int i=1;i<G.vexnum;++i){
		int min=INFINITY;
		for(int j=0;j<G.vexnum;++j){//找出最小的邻边！ 
		//	int min=INFINITY;
			//啊啊啊啊上一行真是傻了。。。每一次新循环都会重置啊！仔细。。 
			if(Aid[j].lowcost<min&&Aid[j].lowcost!=0){
				min=Aid[j].lowcost;k=j;
	//			cout<<"k="<<k; 
			}
		}
		if(Max<Aid[k].lowcost)Max=Aid[k].lowcost;
	//	printf("now k=%d\n",k);
		Aid[k].lowcost=0;
	//	printf("%c%c ",G.vexs[k],Aid[k].adjvex);
		for(int i=0;i<G.vexnum;++i){
			if(Aid[i].lowcost>G.arcs[k][i].adj){
				Aid[i].lowcost=G.arcs[k][i].adj;
				Aid[i].adjvex=G.vexs[k];
			}
		}
	//	sort(Aid,Aid+G.vexnum,cmp);
		
	}
	printf("%d",Max);
	return Ok;
}

int main()
{
	MGraph G;
	CreateUDN(G);
	MiniSpanTree_PRIM(G);
	return 0;
}


