#include <iostream>
#include <forward_list>
#include <vector>
using namespace std;

int main ()
{
	forward_list<string> lst1{"hello"," !"," world."};
	for(auto i:lst1)cout<<i;cout<<endl;
	lst1.pop_front();//forward_list����pop_front���� 
//	lst1.pop_back(); forward_list����pop_back���� 
						//�������Ϊʲô��������ݽṹ��֪ʶ�� 
	for(auto i:lst1)cout<<i;cout<<endl;
	
	vector<int> v1{1,2,3,4,5};
	vector<int>::iterator it1=v1.begin()+1;
	vector<int>::iterator it2=v1.begin()+2;
	cout<<endl<<*it1<<endl;
	cout<<endl<<*it2<<endl;
	cout<<endl<<*(v1.end()-1)<<endl;
	v1.erase(v1.begin()+2,v1.end()-1);
	for(auto i:v1)cout<<i<<' ';
	cout<<endl;
	cout<<*it1<<endl;
	cout<<*it2<<endl;
	return 0;
}
