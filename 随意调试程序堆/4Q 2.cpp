#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define INFINITY 0x3f3f3f3f
#define Ok 1
#define Error 0
#define Overflow -2
#define True 1
#define MAX_VERTEX_NUM 5
typedef int Status;
typedef char VertexType;
typedef int InfoType;
typedef int VRType;
typedef enum{DG,DN,UDG,UDN}GraphKind;
int Max,root;

typedef struct mini{
	VertexType adjvex;//������������������ݽṹ��
					//���adjvex ������ǻ�β��ֵ�ˣ� 
	VRType lowcost;
}closedge[5];

typedef struct ArcNode{
	
	//���������ˣ��ڽӱ��������������ͬһ�������µ��ڽӵĻ��ļ��ϣ�
	//ͨ��������������ݽṹ����Ϊ���ݽṹ��Ϊ������ĳһҪ���������������ģ� 
	int adjvex; 
	InfoType *info;
	struct ArcNode *nextarc;
}ArcNode;
//typedef struct AdjList{
typedef struct VNode{
	VertexType data;
	ArcNode *firstarc;
}VNode,AdjList[5];

typedef struct ALGraph{
	GraphKind kind;
	AdjList vertices;
	//��ǰ����µĶ����������� һ����Ҫ���ǰ������� 
	int vexnum,arcnum;
}ALGraph;

Status CreateUDN(ALGraph &G)
{
	int i,j,k,w;
	VertexType v1,v2;
	ArcNode *pi,*pj;
//	printf("���붥���� G.vexnum��");
	scanf("%d",&G.vexnum);
//	printf("������� G.arcnum��");
	scanf("%d",&G.arcnum);
	scanf("%d",&root);
	root-=1;
	for(i=0;i<G.vexnum;++i){
//		printf("���붥�� G.vertices[%d].data:",i);
//		scanf("%c",&G.vertices[i].data);getchar();
		G.vertices[i].firstarc=nullptr;
	}
	for(k=0;k<G.arcnum;++k){
//		printf("������� %d ���ߵĶ��� v1��v2 �Լ�Ȩֵ w (int)��\n",k+1);
		scanf("%d %d %d",&i,&j,&w);
		i-=1;j-=1;
		if(!(pi=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
		if(!(pi->info=(InfoType*)malloc(sizeof(InfoType))))exit(Overflow);
		//�ٴ����malloc��Ϊĳһָ�����һ�ռ䣬��ʵ���Ƿ�����һ������ĵ�ַ�� 
		*pi->info=w;
		pi->adjvex=j;pi->nextarc=G.vertices[i].firstarc;
		G.vertices[i].firstarc=pi;
		if(!(pj=(ArcNode*)malloc(sizeof(ArcNode))))exit(Overflow);
		if(!(pj->info=(InfoType*)malloc(sizeof(InfoType))))exit(Overflow);
		*pj->info=w;
		pj->adjvex=i;pj->nextarc=G.vertices[j].firstarc;
		G.vertices[j].firstarc=pj;
	}
	return Ok;
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
		int min=INFINITY;
		for(int j=0;j<G.vexnum;++j){					//�ҳ���С���ڱߣ� 
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
		}
		
	}
	printf("%d",Max);
	return Ok;
}

int main()
{
	printf("here234");
	ALGraph G;
	CreateUDN(G);
	MiniSpanTree_PRIM(G);
	return 0;
}

