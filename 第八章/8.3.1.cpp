#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void fun1(istream &is,vector<string> &v)
{
	string s;
	while(getline(is,s)){
		v.push_back(s);
	}
}

void fun2(istringstream &is,const vector<string> &v1,vector<string> &v2)
{
	int a=0;
	for(auto i:v1){
		is.str(i);
		string s;
		while(is>>s){
			v2.push_back(s);
			++a;
		}
		is.clear();//这行一定要注意！
		//要对流重置，不然直接结束循环。因为failbit被置位，随后的试图使用流的操作都会失败！ 
	}
	cout<<endl<<a<<endl;
}

int main ()
{
	ifstream ifs("ifile.txt");
	if(ifs){
		istringstream iss;
		vector<string> v1;
		fun1(ifs,v1);
		for(auto i:v1)cout<<i<<endl;
		cout<<endl;
		vector<string> v2;
		fun2(iss,v1,v2);
		for(auto i:v2)cout<<i<<endl;
	}
	return 0;
}
