#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main ()
{
//	string s1("ab2c3d7R4E6");
//	string cmp1("123456789");
//	string cmp2;
//	for(char i='a';i!='z'+1;++i)cmp2+=i;
//	for(char i='A';i!='Z'+1;++i)cmp2+=i;
//	cout<<s1<<endl<<cmp1<<endl<<cmp2<<endl;
//	string::size_type pos=0;
//	while((pos=s1.find_first_of(cmp1,pos))!=string::npos){
////	while((pos=s1.find_first_not_of(cmp2,pos))!=string::npos){	
//		cout<<s1[pos]<<' '<<pos<<endl;
//		pos++;
//		//���pos++�ǳ���Ҫ��
//		//��Ѱ��һ����δ������ַ���
//		//��ѭ��������ֻ�Ƿ��������������ĸձ�������Ǹ��ַ��� 
//	}
//	pos=0;
//	while((pos=s1.find_first_of(cmp2,pos))!=string::npos){
////	while((pos=s1.find_first_not_of(cmp1,pos))!=string::npos){ 	
//		cout<<s1[pos]<<' '<<pos<<endl;
//		pos++;
//	}
	
//	string text="amnomnopqxz";
//	pos=text.find_last_not_of("mno");
//	cout<<pos;
	
	ifstream ifs("words.txt");
	string word;
	const string cmp("bdfghijklpqty");
	string::size_type ans=0;
	string::size_type pos;
	while(ifs>>word){
		pos=0;
		//�������һ����Ҫ�����ˣ�����
		//��Ч����������һĿ�е�++pos��
		//����Ļ������û������posΪ0
		//���һ��δ�ҵ�ʱ����ʹpos==npos
		//����û�л�������ֵ�ˣ�
		//�����￪ʼ������Ȼ�����false 
		if((pos=word.find_first_of(cmp,pos))==string::npos){
			continue;
		}
		cout<<word<<endl;
		auto curr=word.size();
		if(curr>ans)ans=curr;
	}
	if(ans)cout<<ans<<endl;
	else cout<<"None"<<endl;
	
	return 0;
}
