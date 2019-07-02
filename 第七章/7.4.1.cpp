#include <iostream>
#include <string>
using namespace std;

typedef double Money;
string bal;
class Account{
	public:
		
		Account()=default;
		friend ostream &print(ostream &os,const Account &a);
		Money balance() {return bal;}
		Account(istream &is) {is>>bal;}
	private:
	//	typedef double Money;	该条语句重新定义了类型名字，是错误的行为！
	//	但是编译器不为此负责。一些编译器（我的就这样）仍顺利通过这样的代码，而忽略了代码有错的事实！ 
		Money bal;
}; 
inline ostream &print(ostream &os,const Account &a)
{
	os<<a.bal;
	return os;
}
int main ()
{
	Account a(cin),b;
	print(cout,a)<<endl;
	cout<<a.balance();
	return 0;
}
