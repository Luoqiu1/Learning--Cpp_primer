#include <vector>
#include <iostream>
using namespace std;
void func(const int i)
{
	return;
}
int Go(int,int);
int Go1(int a,int b)
{
	return a+b;
}
int Go2(int a,int b)
{
	return a-b;
}
int Go3(int a,int b)
{
	return a*b;
}
int Go4(int a,int b)
{
	return a/b;
}

int main ()
{
	void (*f)(int)=func;
	
	vector<int (*)(int,int)> x{Go1,Go2,Go3,Go4};
	vector<decltype(Go)*> xx{&Go1,&Go2,&Go3,&Go4};//列表初始化别忘了！ 
//	x.push_back(Go1);x.push_back(Go2);x.push_back(Go3);x.push_back(Go4);
	for(auto i:x){
	//	cout<<i(10,5)<<' ';
		cout<<(*i)(10,5)<<' ';
	}
	cout<<endl;
//	xx.push_back(Go1);xx.push_back(Go2);xx.push_back(Go3);xx.push_back(Go4);
	for(auto i:xx){
		cout<<i(10,5)<<' ';
	}
	return 0;
 } 
