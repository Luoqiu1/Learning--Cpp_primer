#include <iostream>
#include "Sales_data.h"
#include <string>//��׼�⺯���϶��뵽������Ķ�������Ȼ����ͷ�ļ��������� 
using namespace std;
#include <stdexcept>
int main()
{
//	Sales_data data1,data2,data;
//	std::cin>>data1.bookNo>>data1.units_sold>>data1.revenue;
//	std::cin>>data2.bookNo>>data2.units_sold>>data2.revenue;
//	if(data1.bookNo==data2.bookNo){
//		data.bookNo=data1.bookNo;
//		data.units_sold=data1.units_sold+data2.units_sold;
//		data.revenue=data1.units_sold*data1.revenue+data2.units_sold*data2.revenue;
//		std::cout<<data.bookNo<<' '<<data.units_sold<<' '<<data.revenue;
//	}
//	else std::cout<<"Error!";
	
//	Sales_data item1,item2;
//	while(cin>>item1.bookNo>>item2.bookNo){
//		
//		try{
//			if(item1.bookNo!=item2.bookNo)
//				throw runtime_error("Data must refer to same ISBN");
//			cout<<"Equal"<<endl;
//		}catch(runtime_error err){
//	//	}catch(range_error err){
//			cout<<err.what() //err.what() ����ʼ��runtime_error����ʱ�ĳ�ʼֵ 
//							//�˴�Ϊ  "Data must refer to same ISBN"
//			<<"\nTry Again?Enter y or n"<<endl;
//			char c;
//			cin>>c;
//			if(!cin||c=='n')break;
//		//	if(c=='n')break; //���������ctrl zҲ���˳� 
//		}
//
////		if(item1.bookNo!=item2.bookNo)
////				throw runtime_error("Data must refer to same ISBN");
////			cout<<"Equal"<<endl;
////		
//
//	}
	
	
	int a,b;
	while(cin>>a>>b){
		try{
			if(b==0)throw runtime_error("error!");
			cout<<a/b<<endl;
		}catch(runtime_error err){
		//	cout<<err.what()<<endl;
			cout<<err.what()<<"\nTry Again? Enter y or n"<<endl;
			char c;cin>>c;
			if(!cin||c=='n')break;
		}
	}
	return 0;
}
