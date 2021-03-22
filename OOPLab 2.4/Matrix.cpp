#include "Matrix.h"
#include <sstream>
#include <Windows.h>

using namespace std;

Matrix::Matrix() {   
	size = 1;

	line = new Row[size];  
	for (int i = 0; i < size; i++)
		line[i] = Row(size);
}

Matrix::Matrix(int numerosity_l_c) {   
	size = (numerosity_l_c < 1) ? 1 : numerosity_l_c;    

	line = new Row[size];  
	for (int i = 0; i < size; i++)
		line[i] = Row(size);
}

Matrix::Matrix(int values_s, Row* value_l) {  
	size = values_s;
	line = value_l;
}

Matrix::~Matrix() { 
	for (int i = 0; i < size; i++)
		if (line[i].column != nullptr)
			delete[] line[i].column;    

	if (line != nullptr)
		delete[] line;  
}

Matrix& Matrix::operator =(Matrix& value) {   
	size = value.size;
	line = value.line;
	return *this;
}

Matrix::Row& Matrix::operator [](int line) {  
	return this->line[line];
}

Matrix::operator string() { 
	std::stringstream sout;
	sout << "\n\nПеретворення в літерний рядок: " << endl;

	sout << "Розмір: " << size << endl;
	sout << "Матриця: " << endl;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			sout << "   " << (*this)[i][j];
		sout << "\n";
	}

	return sout.str();
}

ostream& operator << (ostream& out, Matrix& value) {   
	out << "\nВиведені елементи матриці: " << value.size << "x" << value.size << "\n";
	for (int i = 0; i < value.size; i++) {
		for (int j = 0; j < value.size; j++)
			out << "   " << value[i][j];
		out << "\n";
	}
	return out;
}

istream& operator >> (istream& in, Matrix& value) {  
	cout << "\nВведення значень елементів матриці:" << "\n";
	for (int i = 0; i < value.size; i++) {
		for (int j = 0; j < value.size; j++) {
			std::cout << "Об'єкт: " << "[" << i << "]" << "[" << j << "] : ";
			in >> value[i][j];
		}
	}
	return in;
}

Matrix::Row::Row(int numerosity_column) {   
	column = new int[numerosity_column];   

	for (int i = 0; i < numerosity_column; i++)
		column[i] = 0;
}

int& Matrix::Row::operator [](int column) {  
	return this->column[column];
}