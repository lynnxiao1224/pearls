#pragma once

class Fraction
{
private:
	unsigned int numerator_, denominator_;
	bool ispositive_;//1 is + and 0 is -.
	void reduce(); // 
public:
	// 
	Fraction();
	Fraction(int numerator, int denominator);
	Fraction(bool ispositive, int numerator, int denominator);
	//void reduce();
	Fraction add(Fraction b);
	Fraction subtract(Fraction b);
	Fraction multiply(Fraction b);
	//Fraction divide(Fraction b);
	//Fraction reciprocal();
	//void print();
	//void println();
	//void scan();
};

void test_class();


