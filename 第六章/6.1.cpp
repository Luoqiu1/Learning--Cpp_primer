#include <iostream>
using namespace std;

long long fact(int x)
{
	long long ans=1;
	for(int i=1;i<=x;i++)ans*=i;
	return ans;
}
int juedui(int x)//return x;
{
	if(x<0)return -x;
	return x;
}
int zeng()
{
	static int x=-1;
	return ++x;
}
int main ()
{
	
//	int x;cin>>x;
//	cout<<fact(x)<<endl;
//	cout<<juedui(x)<<endl;

	for(int i=1;i<=10;i++)cout<<zeng()<<' ';
	return 0;
}
