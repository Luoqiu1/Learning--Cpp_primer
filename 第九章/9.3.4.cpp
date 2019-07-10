#include <iostream>
#include <forward_list>
#include <list>
using namespace std;

int main (int argc,char *argv[])
{
	forward_list<int> flst1{1,2,3,4,5,6,7};
//	auto it=flst1.before_begin();
//	while(it!=flst1.end()-1){
//		if(*(it+1)%2)flst1.erase_after(it);
//		else ++it;
//	}

	auto prev=flst1.before_begin(),curr=flst1.begin();
	while(curr!=flst1.end()){
		if(*curr%2){
			curr=flst1.erase_after(prev);
		}
		else{
			++prev;++curr;
		}
	}
	for(auto i:flst1)cout<<i<<' ';cout<<endl;
	return 0;
 } 
