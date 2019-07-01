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
	Sales_data()=default;//�����⹹�캯����ʵ���Ǻ�����������ͬ���ľ��ǹ��캯�������أ�
						//�������������һ��Ҫ�ģ���������һ�����캯����ʱ�򣬺ϳɵ�Ĭ�Ϲ��캯�����ᱻ���������壡)
						//��Ϊ���û��������䣬��������һ��Sales_data���͵ı��������˷Ƿ�����Ϊ��
						//��Ϊû���ṩ���������Ĺ��캯��������û����ʾ���庯����ʱ�򣬱��������Զ�����ϳɵ�Ĭ�Ϲ��캯����)
						//���캯��Ҳ�Ǻ������ú����ķ�����������
						//�β��������β����͵ȣ� 
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
	
	private:
	inline double avg_price()const
	{
		return cnt?revenue/cnt:0;
	}
	string bookNo;
	unsigned cnt=0;
	double units_sold=0.0;//�������˵��ۡ������������ 
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
	os<<"��ı��Ϊ��"<<item.bookNo<<"����Ϊ��"<<item.cnt<<"����Ϊ��"<<item.units_sold<<"�ܼ�Ϊ��"<<item.revenue;
	return os;
}
//Sales_data::Sales_data(istream &is)
//{
//	read(is,*this);
//}
Sales_data add(const Sales_data &lhs,const Sales_data &rhs)
{						//lhs=left hand side;������� 
						//rhs=right hand side;�Ҳ����� 
//	return lhs.combine(rhs);
	//������������⣡combine������ı���øó�Ա�����Ķ���
	
	Sales_data sum=lhs;
	return sum.combine(rhs); 
} 
#endif
