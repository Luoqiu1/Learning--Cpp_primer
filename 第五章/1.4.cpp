#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main ()
{
//	int sum=0,val=1;
//	while(val<=10)sum+=val,++val;
//	cout<<"Sum of 1 to 10 inclusive is "<<sum<<endl;

//	const vector<string> scores{"F","D","C","B","A","A++"};
//	vector<string> const scores{"F","D","C","B","A","A++"};
//	scores.push_back("S");
//	scores[2]="S"; 
	//以上两种形式容器 加了const 长度和内容都不能改！即 容器 这一整体是常量！ 
	
	const vector<string> scores{"F","D","C","B","A","A++"};
	int x;string MyScore;
	while(cin>>x){
		if(x>=0&&x<=100){
			if(x<60)MyScore=scores[0];
			else if(x==100)MyScore=scores[5];
			else{
				if(x%10>7) MyScore=scores[x/10-5]+'+';
				else if(x%10<3) MyScore=scores[x/10-5]+'-';
				else MyScore=scores[x/10-5];
			}
			cout<<MyScore<<endl;
		}
		else cout<<"Error Input!"<<endl;
	}
	return 0;
 } 
