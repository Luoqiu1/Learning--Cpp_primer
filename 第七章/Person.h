#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>
using namespace std;
struct Person{
	std::string Name;
	std::string Address;
	std::string GetName() const {return Name;}
	std::string GetAddress() const {return Address;} 
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
