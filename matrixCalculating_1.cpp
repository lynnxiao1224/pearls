//EXP_6.2.4_MatrixCalculating.cpp

#include <iostream>

using namespace std;

//const int HUNDRED = 100;

void MatrixMultiplication(int** matrix_left, int** matrix_right, int limit, int** dst);

int testMatrix_1()
{
	int ROW = 0, COLUMN = 0;
	cout << "please enter row and column:" << endl;
	cin >> ROW >> COLUMN;

	
	//Initialize matrix
	//const int row = 100, column = 100;
	//float** matrix1, ** matrix2, ** matrix3, ** matrix4, ** matrix5, ** matrix6;
	int** matrix1, ** matrix2, ** matrix3, ** matrix4, ** matrix5, ** matrix6;

	//Initialize matrix1
	matrix1 = new int* [ROW];
	for (int i = 0; i < ROW; i++) {
		matrix1[i] = new int[COLUMN];
	}

	//Initialize matrix2
	matrix2 = new int* [ROW];
	for (int i = 0; i < ROW; i++) {
		matrix2[i] = new int[COLUMN];
	}

	//Initialize matrix3 (Transpose matrix1)
	matrix3 = new int* [COLUMN];
	for (int i = 0; i < COLUMN; i++) {
		matrix3[i] = new int[ROW];
	}

	//Initialize matrix4 (Transpose matrix2)
	matrix4 = new int* [COLUMN];
	for (int i = 0; i < COLUMN; i++) {
		matrix4[i] = new int[ROW];
	}

	//Initialize matrix5 --> matrix1 * matrix4
	matrix5 = new int* [ROW];
	for (int i = 0; i < ROW; i++) {
		matrix5[i] = new int[ROW];
	}

	//Initialize matrix6 --> matrix3 * matrix2
	matrix6 = new int* [COLUMN];
	for (int i = 0; i < COLUMN; i++) {
		matrix6[i] = new int[COLUMN];
	}


	//Input matrix1
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cout << "please enter matrix1 in " << i + 1 << " row " << j + 1 << " column" << endl;
			cin >> matrix1[i][j];
		}
	}
	cout << endl;

	//Input matrix2
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
//			cout << "请输入矩阵2的第 " << i + 1 << " 行的第 " << j + 1 << " 列：" << endl;
			cout << "please enter matrix2 in " << i + 1 << " row " << j + 1 << " column" << endl;
			cin >> matrix2[i][j];
		}
	}
	cout << endl;

	//Outprint matrix1
	cout << "Matrix1:" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cout << "\t" << matrix1[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//Outprint matrix2
	cout << "Matrix2:" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cout << "\t" << matrix2[i][j];
		}
		cout << endl;
	}
	cout << endl;


	//Transpose matrix1 --> matrix3
	for (int j = 0; j < COLUMN; j++) {
		for (int i = 0; i < ROW; i++) {
			int temp;
			temp = matrix1[i][j];
			matrix3[j][i] = temp;
		}
	}

	//Outprint matrix3
	cout << "Matrix3:" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cout << "\t" << matrix3[j][i];
		}
		cout << endl;
	}
	cout << endl;

	//Transpose matrix2 --> matrix4
	for (int j = 0; j < COLUMN; j++) {
		for (int i = 0; i < ROW; i++) {
			int temp;
			temp = matrix2[i][j];
			matrix4[j][i] = temp;
		}
	}

	//Outprint matrix4
	cout << "Matrix4:" << endl;
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cout << "\t" << matrix4[j][i];
		}
		cout << endl;
	}
	cout << endl;

/*
	//Initialize matrix
	float matrix1[HUNDRED][HUNDRED], matrix2[HUNDRED][HUNDRED],
		matrix3[HUNDRED][HUNDRED], matrix4[HUNDRED][HUNDRED],
		matrix5[HUNDRED][HUNDRED], matrix6[HUNDRED][HUNDRED];

	//Input matrix1
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << "请输入矩阵1的第 " << i + 1 << " 行的第 " << j + 1 << " 列：" << endl;
			cin >> matrix1[i][j];
		}
	}
	cout << endl;

	//Outprint matrix1
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << "\t" << matrix1[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//Input matrix2
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << "请输入矩阵2的第 " << i + 1 << " 行的第 " << j + 1 << " 列：" << endl;
			cin >> matrix2[i][j];
		}
	}
	cout << endl;

	//Outprint matrix2
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < column; j++) {
			cout << "\t" << matrix2[i][j];
		}
		cout << endl;
	}
	cout << endl;


	//Transpose matrix1 --> matrix3
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < row; i++) {
			float temp;
			temp = matrix1[i][j];
			matrix3[j][i] = temp;
		}
	}

	//Outprint matrix3
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < row; i++) {
			cout << "\t" << matrix3[j][i];
		}
		cout << endl;
	}
	cout << endl;

	//Transpose matrix2 --> matrix4
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < row; i++) {
			float temp;
			temp = matrix2[i][j];
			matrix4[j][i] = temp;
		}
	}

	//Outprint matrix4
	for (int j = 0; j < column; j++) {
		for (int i = 0; i < row; i++) {
			cout << "\t" << matrix4[j][i];
		}
		cout << endl;
	}
	cout << endl; 
	*/

	//matrix5 = matrix1 * matrix4
//	MatrixMultiplication(matrix1, matrix4, ROW, matrix5);
	MatrixMultiplication(matrix1, matrix3, ROW, matrix5);

	//Outprint matrix5
	for (int i = 0; i < ROW; i++) {
		for (int j = 0; j < ROW; j++) {
			cout << "\t" << matrix5[i][j];
		}
		cout << endl;
	}
	cout << endl;

	//matrix6 = matrix3 * matrix2
//	MatrixMultiplication(matrix3, matrix2, COLUMN, matrix6);
	MatrixMultiplication(matrix2, matrix4, COLUMN, matrix6);



	//Outprint matrix6
	for (int i = 0; i < COLUMN; i++) {
		for (int j = 0; j < COLUMN; j++) {
			cout << "\t" << matrix6[i][j];
		}
		cout << endl;
	}
	cout << endl;

	delete [] matrix1;
	delete [] matrix2;
	delete [] matrix3;
	delete [] matrix4;
	delete [] matrix5;
	delete [] matrix6;

	return 0;
}

/*float Calculate(float matrix_left[HUNDRED][HUNDRED], float matrix_right[HUNDRED][HUNDRED],
	float matrix_done[HUNDRED][HUNDRED], int row, int column)
{
	for (int donexy = 0, donexy < 
}*/

/*
void MatrixMultiplication(float** matrix_left, float** matrix_right, int limit, float** dst)
{
	for (int i = 0; i < limit; i++) {
		for (int j = 0; j < limit; j++) {
			//for (int m = 0, n = 0; m <= i || n <= j; m++, n++) {
			for (int m = 0, n = 0; m <= i && n <= j; m++, n++) {
				dst[i][j] += matrix_left[i][m] * matrix_right[n][j];
			}
		}
	}
}
*/

void MatrixMultiplication(int** A, int** B, int limit, int** dst)
{
	cout << "limit = " << limit << endl;
	for (int i = 0; i < limit; i++) {
		for (int j = 0; j < limit; j++) {
			//for (int m = 0, n = 0; m <= i || n <= j; m++, n++) {
			int sum = 0;
			for (int m = 0; m < limit; m++) {
				sum += A[i][m] * B[m][j];
			}
			cout << "i = " << i << ", j= " << j << ", sum=" << sum << endl;
			dst[i][j] = sum;
		}
	}
}




