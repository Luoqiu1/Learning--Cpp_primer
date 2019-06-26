#include <string>
using namespace std;
string (&fun(string (&s)[10]))[10];
using ss=string[10];
ss	&fun(ss &s);
auto fun(string (&s)[10])->string(&)[10];
string s[10];
decltype(s) &fun(string (&s)[10]);

int main ()
{
	return 0;
}
