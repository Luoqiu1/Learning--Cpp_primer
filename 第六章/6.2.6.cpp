#include <string>
#include <iostream>
#include <initializer_list>
void print(std::initializer_list<std::string> lt)
{
	for(auto beg=lt.begin();beg!=lt.end();++beg){
		std::cout<<*beg<<std::endl;
	}
}
int main (int argc,char **argv)
{
	std::string s1,s2;
	std::cin>>s1>>s2;
	size_t a=2;
	if(s1!=s2){
		print({"Yes,GO!",s1,s2});
	}
	else print({"yes,GO!",s1});
	return 0;
}
