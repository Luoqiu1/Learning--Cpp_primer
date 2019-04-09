#include <iostream>
int main ()
{
	int a=4;
	int *const p=&a;
	int b=2;
//	p=&b;
	std::cout<<*p<<std::endl;
	a=5;
	std::cout<<*p<<std::endl;
	
	const int *q=&a;
	q=&b;
	std::cout<<*q<<std::endl;
	b=4;
	std::cout<<*q<<std::endl;
	
	int c=5;
	const int d=6;
	int *const m=&c;
	
	const int *const n=&c;
	c=2;
	std::cout<<*n<<std::endl;
	c=7;
	std::cout<<*n<<std::endl;
	
	const int k=5,*s=&k;
//	s=4;
	const int *w;
	w=&c;
	std::cout<<*w<<std::endl;
//	*w=2;
	w=&b;
	std::cout<<*w<<std::endl;
//	int *const w;
	w=s;
	std::cout<<*w<<std::endl;
	
	const int *p1;
	const int ic=4;
	p1=&ic;
	std::cout<<*p1<<*p1<<std::endl;
	
	int i=0;
	const int *p2=&i;
	i=5;
	std::cout<<*p2<<*p2<<std::endl;
	return 0;
 } 
