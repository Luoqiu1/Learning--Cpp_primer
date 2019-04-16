#include <bits/stdc++.h>
using namespace std;
int k=2;
constexpr int go(int i,int j)
{
	return i+j;
}


int main ()
{
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
	int null=0,*s=null; //错。。注意！C是强类型的！除了极个别的例子，指针中的两个外。。 
	return 0;
}
