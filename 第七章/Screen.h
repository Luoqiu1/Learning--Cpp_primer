#ifndef SCREEN
#define SCREEN
#include <string>
#include <iostream>
using namespace std;
class Screen{
	public:
		using pos=string::size_type;
		friend ostream &print(ostream &os,const Screen sg);
		const Screen &display(ostream &os) const {go_display(os);return *this;}
		Screen &display(ostream &os) {go_display(os);return *this;}
		Screen &move(pos r,pos c);
		Screen &set(char c)
		{
			contents[cursor]=c;
			return *this;
		}
		Screen &set(pos r,pos col,char c);
		Screen()=default;
		Screen(const pos &h,const pos &wd):width(wd),height(h),contents(wd*h,' '){}
		Screen(const pos &h,const pos &wd,char c):width(wd),height(h),contents(wd*h,c){}
		Screen(istream &is);
	private:
	//	void go_display(ostream &os) const;
	void go_display(ostream &os) const {os<<contents;};
		pos height=0,width=0;
		string contents;
		pos cursor=0;
};
//inline void Screen::go_display(ostream &os) const
//{
//	os<<contents;
//}
inline Screen &Screen::set(pos r,pos col,char c)
{
	contents[r*width+col]=c;
	return *this;
}
inline Screen &Screen::move(pos r,pos c)
{
	pos row=r*width;
	cursor=row+c;
	return *this;
}
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
	for(pos i=0;i<wd*h;++i)contents+=c;
}
#endif
