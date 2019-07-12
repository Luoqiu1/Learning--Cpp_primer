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
//		//这个pos++非常重要！
//		//搜寻下一个尚未处理的字符！
//		//在循环条件中只是返回了满足条件的刚被处理的那个字符！ 
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
		//这条语句一定不要忘记了！。。
		//其效果类似于上一目中的++pos！
		//这里的话，如果没有重置pos为0
		//则第一次未找到时，会使pos==npos
		//而后没有机会改这个值了！
		//从这里开始搜索必然结果是false 
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
