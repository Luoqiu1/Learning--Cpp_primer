#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>
#include <string>
using namespace std;
struct Sales_data{
	string bookNo;
	unsigned cnt=0;
	double units_sold=0.0;
	double revenue=0.0;
	string isbn() const{return bookNo;}
	Sales_data& combine(const Sales_data &rhs)
	{
		//bookNo.units_sold+=rhs.units_sold;
		//bookN0.revenue+=rhs.revenue;
		//上面这两句有点没搞清楚对象。。点运算符作用于对象，而不是成员！
		//而其实对象没有显式声明！要用对象的话要用隐式声明的*this!
		//但其实在成员函数内部，可以直接使用调用该函数的对象的成员
		//任何对类成员的直接访问都被看作this的隐式引用！
	//	units_sold+=rhs.units_sold;
	//	revenue+=rhs.revenue;
		
		//其实知道了this这个隐式声明的指针后，可以通过this来提升代码速度
		//对this使用->会出来参数列表！直接选择，后面对应即可，不需要再翻上去了 
		this->cnt+=rhs.cnt;
		this->revenue+=rhs.revenue;
		this->units_sold=revenue/cnt;
		return *this;
	}
};
istream& read(istream& in,Sales_data &s)
{
	in>>s.bookNo>>s.cnt>>s.units_sold;
	s.revenue=s.cnt*s.units_sold; 
	return in;
}
ostream& print(ostream& out,const Sales_data &s)
{
	out<<"书的编号为："<<s.bookNo<<"数量为："<<s.cnt<<"单价为："<<s.units_sold<<"总价为："<<s.revenue<<endl;
	return out;
}
#endif
