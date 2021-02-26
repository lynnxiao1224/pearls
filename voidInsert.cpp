//EXP _6.2.2_void Insert.cpp

#include <iostream>

using namespace std;

void Insert(int, int[], int);

int testInsert()
{
	int first = 512;
	const int SIZE = 11;
	int array[SIZE] = {2,4,8,16,32,64,128,256 };
	
	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << "\t";
	}
	cout << endl;

	Insert(first, array, SIZE);
	Insert(5, array, SIZE);
	Insert(1, array, SIZE);

	for (int i = 0; i < SIZE; i++) {
		cout << array[i] << "\t";
	}

	return 0;
}

void Insert(int num, int array[], int size)
{
	/*
	if (num <= array[0]) {
		for (int j = size - 1; j > 0; j--) {
			array[j] = array[j - 1];
		}
		array[0] = num;

		return;
	}
	*/
	for (int i = 0; i < size - 1; i++) {
		if (array[i] != 0 && array[i] <= num) {
			continue;
		}
		for (int j = size - 1; j > i; j--) {
			array[j] = array[j - 1];
		}
		array[i] = num;
		break;
	}	
}
