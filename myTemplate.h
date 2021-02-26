#ifndef __MY_TEMPLATE__
#define __MY_TEMPLATE__

#include <iostream>

class myFraction1
{
public:
	myFraction1(int num, int den = 1) : m_numerator(num), m_denominator(den) {}

	operator double() const 
	{
		return static_cast<double>(m_numerator / m_denominator);
	}

private:
	int m_numerator;
	int m_denominator;
};

template<class Arg, class Result>
struct myBinary_function {
	typedef Arg argument_type;
	typedef Result result_type;
};

struct testSizeof {
	typedef int i8;
	typedef double d16;
};

void test_myTemplate()
{
	myFraction1 f(3, 5);
	double d1 = 4.1 + f;   // call operator double() f->3/5=0.6
	cout << "case 1 = " << d1 << endl;    //4.1  f = 0????
	double d2 = 1.5;
	cout << "case 2 = " << d2 << endl;  // 1.5

	double d3 = f + 4.5;
	cout << "case 2 = " << d3 << endl;  // result:4.5   why f = 0???

	cout << "sizeof(struct testSizeof) = " << sizeof(struct testSizeof) << endl;

	cout << " compiler version = " << __cplusplus << endl; //199711
}





#endif // !__MY_TEMPLATE__
