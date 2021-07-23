#include "MyMatrix.h"
#include<iostream>
using namespace std;

MyMatrix::MyMatrix()
{
	float mat[2][2] = { {0} }; 
}
MyMatrix::MyMatrix(int a, int b, int c, int d)
{
	this->mat[0][0] = a;
	this->mat[0][1] = b;
	this->mat[1][0] = c;
	this->mat[1][1] = d;
}
MyMatrix::MyMatrix(const MyMatrix& mymatrix)
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			this->mat[i][j] = mymatrix.mat[i][j];
		}
	}
}	
MyMatrix::~MyMatrix()
{
}
void MyMatrix::set(const MyMatrix& mymatrix)
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			this->mat[i][j] = mymatrix.mat[i][j];
		}
	}
}
void MyMatrix::set(int a, int b, int c, int d)
{
	this->mat[0][0] = a;
	this->mat[0][1] = b;
	this->mat[1][0] = c;
	this->mat[1][1] = d;
}
void MyMatrix::print() const
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			cout << mat[i][j]<<"   ";
		}
		cout << endl;
	}
	cout << endl;
}
float MyMatrix::det() const 
{
	float Det; 
	Det =( (this->mat[0][0] * this->mat[1][1]) - (this->mat[0][1] * this->mat[1][0])) ;
	return Det;
}
void MyMatrix::add(const MyMatrix& m)
{
	this->mat[0][0] += m.mat[0][0];
	this->mat[0][1] += m.mat[0][1];
	this->mat[1][0] += m.mat[1][0];
	this->mat[1][1] += m.mat[1][1];
}
void MyMatrix::mult(const MyMatrix& m)
{
	float a, b, c, d;
	a = (this->mat[0][0] * m.mat[0][0]) + (this->mat[0][1] * m.mat[1][0]);
	b = (this->mat[0][0] * m.mat[0][1]) + (this->mat[0][1] * m.mat[1][1]);
	c = (this->mat[1][0] * m.mat[0][0]) + (this->mat[1][1] * m.mat[1][0]);
	d = (this->mat[1][0] * m.mat[0][1]) + (this->mat[1][1] * m.mat[1][1]);
	this->mat[0][0] = a;
	this->mat[0][1] = b;
	this->mat[1][0] = c;
	this->mat[1][1] = d;

}
bool MyMatrix::is_equal(const MyMatrix& m) const
{
	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			if (this->mat[i][j] == m.mat[i][j])
			{
				////HELLO FROM CORENTIN////
			}
			else
				return false;
		}
	}
	return true;
}




