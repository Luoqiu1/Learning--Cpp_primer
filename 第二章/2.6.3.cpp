#include <iostream>
#include "Sales_data.h"
#include <string>//��׼�⺯���϶��뵽������Ķ�������Ȼ����ͷ�ļ��������� 
int main()
{
	Sales_data data1,data2,data;
	std::cin>>data1.bookNo>>data1.units_sold>>data1.revenue;
	std::cin>>data2.bookNo>>data2.units_sold>>data2.revenue;
	if(data1.bookNo==data2.bookNo){
		data.bookNo=data1.bookNo;
		data.units_sold=data1.units_sold+data2.units_sold;
		data.revenue=data1.units_sold*data1.revenue+data2.units_sold*data2.revenue;
		std::cout<<data.bookNo<<' '<<data.units_sold<<' '<<data.revenue;
	}
	else std::cout<<"Error!";
}
