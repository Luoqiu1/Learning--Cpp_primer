#ifndef SCREEN
#define SCREEN
#include <string>
#include <iostream>
using namespace std;
class Screen{
	public:
		using pos=string::size_type;
		friend ostream &print(ostream &os,const Screen sg);
		Screen()=default;
		Screen(const int &wd,const int &h):width(wd),height(h),contents(wd*h,' '){}
		Screen(const int &wd,const int &h,char c):width(wd),height(h),contents(wd*h,c){}
		Screen(istream &is);
	private:
		pos height=0,width=0;
		string contents;
		pos cursor=0;
};
ostream &print(ostream &os,const Screen sg)
{
	os<<sg.contents;
	return os;
}
Screen::Screen(istream &is)
{
//	is>>this->width>>this->height;
//	char c;is>>c;
//	contents(width*height,c);		//当我们提供一个类内初始值时，必须以符号=或者花括号{}来表示！

	pos wd,h;char c;is>>wd>>h>>c;
	for(int i=0;i<wd*h;++i)contents+=c;
}
#endif
