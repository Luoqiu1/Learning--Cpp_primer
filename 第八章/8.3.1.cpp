#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void fun1(istream &is,vector<string> &v)
{
	string s;
	while(getline(is,s)){
		v.push_back(s);
	}
}

void fun2(istringstream &is,const vector<string> &v1,vector<string> &v2)
{
	int a=0;
	for(auto i:v1){
		auto old=is.rdstate();
		cout<<old<<' ';
		is.str(i);
		string s;
		while(is>>s){
			v2.push_back(s);
			++a;
		}	
	//	is.clear();//����һ��Ҫע�⣡
		//Ҫ�������ã���Ȼֱ�ӽ���ѭ������Ϊfailbit����λ��������ͼʹ�����Ĳ�������ʧ�ܣ� 
	//	is.setstate(old);//���д�����׳���Ҫϸ΢����setstate��clear�ĺ������ذ�Ĳ��죡
						//setstate����λ���ǵ��ӵģ��Ӷ����ƵĽǶ�ȥ������
						//��������ǿ�Ƹ�������ԭ״̬�����ǽ������ڲ����������״̬���ӵ�ԭʼ״̬�� 
						//clear�Ĳ������ذ汾�Ǹ�λ��
						//����״̬���ó������ڲ����������״̬��ǿ�Ƹ��ǵ�����ԭ״̬ 
	//	old=is.rdstate();cout<<old<<' ';
		//����Ӧ����clear��
		is.clear(old);
		//����ʵ�����鷳���ʼ״̬
		//��Ϊ��ʼ״̬��goodbit
		//ֱ��is.clear()! 
	}
	cout<<endl<<a<<endl;
}

int main ()
{
	ifstream ifs("ifile.txt");
	if(ifs){
		istringstream iss;
		vector<string> v1;
		fun1(ifs,v1);
		for(auto i:v1)cout<<i<<endl;
		cout<<endl;
		vector<string> v2;
		fun2(iss,v1,v2);
		for(auto i:v2)cout<<i<<endl;
	}
	return 0;
}
