#include <iostream>
int main ()
{
	int a=5;
	int *p=&a;
	int &b=*p;
	b=3;
	printf("%d",a);
	return 0;
 } 
