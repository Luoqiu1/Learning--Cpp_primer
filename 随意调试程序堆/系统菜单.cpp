#include <bits/stdc++.h>
using namespace std;

void Go1(void)
{
	printf("您已成功进入题目一！请按要求输入数据，我们将输出结果！\n");
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
	printf("答案为：");cout<<ans;
}

void Go2(void)
{
	printf("您已成功进入题目二！请按要求输入数据，我们将输出结果！\n");
	int r,y,g;
	int n;
	int k,t;
	long long ans=0;//进行到当前道路下的总时间
	cin>>r>>y>>g;cin>>n;
	int loop=r+y+g;//红黄绿三灯循环一次的时间
	while(n--){
		cin>>k>>t;
		if(k==0)ans+=t;
		else{
			if(ans-t<=0){//还在该灯的时间内 
				if(k==1) ans=t;//红灯等待时间 
				else if(k==3) ;//绿灯通过 
				else ans=t+r;//黄灯+红灯等待时间 
			}
			else{
				int cur=(ans-t)%loop;//从该灯的下一个灯开始
				if(k==1){//绿 
					if(cur<g);//处于绿
					else ans+=r+(y-(cur-g)); 
				}
				else if(k==2){//红
					if(cur<r)ans+=r-cur;//处于红 
					else if(cur>=r&&cur<r+g);//处于绿
					else{//处于黄 
						ans+=loop-cur+r;
					}
				}
				else{//黄 
					if(cur<y)ans+=y-cur+r;
					else if(cur>=y&&cur<y+r)ans+=y+r-cur;
				}
			}
		}
	}
	printf("答案为：");cout<<ans;
}

	typedef struct ip{
	vector<string> s{"","","",""};//非前缀部分 
	long long frontip;//ip地址 
	unsigned int len;//前缀
	unsigned int pointCnt;
	//例如 101.6.6.0/24    ip地址为101.6.6.0所对应的十进制数
	//                     前缀为 24  
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
	printf("您已成功进入题目三！请按要求输入数据，我们将输出结果！\n");
	const vector<unsigned int> num{1,256,65536,16777216}; 
	vector<ip> ivec;
	int n;cin>>n;
	while(n--){
		ip curip;
		string s;cin>>s;
		unsigned int pointCnt=0;
		bool iflen=false;//判断是否显示地输入了前缀len
		string curlen;
		string curS;//每一个point('.')前所表示的点分十进制数的字符串形式 
		for(auto x:s){
			curS+=x;
			if(iflen)curlen+=x;
			if(x=='.')++pointCnt;
			if(x=='/')iflen=true;
		}
		//下面先对ip地址初始化 
		if(!pointCnt&&!iflen){//没有'.'也没有前缀len
			curip.s[0]=curS;
			curip.frontip=goNum(curS)*num[3];//直接转化 
		}
		else if(!pointCnt&&iflen){//没有'.'但有前缀len 
			string curS;
			for(auto x:s){
				if(x=='/')break;
				curS+=x;
			}
			curip.s[0]=curS;
			curip.frontip=goNum(curS)*num[3];//直接转化
		}
		else if(pointCnt&&!iflen){//有'.'没有前缀
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
			}//结束时还有最后一串数字没有处理 
			curip.s[curpoint]=curS;
			nowip+=goNum(curS);
			curip.frontip=nowip;
		}
		else if(pointCnt&&iflen){//有'.'有前缀
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
			}//结束时还有最后一串数字没有处理 
			curip.s[curpoint]=curS;
			nowip+=goNum(curS);
			curip.frontip=nowip;
		}
		//下面对前缀初始化 
		if(!iflen){//省略了前缀长度len
			curip.len=(pointCnt+1)*8;
		}
		else{//显示地声明了前缀长度 
			curip.len=goNum(curlen);
		}
		curip.pointCnt=pointCnt;
		ivec.push_back(curip);
	}
	sort(ivec.begin(),ivec.end(),cmp);//ip地址为第一关键字先排序 前缀长度为第二关键字后排序
//	for(auto x:ivec){
//		cout<<x.frontip<<" ";
//	}
	bool flag2=true;
	for(auto it=ivec.begin();it!=ivec.end();){
		if(ivec.end()-it>1){
		//	cout<<"vec "<<(ivec[i].frontip>>(32-ivec[i].len)==ivec[i+1].frontip>>(32-ivec[i+1].len))<<endl;
		//	cout<<"vec: "<<ivec[i].frontip<<' '<<ivec[i+1].frontip<<endl;
		//	if(ivec[i].frontip>>(32-ivec[i].len)==ivec[i+1].frontip>>(32-ivec[i].len)&&ivec[i].len!=ivec[i+1].len){//后面元素是前面元素的匹配集子集 
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
		else ++it;//下一次判断条件时it==ed，结束循环 
	}
//	cout<<"siezof now "<<ivec.size()<<endl;
	bool flag=true;
	for(auto it=ivec.begin();it!=ivec.end();){
		if(ivec.end()-it>1){
		//	if(ivec[i].len==ivec[i+1].len){//相邻两元素的前缀相同 
			if((*it).len==(*(it+1)).len){
			//	ip newip=ivec[i];--newip.len;
				ip newip=(*it);--newip.len;
			//	if(!((newip.frontip>>ivec[i].len)&1)){//若合法 
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
		else ++it;//下一次判断条件时it==ed，结束循环 
	}
//	cout<<"sizeof now "<<ivec.size()<<endl;
	printf("答案为：\n"); 
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
	printf("您已成功进入题目四！请按要求输入数据，我们将输出结果！\n");
	int n,m;
	int Max=-0x3f3f3f3f;
	int gogogo;
	cin>>n>>m>>gogogo;
	for(int i=1;i<=m;i++) cin>>arcs[i].x>>arcs[i].y>>arcs[i].w;//读入数据 
	sort(arcs+1,arcs+1+m,cmp1);//将最小生成树的边按非递减排序，简化操作 
	for(int i=1;i<=n;i++) sign[i]=i;//
	for(int i=1;i<=m;i++){	//第一次循环时，假设arcs[1].x=4,arcs[1].y=8;
										//即无向网的两端点是 4 8	
										//第一次循环中，sign[i]==i是成立的
										//故第一次循环中有 x=4;y=8;	
		int x=getSign(arcs[i].x); 
		int y=getSign(arcs[i].y);			
		if(x==y) continue;				//倘若已被压缩为同一标志（下一条语句是进行状态压缩的语句） 

		sign[x]=y;	//即将 4 同 8 等效，这一步是状态压缩思想！ //将不同的点并入为同一标志确定！ 
					//而这个标志必然可以被找到！ 
					//一开始必然有一点是 sign[x]==x 的！
					//因为在初始化时，for初始化了sign[i]=i！
					//所以必然能在通过函数 get 递归找到这个 同一代表标志！ 

		Max=max(Max,arcs[i].w);//比较，更新 
	}
	printf("答案为：");cout<<Max;
} 
int main()
{
	printf("请输入要进入的题目：\n输入 1 表示进入题目一；输入 2 表示进入题目二；输入 3 表示进入题目三；输入 4 表示进入题目四；");
	printf("\n请输入数 k 表示将要进入的题目！\nk = ");
	int k;cin>>k;
	switch(k){
		case 1:Go1();break;
		case 2:Go2();break;
		case 3:Go3();break;
		case 4:Go4();break;
	}
	return 0;
}
