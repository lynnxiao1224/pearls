
/*
Test inhenance access features:
*/

#include <iostream>

#include "Header.h"


using namespace std;

class A
{
public:
	A() 
	{ 
		number = 0; 
	};

	~A() {};

	void setNumberValue(int num) {
		number = num;
	}

	int getNumberValue() {
		return number;
	}

private:
	int number;
};

// Through B, just can call A::getNumberValue()
class B :private A     // NOT: public A !!!
{
public:
	int getNumberValueInA() {
		return getNumberValue();
	}
};

//Throgh C, just can call A::setNumberValue()
class C :private A     // NOT: public A !!!
{
public:
	void setNumbetValueInA(int num) {
		setNumberValue(num);
	}
};

//Through D, can call A::getNumberValue() and setNumberValue().
class D : public A
{
public:
	// don't do anything to support the functions.
};


void testEnhentance()
{
	int result = 0;

	B  b;
	//result = b.getNumberValue(); // will compile Error!
	//b.setNumberValue(3); // will compile Error!
	result = b.getNumberValueInA();
	cout << "number in B = " << result << endl;

	C c;
	//result = c.getNumberValue(); // will compile Error!
	//c.setNumberValue(3); // will compile Error!
	c.setNumbetValueInA(3);

	D d;
	d.setNumberValue(4);
	result = d.getNumberValue();
	cout << "number in D = " << result << endl;
}




