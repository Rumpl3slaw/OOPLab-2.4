#pragma once
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Matrix {     
	class Row; 

	int size;   
	Row* line;  

	class Row {  
	public:
		int* column;   

		void Setcolumn(int* value) { column = value; }  
		int* Getcolumn() const { return column; }       

		Row(int numerosity_column = 1);  
		int& operator [](int);       
	};
public:
	Matrix();         
	Matrix(int);         
	Matrix(int, Row*);  
	~Matrix();  

	void Setsize(int value) { size = value; }	 
	void Setline(Row* value) { line = value; }   

	int Getsize() const { return size; }       
	Row* Getline() const { return line; }      

	Row& operator [](int line);    
	Matrix& operator =(Matrix&);     
	operator string();          

	friend ostream& operator << (ostream&, Matrix&);  
	friend istream& operator >> (istream&, Matrix&);	

	friend void operator +(Matrix&, Matrix&);   
	double CalcnormMatrices();            


	friend bool operator < (Matrix&, Matrix&);   
	friend bool operator > (Matrix&, Matrix&);    

	friend bool operator<= (Matrix&, Matrix&);    
	friend bool operator >= (Matrix&, Matrix&);    

	friend bool operator == (Matrix&, Matrix&);    
	friend bool operator != (Matrix&, Matrix&);   
};