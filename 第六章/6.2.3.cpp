#include <iostream>
#include <string>
using Status=int;
Status isupperS(const std::string &s)
{
	for(auto i:s){
	//	if(i==toupper(i))
		if(isupper(i))
			return 1;
	}
	return 0;
}

int main ()
{
	std::string s;
	std::cin>>s;
	if(isupperS(s))
		std::cout<<"Yes";
	else std::cout<<"No";
	return 0;
}
