#include "f.h"
#include <bits/stdc++.h>
int f(int *a,int *b){
	int mid=*a;
	*a=*b;
	*b=mid;
}
int ff(int &i)
{
	i=2;
	return 0;
}
int main ()
{
	int a=2;
	ff(a);
	printf("%d",a);
	return 0;
 } 
