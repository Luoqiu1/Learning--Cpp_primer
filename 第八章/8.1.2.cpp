#include <iostream>
using namespace std;

istream &fun(istream &is)
{
	do{
		string s;
		is>>s;
		if(!is.eof())cout<<s<<endl;
		else{
			is.clear();
			return is;
		}
	}while(1);
}

int main ()
{
	fun(cin);
	string ss;
	decltype(ss) s=ss;
	if(cin.good())cout<<"good123";
	else cout<<"bad";
	cout<<endl;
	return 0;
}
