#include <bits/stdc++.h>
using namespace std;
struct text{
	int a;
}*tp,text;//ֱ����c++�������ԣ�����typedef��ʱ�����ֺ�ǰ���������ֱ�������� �ṹ�������
			//��������ͬcһ������typedef��ʱ���������� �ṹ�����ͣ� 
			//����tp��text���͵�ָ�롣��ǰ����typedef��tp����text*���͡� 
struct Sales_data{
	string bookNo;
	unsigned units_sold=0;
	double revenue=0.0;
};
int main ()
{
	int i;
//	tp d; tp�Ǳ���������������
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
