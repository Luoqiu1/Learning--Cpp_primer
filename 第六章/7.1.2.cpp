#include <iostream>	
#include <string>
using namespace std;
struct Sales_data{
	string bookNo;
	unsigned units_sold=0;
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
		this->units_sold+=rhs.units_sold;
		this->revenue+=rhs.revenue;
		
		return *this;
	}

};
//Sales_data& Sales_data::combine(const Sales_date &rhs)
//{
//	this->units_sold;
//	//在类外定义跟直接在类内定义差不多！
//	//除了加还有用到io库的两种情况不能直接在类内定义还不太清楚原因是什么。。 
//}

void textf(std::istream);
int main (int argc,char **argv)
{
	return 0;
}
