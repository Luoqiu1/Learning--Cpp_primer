#include <bits/stdc++.h>
using namespace std;
int k=2;
constexpr int go(int i,int j)
{
	return i+j;
}
//extern int u=2;
struct text{	};
int main ()
{
	struct text as;
	int i=2;
	const int c=2,d=5;
	constexpr int a=go(c,d);
	constexpr int *p=&k;
	const int *q;
	q=&i;
//	*q=4;
	i=4;
	*p=6;
	int null=0;
	int *m=&null;
//	p=&i;
//	cout<<*q; 

	char *n=nullptr;
	if(!n)
	cout<<"3";//<<*n;
//	cout<<c<<*n<<'1';

	
//		int i=4,j=5;
		const int v=6; 
//		int change=2;
//		const int *p=&i;
//		int const *q=&j;
	//	constexpr int *r=&v;////编译出错是因为！在函数体内定义的变量的地址是变化的！constexpr的意思是
							////顶层指针！即指向的地址不变！ 而15行过了编译就是这回事！ 
//		*p=9;
//		p=&chang;
//		*q=9;
//		q=&chang;
//		*r=9;
//		r=&chang;
//	int null=0,*s=null; //错。。注意！C是强类型的！除了极个别的例子，指针中的两个外。。 
//	int &l=34;
	const int g=34;
	const int &o=g;
	int t=1;
	const int &u=t;
	{
		const int i=42;
		auto j=i;const auto &k=i;auto *p=&i;
		const auto j2=i,&k2=i;
		j=3;
	//	k=3;
	//	*p=2;
		const int y=22;
		p=&y;
	//	j2=3;
	//	k2=3;
	}//
//	extern int l=2; extern 声明 
	{
		unsigned as=0;
	 } 
	return 0;
}
