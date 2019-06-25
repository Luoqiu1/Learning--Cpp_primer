#include <iostream>
#include <string>
int main (int argc,char **argv)
{
	std::string s;
	for(decltype(s.size()) i=1;i!=argc;++i){//注意是从argc[1]开始，argc[0]是用来保存程序的名字 
		s+=argv[i]+' ';
	}
	std::cout<<s<<std::endl;
	return 0;
}
