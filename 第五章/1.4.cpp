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
	
//	const vector<string> scores{"F","D","C","B","A","A++"};
//	int x;string MyScore;
//	while(cin>>x){
//		if(x>=0&&x<=100){
//			if(x<60)MyScore=scores[0];
//			else if(x==100)MyScore=scores[5];
//			else{
//				if(x%10>7) MyScore=scores[x/10-5]+'+';
//				else if(x%10<3) MyScore=scores[x/10-5]+'-';
//				else MyScore=scores[x/10-5];
//			}
//			cout<<MyScore<<endl;
//		}
//		else cout<<"Error Input!"<<endl;
//	}
	
	char ch;unsigned otherCnt=0;unsigned aCnt=0;unsigned eCnt=0;unsigned iCnt=0;unsigned oCnt=0;unsigned uCnt=0;
	unsigned spaceCnt=0;unsigned tCnt=0;unsigned nCnt=0;unsigned ffCnt=0;unsigned fiCnt=0;unsigned flCnt=0;
//	while(cin>>ch){
//		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')vowelCnt++;
//	}
//	cout<<vowelCnt<<endl;

//	while(scanf("%c",&ch)!=EOF){
//	while(cin>>ch){
	char pre; 
	while(cin>>noskipws>>ch){//no skip whitespace ! 学到了 
		if(ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U')ch+='a'-'A';
		switch(ch){
			case'a':++aCnt;break;
			case'e':++eCnt;break;
			case'i':++iCnt;if(pre=='f')++fiCnt;break;
			case'f':if(pre=='f')++ffCnt;break;
			case'l':if(pre=='f')++flCnt;break;
			case'o':++oCnt;break;
			case'u':++uCnt;break;
			case' ':++spaceCnt;break;
			case'\t':++tCnt;break;
			case'\n':++nCnt;break;
			default:++otherCnt;
		}
		pre=ch;
	}
	cout<<"a："<<aCnt<<' '<<"e："<<eCnt<<' '<<"i："<<iCnt<<' '<<"o："<<oCnt<<' '
	<<"u："<<uCnt<<' '<<"t："<<tCnt<<' '<<"n："<<nCnt<<' '<<"space："<<spaceCnt<<' '<<"other："<<otherCnt<<' '
	<<"ff："<<ffCnt<<' '<<"fi："<<fiCnt<<' '<<"fl："<<flCnt<<' ';

	return 0;
 } 
