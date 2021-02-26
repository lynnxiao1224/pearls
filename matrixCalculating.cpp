//EXP_6.2.4_MatrixCalculating.cpp

#include <iostream>

using namespace std;

int testMatrix()
{
	int row = 0, column = 0;
	cout << "Please enter the row:" << endl;
	cin >> row >> column;


	//Initialize matrix
//	float** matrix1, ** matrix2, ** matrix3, ** matrix4, ** matrix5, ** matrix6;
	float** matrix1, ** matrix2, ** matrix3, ** matrix4;

	//Initialize matrix1
	matrix1 = new float* [row];
	for (int i = 0; i < row; i++) {
		matrix1[i] = new float[column];
	}

	//Initialize matrix2
	matrix2 = new float* [row];
	for (int i = 0; i < row; i++) {
		matrix2[i] = new float[column];
	}

	//Initialize matrix3 (Transpose matrix1)
	matrix3 = new float* [column];
	for (int i = 0; i < column; i++) {
		matrix3[i] = new float[row];
	}

	//Initialize matrix4 (Transpose matrix2)
	matrix4 = new float* [column];
	for (int i = 0; i < column; i++) {
		matrix4[i] = new float[row];
	}
	/*
	//Initialize matrix5 --> matrix1 * matrix4
	matrix5 = new float* [row];
	for (int i = 0; i < row; i++) {
		matrix5[i] = new float[row];
	}

	//Initialize matrix6 --> matrix2 * matrix3
	matrix6 = new float* [column];
	for (int i = 0; i < column; i++) {
		matrix6[i] = new float[column];
	}
	*/
	
	//Input matrix1
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << "please enter matrix1 value in " << i + 1 << " row and " << j + 1 << " column" << endl;
			cin >> matrix1[i][j];	
		}
	}
	cout << endl;

	//Outprint matrix1
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << matrix1[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	//Input matrix2
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
//			cout << "请输入矩阵2的第 " << i + 1 << " 行的第 " << j + 1 << " 列：" << endl;
			cout << "please enter matrix2 value in " << i + 1 << " row and " << j + 1 << " column" << endl;
			cin >> matrix2[i][j];
		}
	}
	cout << endl;

	//Outprint matrix2
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << matrix2[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
	

	//Transpose matrix1 --> matrix3
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < row; i++) {
			float temp = matrix1[i][j];
			matrix3[j][i] = temp;
		}
	}

	//Outprint matrix3
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < row; i++) {
			cout << matrix3[j][i] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	//Transpose matrix2 --> matrix4
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < row; i++) {
			float temp = matrix2[i][j];
			matrix4[j][i] = temp;
		}
	}

	//Outprint matrix4
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < row; i++) {
			cout << matrix4[j][i] << "\t";
		}
		cout << endl;
	}
	cout << endl;

	return 0;
}