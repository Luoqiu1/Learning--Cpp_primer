#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
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
int main ()
{
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
	return 0;
}
