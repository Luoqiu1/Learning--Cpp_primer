#include <iostream>
using namespace std;
inline void go()
{
	cerr<<__func__<<endl;
	cerr<<__FILE__<<endl;
	cerr<<__LINE__<<endl;
	cerr<<__TIME__<<endl;
	cerr<<__DATE__<<endl;
}
int main(int argc,char *argv[])
{
	go();
	return 0;
}
