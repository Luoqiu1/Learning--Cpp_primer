#include <iostream>
#include <queue>
#include <string>
#include <stack>
using namespace std;

int main ()
{
//	string s;
//	stack<string> q;
//	while(cin>>s){
//		q.emplace(s);
//	}
//	for(auto i:q)cout<<i<<' ';cout<<endl;
//	s=q.front();
//	cout<<s<<endl;
//	for(auto i:q)cout<<i<<' ';cout<<endl;
//	return 0;
	stack<char> S1,S2;
	double ans=0;
	char c;
	cin>>c;
	if(c!='(')cout<<"Error!"<<endl;
	else{
		S1.push(c);
		while(!S1.empty()){
			cin>>c;
			if(c=='(')S1.push(c);
			else if(c!=')'){
				S2.push(c);
			}
//			else{
//				S1.pop();
//				double tmp=0;
//				int k=1;
//				while(!S2.empty()){
//					char c=S2.top();S2.pop();
//					if(isdigit(c));
//				}
//			}
					//���洦�������ڵ��������е㸴��
					//��ʱ��� 
		}
	}
	
}
