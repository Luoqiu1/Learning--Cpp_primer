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
	return 0;
 } 
