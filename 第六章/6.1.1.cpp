#include <iostream>
using namespace std;

int Go(int i)
{
	static int cnt=i;
	cout<<" "<<cnt<<' ';
	return ++cnt;
}

int main ()
{
	int Cnt=0;
	Cnt=Go(5);for(int i=0;i<4;i++)Cnt=Go(123);
	cout<<Cnt<<endl;
	return 0;
 } 
