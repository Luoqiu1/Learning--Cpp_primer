#include <string>
#include <iostream>
#include <vector>
//#define NDEBUG
using namespace std;
bool str_subrange(const string &str1,const string &str2)
{
	if(str1.size()==str2.size())
		return str1==str2;
	auto size=(str1.size()<str2.size())?str1.size():str2.size();
	for(decltype(size) i=0;i!=size;++i){
		if(str1[i]!=str2[i])
			return 0;
	}
}
int &get(int *arry,int index)
{
	return arry[index];
}
void print(vector<int>::const_iterator beg,vector<int>::const_iterator end)
//void print(vector<string>::const_iterator beg,vector<string>::const_iterator end)
{
	if(beg!=end){
		cout<<*beg;
		#ifndef NDEBUG
		cout<<" This strings' size are "<<sizeof(*beg)<<endl;
		#endif
		print(++beg,end);
	}
}
int main (int argc,char **argv)//(int argc,char *argv[]) 
{
	int ia[10];
	for(int i=0;i!=10;++i)get(ia,i)=i;
	for(auto i:ia)cout<<i<<' ';cout<<endl;
	cout<<endl;
	vector<int> v1{5,7,3,1,3,9,2,1,5};
//	vector<string> v1{"Hello!","World.","Hi!!!!","Hahahaha"};
	print(v1.cbegin(),v1.cend());cout<<endl;
	return 0;
}
