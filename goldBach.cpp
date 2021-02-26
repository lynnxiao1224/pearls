//EXPE3_1_2.cpp

#include <iostream>

using namespace std;

bool isPrime(int n);

bool isPrime(int n)
{
	if (n == 0 || n == 1)
		return false;

	for (int a = 2; a <= sqrt(n); a++)
	{
		if (n % a == 0)
			return false;
	}
	return true;
}

void Goldbach(int n)
{
	for (int i = 3; i < n; i += 2) {

		if (n - i < i) {
			break;
		}

		if (isPrime(i) && isPrime( n - i)) {
			cout << n << " = " << i << " + " << n - i << endl;
		}
	}
	
	/*
	int prime = 3;
	while (prime <= n - prime)
	{
		if (isPrime(prime) && isPrime( n - prime))
		{
			cout << n << " = " << prime << " + " << prime_lost << endl;
		}

		prime += 2;
	}
	*/
}