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
	for(int i=1;i<=m;i++) cin>>arcs[i].x>>arcs[i].y>>arcs[i].w;//�������� 
	sort(arcs+1,arcs+1+m,cmp);//����С�������ı߰��ǵݼ����򣬼򻯲��� 
	for(int i=1;i<=n;i++) sign[i]=i;//
	for(int i=1;i<=m;i++){	//��һ��ѭ��ʱ������arcs[1].x=4,arcs[1].y=8;
										//�������������˵��� 4 8	
										//��һ��ѭ���У�sign[i]==i�ǳ�����
										//�ʵ�һ��ѭ������ x=4;y=8;	
		int x=get(arcs[i].x); 
		int y=get(arcs[i].y);			
		if(x==y) continue;				//�����ѱ�ѹ��Ϊͬһ��־����һ������ǽ���״̬ѹ������䣩 

		sign[x]=y;	//���� 4 ͬ 8 ��Ч����һ����״̬ѹ��˼�룡 //����ͬ�ĵ㲢��Ϊͬһ��־ȷ���� 
					//�������־��Ȼ���Ա��ҵ��� 
					//һ��ʼ��Ȼ��һ���� sign[x]==x �ģ�
					//��Ϊ�ڳ�ʼ��ʱ��for��ʼ����sign[i]=i��
					//���Ա�Ȼ����ͨ������ get �ݹ��ҵ���� ͬһ�����־�� 

		Max=max(Max,arcs[i].w);//�Ƚϣ����� 
	}
	cout<<Max;
	return 0;
}
