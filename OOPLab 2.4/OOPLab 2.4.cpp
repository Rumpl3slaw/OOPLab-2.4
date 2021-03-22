#include <iostream>
#include "Matrix.h"
#include <Windows.h>

using namespace std;

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int size_A, size_B;
	cout << "\n\nМатриця A:" << endl;
	cout << "Введіть розміри матриці: "; cin >> size_A;
	cout << "Matrix B:"  << endl;
	cout << "Введіть розміри матриці: "; cin >> size_B;

	Matrix A(size_A),
		B(size_B);

	cout << "\n\nMatrix A:";
	cin >> A;
	cout << "\n\nMatrix B:";
	cin >> B;

	cout << "\n\nMatrix A:";
	cout << A;
	cout << "\n\nMatrix B:";
	cout << B;

	A + B;

	cout << "\n\nОбчислення норми матриці A: ";
	cout << A.CalcnormMatrices();

	cout << "\n\nОбчислення норми матриці B: ";
	cout << B.CalcnormMatrices();

	cout << "\n\nПорівняння матриць: " << endl;

	cout << "Перший спосіб  A < B: " << (A < B) << endl;
	cout << "Перший спосіб  A > B: " << (A > B) << endl;
	cout << "Другий спосіб  A <= B: " << (A <= B) << endl;
	cout << "Другий спосіб  A >= B: " << (A >= B) << endl;
	cout << "Третій спосіб  A == B: " << (A == B) << endl;
	cout << "Третій спосіб  A != B: " << (A != B) << endl;

	return 0;
}