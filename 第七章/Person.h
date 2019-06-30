#ifndef PERSON
#define PERSON
#include <iostream>
#include <string>
struct Person{
	std::string Name;
	std::string Address;
	std::string GetName() const {return Name;}
	std::string GetAddress() const {return Address;} 
};
#endif
