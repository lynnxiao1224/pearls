//COMEXP_3_Integer.cpp

#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <cmath>
#include "integer.h"

using std::cin;
using std::cout;
using std::endl;

int test_Integer()
{
	//char* dights1 = new char;
	std::string dights1;
	Integer x, y;
	cout << "enter x: 0x";
	cin >> dights1;
	cout << "\n";
	x.assign(dights1.c_str());

	char* dights2 = new char;
	cout << "enter y: 0x";
	cin >> dights2;
	cout << "\n";
	y.assign(dights2);

	cout << dights1 << "\n";
	cout << dights2 << "\n";
	x.print();
	y.print();

	return 0;
}

void Integer::assign(const char* dights)
{
	length = strlen(dights);
	int i = length - 1;
	for (int j = 0; j < length; i--, j++) {//change char into unsighed int
		if (dights[i] >= '0' && dights[i] <= '9') {
			num[j] = (dights[i] - '0') * pow(16, j);
		}
		else if (dights[i] >= 'A' && dights[i] <= 'F') {
			num[j] = (10 + (dights[i] - 'A')) * pow(16, j);
		}
		else if (dights[i] >= 'a' && dights[i] <= 'f') {
			num[j] = (10 + (dights[i] - 'a')) * pow(16, j);
		}
	}
	for (int k = length; k < 10; k++) {
		num[k] = 0;
	}
	
	/*for (int j = 0; j < length; j++) {
		int haisu = pow(10, j);
		if (num[j] >= 10 * haisu) {
			num[j + 1] += (num[j] / (10 * haisu)) * (10 * haisu);
		}
		num[j - 1] += num[j] % haisu;
	}*/

	for (int i = length - 1; i >= 0; i--) {
		int ihaisu = pow(10, i);//bei4 shu4
		if (num[i] / ihaisu >= 10) {
			num[i + 1] += num[i] / (10 * ihaisu);
			for (int k = i + 1; num[k] >= 10; k++) {
				num[k + 1] += num[k] / 10;
			}
		}
		if (i > 0) {
			num[i - 1] += num[i] % ihaisu;
		}
		int a = num[i];
		num[i] = a / ihaisu - a / (10 * ihaisu) * 10;
	}
	return;
}

/*void Integer::scan()
{

}*/

void Integer::print()
{
	int i = length;
	while (num[i] == 0) {
		i--;
	}
	
	for (; i >= 0; i--) {
		cout << num[i];
	} 
	cout << "\n";

	return;
}

/*Integer Integer::add(Integer b)
{
	for (int j = 0; ; j++) {
		num[j] += b.num[j];
	}
	for (int j = 0; j < length; j++) {
		if (num[j] >= 10 && num[j] <= 16) {
			num[j] %= 10;
			num[j + 1]++;
		}
	}
	return;
}

Integer Integer::subtract(Integer b)
{
	for (int i = 0; ; i++) {
		num[i] -= b.num[i];
	}
}
Integer Integer::multiply(Integer b)
{
	for (int i = 0; ; i++) {
		num[i] *= b.num[i];
	}
}
Integer Integer::divide(Integer b)
{
	for (int i = 0; ; i++) {
		num[i] /= b.num[i];
	}
}
Integer Integer::mod(Integer b)
{
	for (int i = 0; ; i++) {
		num[i] %= b.num[i];
	}
}*/