//EXPE4_3_1_Reverse.cpp

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

template <typename T>
void Reverse(T array[], int SIZE);

int testReverse()
{
	const int SIZE = 10;
	int array[SIZE] = {1,2,3,4,5,6,7,8,9,0};

	//const int SIZE = 11;
	//int array[SIZE] = { 1,2,3,4,5,6,7,8,9,0,99 };

//	for (int i = 0; i < 9; i++) {
//	    cout << "please input No: " << i + 1 << " number" << endl;
//	    cin >> array[i];
 //   }

	cout << "Before: ";
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	Reverse(array, SIZE);
	
	cout << "After: ";
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << " ";
	}
	cout << endl;

	return 0;
}

template <typename T>
void Reverse(T array[], int SIZE)
{
	/*
	T temp;
	if (SIZE % 2) {
		//SIZE为奇数
		for (int j = 0; j < SIZE / 2 - 0.5; j++) {
			temp = array[j];
			array[j] = array[SIZE - j - 1];
			array[SIZE - j - 1] = temp;
		}
	}
	else {
		//SIZE为偶数
		for (int j = 0; j < SIZE / 2; j++) {
			temp = array[j];
			array[j] = array[SIZE - j - 1];
			array[SIZE - j - 1] = temp;
		}
	}
	*/
	for (int i = 0, j = SIZE - 1; i < j; i++, j--) {
		T temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
}