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
		auto old=is.rdstate();
		cout<<old<<' ';
		is.str(i);
		string s;
		while(is>>s){
			v2.push_back(s);
			++a;
		}	
	//	is.clear();//这行一定要注意！
		//要对流重置，不然直接结束循环。因为failbit被置位，随后的试图使用流的操作都会失败！ 
	//	is.setstate(old);//这个写法极易出错！要细微区分setstate和clear的含参重载版的差异！
						//setstate是置位！是叠加的（从二进制的角度去看）！
						//函数并不强制覆盖流的原状态，而是将括号内参数所代表的状态叠加到原始状态上 
						//clear的参数重载版本是复位！
						//将流状态设置成括号内参数所代表的状态，强制覆盖掉流的原状态 
	//	old=is.rdstate();cout<<old<<' ';
		//所以应该用clear！
		is.clear(old);
		//而其实不必麻烦设初始状态
		//因为初始状态是goodbit
		//直接is.clear()! 
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
