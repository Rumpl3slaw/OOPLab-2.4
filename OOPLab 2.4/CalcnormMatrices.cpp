#include "Matrix.h"
#include <sstream>
#include <Windows.h>

using namespace std;


void operator +(Matrix& A, Matrix& B) {   
	Matrix C(A.size);
	if (A.size == B.size) {
		for (int i = 0; i < A.size; i++) {
			for (int j = 0; j < B.size; j++)
				C[i][j] = A[i][j] + B[i][j];
		}
		cout << "\n\nМатриця C:";
		cout << C;
	}
	else
		cout << "\n\nМатриці не однакові за розміром";
}

double Matrix::CalcnormMatrices() {   
	int norma_matrix{ 0 };
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			norma_matrix += (int)pow((*this)[i][j], 2);
	}

	return sqrt(norma_matrix);
}

bool operator < (Matrix& A, Matrix& B) {
	bool x(A.size < B.size);
	return x;
}
bool operator > (Matrix& A, Matrix& B) {    
	bool x(A.size > B.size);
	return x;
}

bool operator <= (Matrix& A, Matrix& B) {   
	int sum_A{}, sum_B{};
	bool x{};
	for (int i = 0; i < A.size; i++)
		for (int j = 0; j < B.size; j++) {
			sum_A += A[i][j];
			sum_B += B[i][j];
		}
	x = (sum_A <= sum_B);
	return x;
}

bool operator >= (Matrix& A, Matrix& B) {   
	int sum_A{}, sum_B{};
	bool x{};
	for (int i = 0; i < A.size; i++)
		for (int j = 0; j < B.size; j++) {
			sum_A += A[i][j];
			sum_B += B[i][j];
		}
	x = (sum_A >= sum_B);
	return x;
}

bool operator == (Matrix& A, Matrix& B) {   
	bool x = (A[0][0] == B[0][0]);
	return x;
}
bool operator != (Matrix& A, Matrix& B) {   
	bool x = (A[0][0] != B[0][0]);
	return x;
}