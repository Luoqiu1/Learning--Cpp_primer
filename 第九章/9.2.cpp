#include <vector>
#include <string> 
#include <iostream>
using namespace std;

int main ()
{
	vector<string> s1{"hi!","Hello!"},s2{"เห","นþยÞ"};
	for(const auto &i:s1)cout<<i<<' ';cout<<endl;
	for(const auto &i:s2)cout<<i<<' ';cout<<endl;
	swap(s2,s1);
	s1.swap(s2);
	for(const auto &i:s1)cout<<i<<' ';cout<<endl;
	for(const auto &i:s2)cout<<i<<' ';cout<<endl;
	return 0;
 } 
