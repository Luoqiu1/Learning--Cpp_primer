#include <iostream>
#include <sstream>
using namespace std;

istream &fun(istream &is)
{
	do{
		string s;
		is>>s;
		if(!is.eof())cout<<s<<endl;
		else{	
			is.clear();
			cout<<s;
			return is;
		}
	}while(1);
//	string s;
//	while(is>>s){
//		cout<<s<<endl; 
//	}
//	return is;
}

int main ()
{
	string ss("a b c dhello");
	istringstream iss(ss);
	fun(iss);
//	if(cin.good())cout<<"good123";
//	else cout<<"bad";
	cout<<endl;
	return 0;
}
