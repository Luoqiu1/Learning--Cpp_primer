#include <iostream>
#include <forward_list>
using namespace std;

int main ()
{
	forward_list<string> lst1{"hello"," !"," world."};
	for(auto i:lst1)cout<<i;cout<<endl;
	lst1.pop_front();//forward_list中有pop_front函数 
//	lst1.pop_back(); forward_list中无pop_back函数 
						//不难理解为什么！结合数据结构的知识。 
	for(auto i:lst1)cout<<i;cout<<endl;
	return 0;
}
