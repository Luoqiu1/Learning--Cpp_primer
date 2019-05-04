#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef struct ip{
	unsigned int front;//ip地址 
	unsigned int len;//前缀
	//例如 101.6.6.0/24    ip地址为101.6.6.0所对应的十进制数
	//                     前缀为 24  
}ip;
unsigned int goNum(string s)
{
	unsigned int ans=0;
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
	return a.front<b.front;
}
bool cmp2(const ip a,const ip b)
{
	if(a.front==b.front)return a.len<b.len;
}
bool cmp3(const ip a,const ip b)
{
	if(a.front==b.front)return a.len<b.len;
	return a.front<b.front;
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
		if(!pointCnt&&!iflen){//没有'.'也没有前缀len
			curip.front=goNum(curS);//直接转化 
		}
		else if(!pointCnt&&iflen){//没有'.'但有前缀len 
			string curS;
			for(auto x:s){
				if(x=='/')break;
				curS+=x;
			}
			curip.front=goNum(curS);//直接转化
		}
		else if(pointCnt&&!iflen){//有'.'没有前缀
			string curS; 
			unsigned int curpoint=0;
			unsigned int nowip=0;
			for(auto x:s){
				if(x=='.'){
					nowip+=goNum(curS)*num[pointCnt-curpoint];
					curpoint++;
					curS="";
				}
				curS+=x;
			}//结束时还有最后一串数字没有处理 
			nowip+=goNum(curS);
			curip.front=nowip;
		}
		else if(pointCnt&&iflen){//有'.'有前缀
			string curS; 
			unsigned int curpoint=0;
			unsigned int nowip=0;
			for(auto x:s){
				if(x=='/')break; 
				if(x=='.'){
					nowip+=goNum(curS)*num[pointCnt-curpoint];
					curpoint++;
					curS="";
				}
				curS+=x;
			}//结束时还有最后一串数字没有处理 
			nowip+=goNum(curS);
			curip.front=nowip;
		}
		if(!iflen){//省略了前缀长度len
			curip.len=(pointCnt+1)*8;
		}
		else{//显示地声明了前缀长度 
			curip.len=goNum(curlen);
		}
		ivec.push_back(curip);
	}
//	sort(ivec.begin(),ivec.end(),cmp);//ip地址为第一关键字先排序 
//	sort(ivec.begin(),ivec.end(),cmp2);//前缀长度为第二关键字后排序 
	sort(ivec.begin(),ivec.end(),cmp3);//ip地址为第一关键字先排序 前缀长度为第二关键字后排序
}
