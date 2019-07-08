#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

istream &read(istream &is,vector<string> &v)
{
	string s;
	while(getline(is,s)){
		v.push_back(s);
	}
	return is;
}

void fun(vector<string> &v)
{
	for(auto i:v)cout<<i<<endl;
	cout<<endl;
	for(auto beg=end(v)-1,ed=begin(v)-1;beg!=ed;--beg){
		cout<<*beg<<endl;
	}
}

ostream &print(ostream &os,istream &is)
{
	string s;
	os<<endl;
	while(getline(is,s)){
		os<<s<<endl;
	}
	return os;
}

int main (int argc,char *argv[])
{
	string ifile="ifile",ed=".txt";
	ifstream in(ifile+ed);
	vector<string> v,v2,v3;
	if(in){
		read(in,v);
	}
	in.close();
	fun(v);
	cout<<endl;
	in.open(ifile+"2"+ed);
	if(in){
		read(in,v2);
	}
	in.close();
	fun(v2);
	cout<<endl<<endl<<endl<<endl<<endl;
	
	in.open(ifile+ed);
	ofstream out(ifile+"2"+ed,ofstream::app);
	if(in&&out){
		print(out,in);
	}
	out.close();
	in.close();
	in.open(ifile+"2"+ed);
	if(in){
		read(in,v3);
	}
	in.close();
	fun(v3);
	return 0;
}
