#pragma once
#include <string>
#include<iostream>
using namespace std;
class Person {
public:
	

	Person(int ph, string fn, string ln) :phNum(ph), firstName(fn), lastName(ln) {};
	
	int getPhNum() const
	{
		return phNum;
	}
	string getFirstName()const
	{
		return firstName;
	}
	string getLastName()const
	{
		return lastName;
	}
	friend	ostream& operator<<(ostream& outs, const Person& rhs)
	{
		outs << rhs.firstName << "\t" << rhs.lastName << "\t" << rhs.phNum << endl;
		return outs;
	}
private:
	int phNum;
	string firstName, lastName;
};
