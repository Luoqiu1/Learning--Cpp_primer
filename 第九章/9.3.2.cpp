#include <iostream>
#include <vector>
using namespace std;

int main ()
{
	vector<int> v1;
	int a;
	while(cin>>a){
		v1.emplace_back(a);
	}
	auto sz=v1.size()+5;
	for(int i=0;i<sz;++i)cout<<v1.at(i)<<' ';
	cout<<endl;
	return 0;
}
