
/*
 function: reverse a string.
 example: before: "12345"
          after: "54321"
*/

#include <iostream>
#include <string>
#include <algorithm>

#include "Header.h"

using namespace std;

void reverseStringWithStlAlgorithm(string &s)
{
	if (s.empty()) {
		return;
	}

	reverse(s.begin(), s.end());

}

void reverseStringWithTwoPointers(string &s)
{
	if (s.empty()) {
		return;
	}

	int left = 0, right = s.size() - 1;
	while (left < right) {
		swap(s[left], s[right]);
		left++;
		right--;
	}
}

void testReverseString() 
{
	string s = "12345";

	cout << "before: s = " << s << endl;
	reverseStringWithStlAlgorithm(s);
	cout << "after1: s = " << s << endl;
	reverseStringWithTwoPointers(s);
	cout << "after2: s = " << s << endl;

}


