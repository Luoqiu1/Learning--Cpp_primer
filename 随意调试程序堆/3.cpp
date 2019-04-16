#include <bits/stdc++.h>
using namespace std;
struct text{
	int a;
}*tp,text;//直接用c++的新特性，不加typedef的时候，最后分号前面的名字是直接声明了 结构体变量！
			//而不是如同c一样，加typedef的时候声明的是 结构体类型！ 
			//这里tp是text类型的指针。若前面有typedef，tp则是text*类型。 
struct Sales_data{
	string bookNo;
	unsigned units_sold=0;
	double revenue=0.0;
};
int main ()
{
	int i;
//	tp d; tp是变量名而不是类型
	Sales_data data1,data2,data;
	cin>>data1.bookNo>>data1.units_sold>>data1.revenue;
	cin>>data2.bookNo>>data2.units_sold>>data2.revenue;
	if(data1.bookNo==data2.bookNo){
		data.bookNo=data1.bookNo;
		data.units_sold=data1.units_sold+data2.units_sold;
		data.revenue=data1.units_sold*data1.revenue+data2.units_sold*data2.revenue;
		cout<<data.bookNo<<' '<<data.units_sold<<' '<<data.revenue;
	}
	else cout<<"Error!";
	return 0;
 }
