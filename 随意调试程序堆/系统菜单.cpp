#include <bits/stdc++.h>
using namespace std;

void Go1(void)
{
	printf("���ѳɹ�������Ŀһ���밴Ҫ���������ݣ����ǽ���������\n");
	int r,y,g;
	int n;
	int k,t;
	int ans=0;
	cin>>r>>y>>g;cin>>n; 
	while(n--){
		cin>>k>>t;
		if(k==1||k==0){
			ans+=t;
		}
		else if(k==2){
			ans+=t+r;
		}
	}
	printf("��Ϊ��");cout<<ans;
}

void Go2(void)
{
	printf("���ѳɹ�������Ŀ�����밴Ҫ���������ݣ����ǽ���������\n");
	int r,y,g;
	int n;
	int k,t;
	long long ans=0;//���е���ǰ��·�µ���ʱ��
	cin>>r>>y>>g;cin>>n;
	int loop=r+y+g;//���������ѭ��һ�ε�ʱ��
	while(n--){
		cin>>k>>t;
		if(k==0)ans+=t;
		else{
			if(ans-t<=0){//���ڸõƵ�ʱ���� 
				if(k==1) ans=t;//��Ƶȴ�ʱ�� 
				else if(k==3) ;//�̵�ͨ�� 
				else ans=t+r;//�Ƶ�+��Ƶȴ�ʱ�� 
			}
			else{
				int cur=(ans-t)%loop;//�ӸõƵ���һ���ƿ�ʼ
				if(k==1){//�� 
					if(cur<g);//������
					else ans+=r+(y-(cur-g)); 
				}
				else if(k==2){//��
					if(cur<r)ans+=r-cur;//���ں� 
					else if(cur>=r&&cur<r+g);//������
					else{//���ڻ� 
						ans+=loop-cur+r;
					}
				}
				else{//�� 
					if(cur<y)ans+=y-cur+r;
					else if(cur>=y&&cur<y+r)ans+=y+r-cur;
				}
			}
		}
	}
	printf("��Ϊ��");cout<<ans;
}

	typedef struct ip{
	vector<string> s{"","","",""};//��ǰ׺���� 
	long long frontip;//ip��ַ 
	unsigned int len;//ǰ׺
	unsigned int pointCnt;
	//���� 101.6.6.0/24    ip��ַΪ101.6.6.0����Ӧ��ʮ������
	//                     ǰ׺Ϊ 24  
}ip;
long long goNum(string s)
{
	long long ans=0;
	for(auto x:s){
		ans*=10;
		switch(x){
			case'0':ans+=0;break;
			case'1':ans+=1;break;
			case'2':ans+=2;break;
			case'3':ans+=3;break;
			case'4':ans+=4;break;
			case'5':ans+=5;break;
			case'6':ans+=6;break;
			case'7':ans+=7;break;
			case'8':ans+=8;break;
			case'9':ans+=9;break;
		}
	}
	return ans;
}
bool cmp(const ip a,const ip b)
{
	if(a.frontip==b.frontip)return a.len<b.len;
	return a.frontip<b.frontip;
}
void Go3(void)
{
	printf("���ѳɹ�������Ŀ�����밴Ҫ���������ݣ����ǽ���������\n");
	const vector<unsigned int> num{1,256,65536,16777216}; 
	vector<ip> ivec;
	int n;cin>>n;
	while(n--){
		ip curip;
		string s;cin>>s;
		unsigned int pointCnt=0;
		bool iflen=false;//�ж��Ƿ���ʾ��������ǰ׺len
		string curlen;
		string curS;//ÿһ��point('.')ǰ����ʾ�ĵ��ʮ���������ַ�����ʽ 
		for(auto x:s){
			curS+=x;
			if(iflen)curlen+=x;
			if(x=='.')++pointCnt;
			if(x=='/')iflen=true;
		}
		//�����ȶ�ip��ַ��ʼ�� 
		if(!pointCnt&&!iflen){//û��'.'Ҳû��ǰ׺len
			curip.s[0]=curS;
			curip.frontip=goNum(curS)*num[3];//ֱ��ת�� 
		}
		else if(!pointCnt&&iflen){//û��'.'����ǰ׺len 
			string curS;
			for(auto x:s){
				if(x=='/')break;
				curS+=x;
			}
			curip.s[0]=curS;
			curip.frontip=goNum(curS)*num[3];//ֱ��ת��
		}
		else if(pointCnt&&!iflen){//��'.'û��ǰ׺
			string curS; 
			long long curpoint=0;
			long long nowip=0;
			for(auto x:s){
				if(x=='.'){
					curip.s[curpoint]=curS;
					nowip+=goNum(curS)*num[3-curpoint];
					curpoint++;
					curS="";
				}
				else curS+=x;
			}//����ʱ�������һ������û�д��� 
			curip.s[curpoint]=curS;
			nowip+=goNum(curS);
			curip.frontip=nowip;
		}
		else if(pointCnt&&iflen){//��'.'��ǰ׺
			string curS; 
			long long curpoint=0;
			long long nowip=0;
			for(auto x:s){
				if(x=='/')break;
				if(x=='.'){
					curip.s[curpoint]=curS;
					nowip+=goNum(curS)*num[3-curpoint];
					curpoint++;
					curS="";
				}
				else curS+=x;
			}//����ʱ�������һ������û�д��� 
			curip.s[curpoint]=curS;
			nowip+=goNum(curS);
			curip.frontip=nowip;
		}
		//�����ǰ׺��ʼ�� 
		if(!iflen){//ʡ����ǰ׺����len
			curip.len=(pointCnt+1)*8;
		}
		else{//��ʾ��������ǰ׺���� 
			curip.len=goNum(curlen);
		}
		curip.pointCnt=pointCnt;
		ivec.push_back(curip);
	}
	sort(ivec.begin(),ivec.end(),cmp);//ip��ַΪ��һ�ؼ��������� ǰ׺����Ϊ�ڶ��ؼ��ֺ�����
//	for(auto x:ivec){
//		cout<<x.frontip<<" ";
//	}
	bool flag2=true;
	for(auto it=ivec.begin();it!=ivec.end();){
		if(ivec.end()-it>1){
		//	cout<<"vec "<<(ivec[i].frontip>>(32-ivec[i].len)==ivec[i+1].frontip>>(32-ivec[i+1].len))<<endl;
		//	cout<<"vec: "<<ivec[i].frontip<<' '<<ivec[i+1].frontip<<endl;
		//	if(ivec[i].frontip>>(32-ivec[i].len)==ivec[i+1].frontip>>(32-ivec[i].len)&&ivec[i].len!=ivec[i+1].len){//����Ԫ����ǰ��Ԫ�ص�ƥ�伯�Ӽ� 
			if((*it).frontip>>(32-(*it).len)==(*(it+1)).frontip>>(32-(*it).len)&&(*it).len<(*(it+1)).len||(*it).frontip==(*(it+1)).frontip&&(*it).len==(*(it+1)).len){
				it=ivec.erase(it+1);
				if(it-ivec.begin()>=2){
					it=it-2;
				}
				else if(ivec.size()==2&&flag2){
					it=it-2;flag2=!flag2;
				}
			}
			else ++it;
		}
		else ++it;//��һ���ж�����ʱit==ed������ѭ�� 
	}
//	cout<<"siezof now "<<ivec.size()<<endl;
	bool flag=true;
	for(auto it=ivec.begin();it!=ivec.end();){
		if(ivec.end()-it>1){
		//	if(ivec[i].len==ivec[i+1].len){//������Ԫ�ص�ǰ׺��ͬ 
			if((*it).len==(*(it+1)).len){
			//	ip newip=ivec[i];--newip.len;
				ip newip=(*it);--newip.len;
			//	if(!((newip.frontip>>ivec[i].len)&1)){//���Ϸ� 
			//	cout<< (newip.frontip>>(*it).len);
				if(!((newip.frontip>>(32-(*it).len))&1)){
					if(newip.frontip>>(32-newip.len)==(*(it+1)).frontip>>(32-newip.len)){
				//		cout<<"here2"<<endl;
						(*it)=newip;
						it=ivec.erase(it+1);
						if(it-ivec.begin()>=2){
							it=it-2;
						}
						else if(ivec.size()==2&&flag){
							it=it-2;flag=!flag; 
						}
					}
					else ++it;
				}
				else ++it;
			}
			else ++it;
		}
		else ++it;//��һ���ж�����ʱit==ed������ѭ�� 
	}
//	cout<<"sizeof now "<<ivec.size()<<endl;
	printf("��Ϊ��\n"); 
	for(auto it=ivec.begin(),ed=ivec.end();it!=ed;++it){
	//	cout<<"Here1"; 
		for(int i=0;i<4;i++){
			if((*it).s[i]=="")cout<<0;
			else cout<<(*it).s[i];
			if(i!=3)cout<<'.';
			else cout<<'/';
		}
		cout<<(*it).len;
		cout<<endl;
	}
} 
int sign[100010];

