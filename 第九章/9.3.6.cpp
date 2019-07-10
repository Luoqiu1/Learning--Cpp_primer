#include <iostream>
#include <forward_list>
#include <list>
#include <vector> 
#include <string>
using namespace std;

int main ()
{
//	forward_list<int> flst1{1,2,3,4,5,6};
//	auto prev=flst1.before_begin(),curr=flst1.begin();
//	for(auto i:flst1)cout<<i<<' ';
//	cout<<endl;
//	while(curr!=flst1.end()){
//		if(*curr%2){
////			flst1.emplace_after(prev,*curr);
////			prev=curr;++curr;
//			curr=flst1.emplace_after(prev,*curr);
//			++curr;prev=curr;++curr;
//			
//			//以上两种写法均可！因为对于list或者forward_list容器
//			//在删除或者添加元素后，迭代器、指针、引用均不会失效！
//			//可以结合链表的数据结构理解！  
//		}
//		else{
//			curr=flst1.erase_after(prev);
//		}
//	}
//	for(auto i:flst1)cout<<i<<' ';
//	cout<<endl;
	
//	vector<int> v{1,2,3};
//	for(auto i:v)cout<<i<<' ';cout<<endl;
//	auto begin=v.begin(),end=v.end();
//	int cnt=0;
//	while(begin!=v.end()){
//		++cnt;
//		++begin;
//		v.insert(begin,42);
//		cout<<"cnt="<<cnt<<' '<<*begin<<endl;
//		++begin;
//	}
//	for(auto i:v)cout<<i<<' ';cout<<endl;

//	vector<int> vi{1,2,3,4,5,5,6,7,8,8,9,10};
//	for(auto i:vi)cout<<i<<' ';cout<<endl;
//	auto iter=vi.begin();
//	while(iter!=vi.end()){
//		if(*iter%2)
//			iter=vi.insert(iter,*iter);
//		iter+=2;
//	}
//	for(auto i:vi)cout<<i<<' ';cout<<endl;
	//上面这段代码问题很大！有很多会产生未定义行为的情况 
	
	return 0;
}
