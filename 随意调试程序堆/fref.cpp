#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
const int Max=1e6+10;
struct node2{
	int ip[5];
	long long IP;
	int len;
};
vector<node2> p;
int Input(int n){//输入 
	string s;
	for(int i=0;i<n;i++){
		cin>>s;
		int l=0;
		node2 a={0};
		for(int j=0;j<s.size();j++){
			if(s[j]>='0'&&s[j]<='9')
			a.ip[l]=a.ip[l]*10+s[j]-'0';
			else if(s[j]=='/') l=4;
			else l++;
		}
		if(a.ip[4]==0) a.ip[4]=(l+1)*8;
		a.len=a.ip[4];
		a.IP=0;
		long long k=1;
		for(int j=3;j>=0;j--){
			a.IP+=(a.ip[j]*k);
			k*=256;
		}
		p.push_back(a);
	}
	return 1;
}
bool cmp(node2 a,node2 b){
	if(a.IP==b.IP)
	return a.len<b.len;
	return a.IP<b.IP;
}
int second(){//第二步
	int l=0;
	for(int i=1;i<p.size();i++){
		if(((p[l].IP>>(32-p[l].len))==(p[i].IP>>(32-p[l].len))&&p[i].len>p[l].len)||(p[i].IP==p[l].IP&&p[i].len==p[l].len)){
			p.erase(p.begin()+i);
			i--;
		}else l=i;
	}
//	cout<<"sizeof now "<<p.size()<<endl;
	return 1;
}
int third(){
	int l=0;
	while(l<p.size()){
		node2 b;
		if(l-1>=0&&((p[l-1].IP>>(32-p[l-1].len))&1)==0){
			b=p[l-1];
			b.len--;
			if((p[l].IP>>(32-b.len))==(p[l-1].IP>>(32-b.len))&&p[l].len==p[l-1].len){
				p[l-1]=b;
				p.erase(p.begin()+l);
				l--;
			}
			else l++;
		}
		else if(l+1<p.size()&&((p[l].IP>>(32-p[l].len))&1)==0){
			b=p[l];
			b.len--;
			if((p[l].IP>>(32-b.len))==(p[l+1].IP>>(32-b.len))&&p[l].len==p[l+1].len){
				p[l]=b;
				p.erase(p.begin()+l+1);
			}
			else l++;
		}
		else l++;
	}
	return 1;
}
void Print(){
	for(int i=0;i<p.size();i++){
		printf("%d.%d.%d.%d/%d\n",p[i].ip[0],p[i].ip[1],p[i].ip[2],p[i].ip[3],p[i].len);
	}
}
int main()
{
	int n;
	cin>>n;
	Input(n);
	sort(p.begin(),p.end(),cmp);
	second();
	third();
	Print();
}
