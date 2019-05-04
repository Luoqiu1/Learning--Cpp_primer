#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef struct ip{
	unsigned int front;//ip��ַ 
	unsigned int len;//ǰ׺
	//���� 101.6.6.0/24    ip��ַΪ101.6.6.0����Ӧ��ʮ������
	//                     ǰ׺Ϊ 24  
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
		bool iflen=false;//�ж��Ƿ���ʾ��������ǰ׺len
		string curlen;
		string curS;//ÿһ��point('.')ǰ����ʾ�ĵ��ʮ���������ַ�����ʽ 
		for(auto x:s){
			curS+=x;
			if(iflen)curlen+=x;
			if(x=='.')++pointCnt;
			if(x=='/')iflen=true;
		}
		if(!pointCnt&&!iflen){//û��'.'Ҳû��ǰ׺len
			curip.front=goNum(curS);//ֱ��ת�� 
		}
		else if(!pointCnt&&iflen){//û��'.'����ǰ׺len 
			string curS;
			for(auto x:s){
				if(x=='/')break;
				curS+=x;
			}
			curip.front=goNum(curS);//ֱ��ת��
		}
		else if(pointCnt&&!iflen){//��'.'û��ǰ׺
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
			}//����ʱ�������һ������û�д��� 
			nowip+=goNum(curS);
			curip.front=nowip;
		}
		else if(pointCnt&&iflen){//��'.'��ǰ׺
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
			}//����ʱ�������һ������û�д��� 
			nowip+=goNum(curS);
			curip.front=nowip;
		}
		if(!iflen){//ʡ����ǰ׺����len
			curip.len=(pointCnt+1)*8;
		}
		else{//��ʾ��������ǰ׺���� 
			curip.len=goNum(curlen);
		}
		ivec.push_back(curip);
	}
//	sort(ivec.begin(),ivec.end(),cmp);//ip��ַΪ��һ�ؼ��������� 
//	sort(ivec.begin(),ivec.end(),cmp2);//ǰ׺����Ϊ�ڶ��ؼ��ֺ����� 
	sort(ivec.begin(),ivec.end(),cmp3);//ip��ַΪ��һ�ؼ��������� ǰ׺����Ϊ�ڶ��ؼ��ֺ�����
}
