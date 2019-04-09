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
	
	const int k=5,&s=k;
//	s=4;
	const int *w;
	w=&c;
	std::cout<<*w<<std::endl;
//	*w=2;
	w=&b;
	std::cout<<*w<<std::endl;
//	int *const w;
	return 0;
 } 
