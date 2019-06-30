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
		//�����������е�û��������󡣡�������������ڶ��󣬶����ǳ�Ա��
		//����ʵ����û����ʽ������Ҫ�ö���Ļ�Ҫ����ʽ������*this!
		//����ʵ�ڳ�Ա�����ڲ�������ֱ��ʹ�õ��øú����Ķ���ĳ�Ա
		//�κζ����Ա��ֱ�ӷ��ʶ�������this����ʽ���ã�
	//	units_sold+=rhs.units_sold;
	//	revenue+=rhs.revenue;
		
		//��ʵ֪����this�����ʽ������ָ��󣬿���ͨ��this�����������ٶ�
		//��thisʹ��->����������б�ֱ��ѡ�񣬺����Ӧ���ɣ�����Ҫ�ٷ���ȥ�� 
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
	out<<"��ı��Ϊ��"<<s.bookNo<<"����Ϊ��"<<s.cnt<<"����Ϊ��"<<s.units_sold<<"�ܼ�Ϊ��"<<s.revenue<<endl;
	return out;
}
#endif
