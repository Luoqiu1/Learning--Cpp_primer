#ifndef SCREEN
#define SCREEN
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class Screen;
//using ScreenIndex=vector<Screen>::size_type;//using跟typedef功能类似，对不完全类型也一样。 
	//这条语句应该定义在Window_mgr类内！ 
class Window_mgr{
	public:
		using ScreenIndex=vector<Screen>::size_type;
		inline void clear(ScreenIndex);
	private:
	//	vector<Screen> Screens{Screen(24,80,' ')};
		vector<Screen> screens;//Screen不完全类型,这里还没有为screens分配空间！ 
			//在C/C++，不完全类型的表现形式有这几种 void、未指定长度的数组 以及 具有非指定内容的结构和联合。
			//int c[];
			//class a;
			//union b; 这三种均为不完全类型！
		//在使用该类型或定义该类型的对象，一定确保该类型已经被定义过了！
		//如 a text_a1;是非法的！编译器不知道为text_a1分配多大的空间！ 
};

class Screen{
	public:
		using pos=string::size_type;
		friend void Window_mgr::clear(ScreenIndex); 
		friend ostream &print(ostream &os,const Screen sg);
		const Screen &display(ostream &os) const {go_display(os);return *this;}
		Screen &display(ostream &os) {go_display(os);return *this;}
		Screen &move(pos r,pos c);
		
	//	Status text(int a) {return 1;} 
	//	using Status=int;	该条语句应放在33行是合法的 
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
inline void Window_mgr::clear(ScreenIndex i)
{
	Screen &s=screens[i];
	s.contents=string(s.height*s.width,' ');
}
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
