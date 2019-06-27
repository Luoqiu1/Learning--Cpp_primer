#include <iostream>
#include <string >
using namespace std;

const string &shorterString(const string &s1,const string &s2)
{
	return s1.size()<s2.size()?s1:s2;
}
string &shorterString(string &s1,string &s2)
{
	
	auto &r=shorterString(const_cast<const string&>(s1),const_cast<const string&>(s2));
	return const_cast<string&>(r);
}

int main ()
{
	string s1,s2;
	const string s3{"s3o``"},s4{"s4o"};
	cin>>s1>>s2;
	const string cs=shorterString(s3,s4);string ncs=shorterString(s1,s2);
	cout<<cs<<endl<<ncs;
	return 0;
}
