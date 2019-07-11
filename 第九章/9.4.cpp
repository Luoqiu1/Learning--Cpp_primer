#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main ()
{
	string v;
	for(int i=0;i<1000;++i){
		auto tmp1=v.capacity();
		v.push_back(i);
		auto tmp2=v.capacity();
		if(tmp1!=tmp2)cout<<"here i="<<i<<",changes="<<tmp2-tmp1<<endl;
	}
	return 0;
 } 
