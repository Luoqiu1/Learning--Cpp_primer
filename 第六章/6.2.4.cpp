#include <iostream>

int compareInt(int a,int *p)
{
	if(a>*p)return a;
	return *p;
}
void exchangePoint(int **p,int **q)
{
	int *mid=*p;
	*p=*q;
	*q=mid;
}

int main ()
{
	int a,b,*p=&b;
	std::cin>>a>>b;
	int ans=compareInt(a,p);
	std::cout<<ans<<std::endl;
	int *q=&a;
	std::cout<<"*p="<<*p<<" *q="<<*q<<std::endl;
	exchangePoint(&p,&q);
	std::cout<<"*p="<<*p<<" *q="<<*q<<std::endl;
	return 0;
}
