#include <iostream>	
#include <string>
#include "Sales_data.h" 
#include "Sales_data.h"
#include "Sales_data.h"
#include "Sales_data.h"
#include "Person.h"
#include "Person.h"
using namespace std;
//struct Sales_data{
//	string bookNo;
//	unsigned cnt=0;
//	double units_sold=0.0;
//	double revenue=0.0;
//	string isbn() const{return bookNo;}
//	Sales_data& combine(const Sales_data &rhs)
//	{
//		//bookNo.units_sold+=rhs.units_sold;
//		//bookN0.revenue+=rhs.revenue;
//		//上面这两句有点没搞清楚对象。。点运算符作用于对象，而不是成员！
//		//而其实对象没有显式声明！要用对象的话要用隐式声明的*this!
//		//但其实在成员函数内部，可以直接使用调用该函数的对象的成员
//		//任何对类成员的直接访问都被看作this的隐式引用！
//	//	units_sold+=rhs.units_sold;
//	//	revenue+=rhs.revenue;
//		
//		//其实知道了this这个隐式声明的指针后，可以通过this来提升代码速度
//		//对this使用->会出来参数列表！直接选择，后面对应即可，不需要再翻上去了 
//		this->cnt+=rhs.cnt;
//		this->revenue+=rhs.revenue;
//		this->units_sold=revenue/cnt;
//		return *this;
//	}
//};
//istream& read(istream& in,Sales_data &s)
//{
//	in>>s.bookNo>>s.cnt>>s.units_sold;
//	s.revenue=s.cnt*s.units_sold; 
//	return in;
//}
//ostream& print(ostream& out,const Sales_data &s)
//{
//	out<<"书的编号为："<<s.bookNo<<"数量为："<<s.cnt<<"单价为："<<s.units_sold<<"总价为："<<s.revenue<<endl;
//	return out;
//}


//Sales_data& Sales_data::combine(const Sales_date &rhs)
//{
//	this->units_sold;
//	//在类外定义跟直接在类内定义差不多！
//	//除了加还有用到io库的两种情况不能直接在类内定义还不太清楚原因是什么。。 
//}

//将Sales_data封装入Sales_data.h类中！ 

void textf(std::istream);
int main (int argc,char **argv)
{
//	Sales_data total;
//	while(read(cin,total)){
//		Sales_data trans;
//		while(read(cin,trans)){
//			if(total.isbn()==trans.isbn()){
//				total.combine(trans);
//			}
//			else{
//				print(cout,total);
//				total=trans;
//			}
//		}
//		print(cout,total);
//	}
//	Sales_data total(cin);
//	if(cin){
//		Sales_data trans(cin);
//		do{
//			if(cin){
//				if(total.isbn()==trans.isbn()){
//					total.combine(trans);
//				}
//				else{
//					print(cout,total);
//					total=trans;
//				}
//			}
//		}while(read(cin,trans));
//		print(cout,total);
//	}

//	Sales_data s("Hello,World!",5,2);
//	Sales_data s("Hello,World!");

//	string ss="Hello,World!";
//	Sales_data s=ss;
	
//	Sales_data s;
//	print(cout,s);cout<<endl;
//	Sales_data s2;
//	print(cout,s2);cout<<endl;


//	Person person1;
//	Person person2("WQx");
//	Person person3("wqx","Hunan");
//	Person person4(cin);
//	print(cout,person1);cout<<endl;print(cout,person2);cout<<endl;
//	print(cout,person3);cout<<endl;
//	print(cout,person4);
//	Person person5;
//	read(cin,person5);print(cout,person5);cout<<endl;

	return 0;
}