struct arc{
	int x,y,w;
}arcs[500010];

bool cmp1(arc a,arc b)
{
	return a.w<b.w;
}

int getSign(int x){
	if(x==sign[x]) return x;
	return sign[x]=getSign(sign[x]);
}
void Go4(void)
{
	printf("���ѳɹ�������Ŀ�ģ��밴Ҫ���������ݣ����ǽ���������\n");
	int n,m;
	int Max=-0x3f3f3f3f;
	int gogogo;
	cin>>n>>m>>gogogo;
	for(int i=1;i<=m;i++) cin>>arcs[i].x>>arcs[i].y>>arcs[i].w;//�������� 
	sort(arcs+1,arcs+1+m,cmp1);//����С�������ı߰��ǵݼ����򣬼򻯲��� 
	for(int i=1;i<=n;i++) sign[i]=i;//
	for(int i=1;i<=m;i++){	//��һ��ѭ��ʱ������arcs[1].x=4,arcs[1].y=8;
										//�������������˵��� 4 8	
										//��һ��ѭ���У�sign[i]==i�ǳ�����
										//�ʵ�һ��ѭ������ x=4;y=8;	
		int x=getSign(arcs[i].x); 
		int y=getSign(arcs[i].y);			
		if(x==y) continue;				//�����ѱ�ѹ��Ϊͬһ��־����һ������ǽ���״̬ѹ������䣩 

		sign[x]=y;	//���� 4 ͬ 8 ��Ч����һ����״̬ѹ��˼�룡 //����ͬ�ĵ㲢��Ϊͬһ��־ȷ���� 
					//�������־��Ȼ���Ա��ҵ��� 
					//һ��ʼ��Ȼ��һ���� sign[x]==x �ģ�
					//��Ϊ�ڳ�ʼ��ʱ��for��ʼ����sign[i]=i��
					//���Ա�Ȼ����ͨ������ get �ݹ��ҵ���� ͬһ�����־�� 

		Max=max(Max,arcs[i].w);//�Ƚϣ����� 
	}
	printf("��Ϊ��");cout<<Max;
} 
int main()
{
	printf("������Ҫ�������Ŀ��\n���� 1 ��ʾ������Ŀһ������ 2 ��ʾ������Ŀ�������� 3 ��ʾ������Ŀ�������� 4 ��ʾ������Ŀ�ģ�");
	printf("\n�������� k ��ʾ��Ҫ�������Ŀ��\nk = ");
	int k;cin>>k;
	switch(k){
		case 1:Go1();break;
		case 2:Go2();break;
		case 3:Go3();break;
		case 4:Go4();break;
	}
	return 0;
}
