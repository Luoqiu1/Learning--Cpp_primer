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

Status golowerS(std::string &s)
{
	for(auto &i:s){
		i=tolower(i);
	}
	return 0;
}

int main ()
{
	std::string s;
	std::cin>>s;
	if(isupperS(s))
		std::cout<<"Yes"<<std::endl;
	else std::cout<<"No"<<std::endl;
	golowerS(s);
	std::cout<<s<<std::endl;
	return 0;
	
	//	bool compare(std::matrix &p,std::matrix &q);
	//	std::vector<int>::iterator change_val(int a,std::vector<int>::iterator p);
	
	
}
