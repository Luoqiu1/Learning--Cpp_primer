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

int main (int argc,char *argv[])
{
	string ifile="ifile.txt";
	ifstream in(ifile);
	vector<string> v;
	read(in,v);
//	for(auto i:v)cout<<i<<endl;
	for(auto beg=end(v)-1,ed=begin(v)-1;beg!=ed;--beg){
		cout<<*beg<<endl;
	}
	return 0;
}
