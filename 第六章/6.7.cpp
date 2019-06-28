void func(const int i)
{
	return;
}

int main ()
{
	void (*f)(int)=func;
	return 0;
 } 
