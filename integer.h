#pragma once

const int INTEGER_SIZE = 1000;

class Integer
{
private:
	unsigned int num[INTEGER_SIZE];
	int length;
public:
	void assign(const char* digits);
	void scan();
	void print();
	Integer add(Integer b);
	Integer subtract(Integer b);
	Integer multiply(Integer b);
	Integer divide(Integer b);
	Integer mod(Integer b);
	int cmp(Integer b);
	Integer gcd(Integer b);
};