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
	return 0;
}
