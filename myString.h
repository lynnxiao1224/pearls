#ifndef __MYSTRING__
#define __MYSTRING__

#include <iostream>

using namespace std;

class myString {
public:
	myString(const char* ctr = 0);
	myString(const myString& other);
	myString& operator=(const myString& other);
	~myString();

	char* get_data() const { return m_data; }

private:
	char* m_data;
};

myString::myString(const char* ctr) 
{
	if (ctr) {
		m_data = new char[strlen(ctr) + 1];
		strcpy_s(m_data, strlen(ctr) + 1, ctr);
	}
	else {
		m_data = new char[1];
		m_data[0] = '\0';
	}
	cout << "in constructor: " << m_data << endl;
}

myString::myString(const myString& other)
{
	m_data = new char[strlen(other.m_data) + 1];
	strcpy_s(m_data, strlen(other.m_data) + 1, other.m_data);
	
	cout << "in copy constructor: " << m_data << endl;

}

myString& myString::operator=(const myString& other) 
{
	if (this == &other) {

		cout << "in copy assigment: same object" << endl;

		return *this;
	}

	delete [] m_data;
	m_data = new char[strlen(other.m_data) + 1];
	strcpy_s(m_data, strlen(other.m_data) + 1, other.m_data);

	cout << "in copy assigment: " << m_data << endl;

	return *this;
}

myString::~myString()
{
	if (m_data) {
		delete[] m_data;
	}

	m_data = nullptr;
}


class myAccount
{
public:
	static void set_rate(const double& x) { m_rate = x; }
	static void print_rate() { cout << "address = "<< &m_rate << ", value = "<< m_rate << endl; }
private:
	static double m_rate;
};
double myAccount::m_rate = 8.0;

void test_static()
{
	myAccount::print_rate();

	myAccount::set_rate(5.0);
	myAccount::print_rate();

	myAccount a;
	a.set_rate(7.0);
	a.print_rate();

}

/*
class myAA
{
public:
	static myAA& getInstance();

private:
	myAA();
};

myAA& myAA::getInstance()
{
	static myAA a;
	return a;
}
*/


// class template
template<typename T>
class myComplexEx
{
public:
	myComplexEx(T r = 0, T i = 0) : re(r), im(i) {}

	myComplexEx<T>& operator += (const myComplexEx<T>&);

	T real() const { return re; }
	T imag() const { return im; }

private:
	T re, im;
	friend myComplexEx<T> __doapl(myComplexEx<T>*, const myComplexEx<T>&);
};

template<typename T>
myComplexEx<T>& myComplexEx<T>::operator += (const myComplexEx<T>& x)
{
	return __doapl(this, x);
}

template<typename T>
inline myComplexEx<T>& __doapl(myComplexEx<T>* ths, const myComplexEx<T>& x)
{
	ths->re += x.re;
	ths->im += x.im;

	return *ths;
}

//function template
namespace XIAOXIAO {
	class myStone
	{
	public:
		myStone(int w = 0, int h = 0, int we = 0) :width(w), heigh(h), weight(we) {}

		bool operator < (const myStone& rhs) const {
			return weight < rhs.weight;
		}

		void printData()
		{
			cout << "width = " << width << ", heigh =" << heigh << ", weight = " << weight << endl;
		}

	private:
		int width, heigh, weight;
	};

	template <class T>
	inline
		const T& min(const T& a, const T& b)
	{
		return b < a ? b : a;
	}
}

void test_mystone()
{
	XIAOXIAO::myStone r1(1, 2, 3), r2(3, 3, 6), r3;
	r3 = XIAOXIAO::min(r1, r2);
	r3.printData();
}

#endif

