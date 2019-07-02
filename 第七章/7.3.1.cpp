#include "Screen.h"
class Y;
class X{
	Y *point=nullptr;
};
class Y{
	X a;
};
class Z;
vector<Z> a;

int main ()
{
//	Screen sg1(cin);
//	print(cout,sg1);cout<<endl;
	Screen myScreen(3,5,'X');
	myScreen.display(cout);
	cout<<endl;
	myScreen.move(1,2).set('#').display(cout);
	cout<<endl;
	myScreen.move(0,0).set('#').display(cout);
	cout<<endl;
	myScreen.display(cout);
	cout<<endl;  
	
	return 0;
}
class Z{
	int x;
};

