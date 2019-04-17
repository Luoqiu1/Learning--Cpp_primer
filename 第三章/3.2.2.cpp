#include <iostream>
#include <string>
using namespace std;
int main ()
{
	string line;
//	while(cin>>line){
//		cout<<line<<endl;
//	}
	string line1,line2;
//	cin>>line1>>line2;
//	if(line1>line2)cout<<line1<<'1';else cout<<line2<<'2';//Ğ¡Ğ´×ÖÄ¸´óÓÚ´óĞ´×ÖÄ¸ 
//	if(line1.size()<line2.size())cout<<line2<<'2';else if(line1.size()>line2.size())cout<<line1<<'1';else cout<<"=="; 
	string line0;
	while(cin>>line0){
		if(!line0.empty())break;
	}
	while(cin>>line){
		line0+=' '+line;
	}
	cout<<line0;
	return 0;
}
