#include <iostream>
#include <string>
#include <vector>
#include <iterator>
#include <cstring>
using namespace std;
int main ()
{
//	string sa2[10];
//	const size_t a=23;
//	int ia2[a];
//	for(auto x:ia2)cout<<x<<' ';
//	int i=-1;
//	vector<int> ivec;
//	while(++i<10){
//		ivec.push_back(i);
//	}
//	for(auto x:ivec)cout<<x;
//	int a[8];
//	for(auto &i:a)i=2;
//	for(auto i:a)cout<<i<<' ';
//	auto pbeg=begin(a),pend=end(a);
//	while(pbeg!=pend){
//		*pbeg=0;pbeg++;
//	}
//	for(auto i:a)cout<<i<<' ';

//	int a[5]={2,3,4,5},b[5]={2,3,4,5};
//	auto abeg=begin(a),aend=end(a);
//	auto bbeg=begin(b),bend=end(b);
//	bool flag=true;
//	if(abeg-aend!=bbeg-bend)flag=!flag;
//	else while(abeg!=aend&&bbeg!=bend){
//		if(*abeg!=*bbeg){
//			flag=!flag;break;
//		}
//		++abeg;++bbeg;
//	}
//	if(flag)cout<<"Yes";else cout<<"No";
	
//	vector<int> avec;
//	avec[2]=2;avec[1]=1;avec[0]=0;cout<<avec[2];
//	for(int i=0;i<3;i++)cout<<avec[i]<<' ';
//	cout<<endl<<avec.cend()-avec.cbegin();
//	avec={1,2,3,4,5};avec={1};avec[77]=92123;cout<<avec[77];

//	for(auto i:avec)cout<<i<<' ';cout<<endl;
//	avec={3,3,1,4};
//	vector<int> bvec{3,3,1,4};
//	if(avec==bvec)cout<<"Yes";else cout<<"No";

//	string s1{"nihao"};
//	s1="ooo";s1[2]='a';
//	cout<<s1;
//	char ca[]={'2','+','1'};
//	for(auto i:ca)cout<<i;
//	cout<<strlen(ca);
//	int a[2]={1,2};
//	*a=0;
//	int i[2];
//	a=i;// a=&a[0];

//	const char ca[5]={'h','e','l','l','o'},cb[5]={'h','e','l','l','o'},cc[5]={'h','e','l','l','o'};
//	const char *cp=ca;
//	cout<<sizeof(ca)<<endl;
//	printf("ca:%p cb:%p cb:%p ",&ca,&cb,&cc);
//	if(ca[5]=='\0')cout<<"yes"<<endl;
//	while(*cp){
//		cout<<*cp<<endl;
//		++cp;
//	}
	
//	char s1[]{"nihao"},s2[]{"ganma"};
//	cout<<(s1>s2);
//	char s11[]{"ganma"},s22[]{"nihao"};
//	cout<<strcmp(s11,s22);
//	char s3[30];
//	strcpy(s3,s1);strcat(s3,s2);
//	strcat(s3,s1);strcat(s3,s2);
//	cout<<s3;

//	int a[13]{1,2,3,5,7,8,123,321};
//	vector<int> ivec(begin(a),end(a));
//	for(auto i:ivec)cout<<i<<' ';
//	int i=0;
//	int b[13]{0};
//	for(auto x:ivec)b[i++]=x;cout<<endl;
//	for(auto i:b)cout<<i<<' ';
	
	int ia[3][4]={0,1,2,3,4,5,6,7,8,9,10,11};
//	for(int (&i)[4]:ia)for(int x:i)cout<<x<<' ';cout<<endl;
//	for(int i=0;i<3;i++)for(int j=0;j<4;j++)cout<<ia[i][j]<<' ';cout<<endl;
//	for(int (*p)[4]=ia;p<ia+3;p++)for(int *q=*p;q<*p+4;q++)cout<<*q<<' ';cout<<endl;
////	for(int p[4]=ia;p!=end(ia);p++)for(int q=*p;q!=end(*p);q++)cout<<*q<<' ';cout<<endl;
//	for(int (*p)[4]=ia;p!=end(ia);p++)for(int *q=*p;q!=end(*p);q++)cout<<*q<<' ';cout<<endl;

//	int (*p)[4]=(ia+2);cout<<*(*p+3);
	for(int (&a)[4]:ia)for(int p:a)cout<<p<<' ';cout<<endl;
	for(int i=0;i<3;i++)for(int j=0;j<4;j++)cout<<ia[i][j]<<' ';cout<<endl;
	for(int (*p)[4]=ia;p<ia+3;p++)for(int *q=*p;q<*p+4;q++)cout<<*q<<' ';cout<<endl; 
	
	return 0;
}
