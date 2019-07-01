#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>
using namespace std;
class Person{
	std::string Name;
	std::string Address;
	public:
	friend istream &read(istream &is,Person &person);
	friend ostream &print(ostream &os,const Person &person);
	Person()=default;
	Person(const string &s):Name(s){}
	Person(const string &s1,const string &s2):Name(s1),Address(s2){}
	Person(istream &is)
	{
		is>>Name>>Address;
	}
	std::string GetName() const {return Name;}
	std::string GetAddress() const {return Address;} 
	private:
	
	
};
istream &read(istream &is,Person &person)
{
	is>>person.Name>>person.Address;
	return is;
}
ostream &print(ostream &os,const Person &person)
{
	os<<person.GetName()<<' '<<person.GetAddress();
	return os;
}
#endif
