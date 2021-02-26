
//COMEXP_4_classFraction.cpp

#include <iostream>
#include <cmath>
#include <cstring>
#include "classFraction.h"

using namespace std;

Fraction::Fraction()
{
	ispositive_ = true;
	numerator_ = 0;
	denominator_ = 1;
}

Fraction::Fraction(int numerator, int denominator)
{
	ispositive_ = true;
	numerator_ = numerator;
	denominator_ = denominator;
	reduce();
}

Fraction::Fraction(bool ispositive,
	int numerator, int denominator)
{
	ispositive_ = ispositive;
	numerator_ = numerator;
	denominator_ = denominator;
	reduce();
}

void Fraction::reduce()
{
	for (int i = 2; i <= numerator_
		&& i <= denominator_; i++) {
		if (numerator_ % i == 0
			&& denominator_ % i == 0) {
			numerator_ /= i;
			denominator_ /= i;
		}
	}
}

Fraction Fraction::add(Fraction b)//a+b
{
	Fraction k;
	k.denominator_ = denominator_ * b.denominator_;
	int up_a = numerator_;
	int up_b = b.numerator_;
	if (ispositive_ == 0)
		up_a = 0 - up_a;
	if (b.ispositive_ == 0)
		up_b = 0 - up_b;
	/*
	k.numerator_ = up_a * b.denominator_
		+ up_b * denominator_;
	if (k.numerator_ < 0) {
		k.ispositive_ = false;
		k.numerator_ = 0 - k.numerator_;
	}
	*/
	int up_k = up_a * b.denominator_
		+ up_b * denominator_;
	if (up_k < 0) {
		k.ispositive_ = false;
		k.numerator_ = -up_k;
	}
	else {
		k.ispositive_ = true;
		k.numerator_ = up_k;
	}



	k.reduce();
	return k;
}

Fraction Fraction::subtract(Fraction b)//a-b
{
	Fraction k;
	k.denominator_ = denominator_ * b.denominator_;
	int up_a = numerator_;
	int up_b = b.numerator_;
	if (ispositive_ == 0)
		up_a = 0 - up_a;
	if (b.ispositive_ == 0)
		up_b = 0 - up_b;
	k.numerator_ = up_a * b.denominator_ - up_b * denominator_;
	if (k.numerator_ < 0) {
		k.ispositive_ = false;
		k.numerator_ = 0 - k.numerator_;
	}
	k.reduce();
	return k;
}

Fraction Fraction::multiply(Fraction b)//a*b
{
	Fraction k;
	k.numerator_ = b.numerator_ * numerator_;
	k.denominator_ = b.denominator_ * denominator_;
	if (b.ispositive_ == ispositive_)
		k.ispositive_ = true;
	else
		k.ispositive_ = false;
	k.reduce();
	return k;
}

bool get_fraction(const char* buffer, int start, int end, char* up, char* down)
{
	int i = start;
	while (i < end) {
		if (buffer[i] == '/') {
			break;
		}
		i++;
	}
	strncpy_s(up, 128, &buffer[start], i - start);
	strncpy_s(down, 128, &buffer[i+1], end - i);

	return true;
}

void test_class()
{
	char buffer[128];
	char up[128], down[128];
	bool flag = true;

	cout << "please input fraction:" << endl;
	cin >> buffer;
	if (buffer[0] >= '0' && buffer[0] <='9') {  // input format: 3/5
		get_fraction(buffer, 0, strlen(buffer)-1, up, down);
	}
	else {                             // input format: +3/5 or -3/5
		if (buffer[0] == '-') {
			flag = false;
		}
		else if (buffer[0] == '+') {
			flag = true;
		}
		else {
			cout << " input format errr !" << endl;     
			return;
		}

		get_fraction(buffer, 1, strlen(buffer) - 1, up, down);
	}

	cout << "char : up=" << up << ", down=" << down << endl;

	int iUp = atoi(up);
	int iDown = atoi(down);

	cout << "int: up=" << up << ", down=" << down << endl;

}


