#include <iostream>
#include <forward_list>
using namespace std;

int main ()
{
	forward_list<string> lst1{"hello"," !"," world."};
	for(auto i:lst1)cout<<i;cout<<endl;
	lst1.pop_front();//forward_list����pop_front���� 
//	lst1.pop_back(); forward_list����pop_back���� 
						//�������Ϊʲô��������ݽṹ��֪ʶ�� 
	for(auto i:lst1)cout<<i;cout<<endl;
	return 0;
}
