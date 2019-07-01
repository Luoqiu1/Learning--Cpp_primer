#ifndef SALES_DATA
#define SALES_DATA
#include <iostream>
#include <string>
using namespace std;
struct Sales_data{
	public:
	friend istream &read(istream &is,Sales_data &item);
	friend ostream &print(ostream &os,const Sales_data &item);
	friend Sales_data add(const Sales_data &lhs,const Sales_data &rhs);
	Sales_data()=default;//深刻理解构造函数！实质是函数！这三个同名的就是构造函数的重载！
						//所以这条语句是一定要的（当有至少一个构造函数的时候，合成的默认构造函数不会被编译器定义！)
						//因为如果没有这条语句，就连定义一个Sales_data类型的变量都成了非法的行为！
						//因为没有提供不含参数的构造函数！（当没有显示定义函数的时候，编译器会自动定义合成的默认构造函数！)
						//构造函数也是函数，用函数的方法来看待！
						//形参数量，形参类型等！ 
//	Sales_data():bookNo("00001"),cnt(1),units_sold(0),revenue(0){}
	Sales_data(const string &s):bookNo(s){}
	Sales_data(const string &s,const unsigned &cntt,const double &units_soldd):bookNo(s),cnt(cntt),
units_sold(units_soldd),revenue(cntt*units_soldd){}
//	Sales_data(istream &is); 
	Sales_data(istream &is)
	{
		is>>bookNo>>cnt>>units_sold;
		revenue=cnt*units_sold;
	}
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
	
	private:
	inline double avg_price()const
	{
		return cnt?revenue/cnt:0;
	}
	string bookNo;
	unsigned cnt=0;
	double units_sold=0.0;//我理解成了单价。。按这个来吧 
	double revenue=0.0;
	
};
istream &read(istream &is,Sales_data &item)
{
	is>>item.bookNo>>item.cnt>>item.units_sold;
	item.revenue=item.cnt*item.units_sold; 
	return is;
}
ostream &print(ostream &os,const Sales_data &item)
{
	os<<"书的编号为："<<item.bookNo<<"数量为："<<item.cnt<<"单价为："<<item.units_sold<<"总价为："<<item.revenue;
	return os;
}
//Sales_data::Sales_data(istream &is)
//{
//	read(is,*this);
//}
Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{						//lhs=left hand side;左操作数 
						//rhs=right hand side;右操作数 
//	return lhs.combine(rhs);
	//这条语句有问题！combine函数会改变改用该成员函数的对象！
	
	Sales_data sum=lhs;
	return sum.combine(rhs); 
} 
#endif
