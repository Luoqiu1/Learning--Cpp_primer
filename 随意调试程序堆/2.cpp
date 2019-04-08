#include <bits/stdc++.h>
using namespace std;

int main ()
{
	int *p=(int*)malloc(5*sizeof(int));
	for(int i=0;i<5;i++){
		printf("%p\n",p[i]);
	}
	return 0;
}
