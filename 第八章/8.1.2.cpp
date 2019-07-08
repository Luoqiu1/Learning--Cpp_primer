#include <iostream>
using namespace std;

istream &fun(istream &is)
{
	do{
		string s;
		is>>s;
		if(!is.eof())cout<<s;
		else{
			is.clear();
			return is;
		}
	}while(1);
}

int main ()
{
	cin=fun(cin);
	if(cin.good())cout<<"good";
	else cout<<"bad";
	cout<<endl;
	return 0;
}
