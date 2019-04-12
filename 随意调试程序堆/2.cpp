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
	return 0;
}
