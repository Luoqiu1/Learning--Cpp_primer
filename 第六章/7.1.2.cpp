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
		//�����������е�û��������󡣡�������������ڶ��󣬶����ǳ�Ա��
		//����ʵ����û����ʽ������Ҫ�ö���Ļ�Ҫ����ʽ������*this!
		//����ʵ�ڳ�Ա�����ڲ�������ֱ��ʹ�õ��øú����Ķ���ĳ�Ա
		//�κζ����Ա��ֱ�ӷ��ʶ�������this����ʽ���ã�
	//	units_sold+=rhs.units_sold;
	//	revenue+=rhs.revenue;
		
		//��ʵ֪����this�����ʽ������ָ��󣬿���ͨ��this�����������ٶ�
		//��thisʹ��->����������б�ֱ��ѡ�񣬺����Ӧ���ɣ�����Ҫ�ٷ���ȥ�� 
		this->units_sold+=rhs.units_sold;
		this->revenue+=rhs.revenue;
		
		return *this;
	}

};
//Sales_data& Sales_data::combine(const Sales_date &rhs)
//{
//	this->units_sold;
//	//�����ⶨ���ֱ�������ڶ����࣡
//	//���˼ӻ����õ�io��������������ֱ�������ڶ��廹��̫���ԭ����ʲô���� 
//}

void textf(std::istream);
int main (int argc,char **argv)
{
	return 0;
}
