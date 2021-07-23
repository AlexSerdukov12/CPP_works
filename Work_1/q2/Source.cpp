#include <iostream>
#include "MyMatrix.h"
using namespace std;

void CheckEqual(const MyMatrix& m1, const MyMatrix& m2, const MyMatrix& m3);
void PrintDet(const MyMatrix& m1, const MyMatrix& m2, const MyMatrix& m3);
void PrintAXBPlusC(const MyMatrix& m1, const  MyMatrix& m2, const  MyMatrix& m3);
void DeleteMatrixB(const MyMatrix& m2);


int main()
{
	float a, b, c, d;
	cout << "enter first matrix ";
	cin >> a >> b >> c >> d;
	MyMatrix m1(a, b, c, d);
	cout << "enter second matrix ";
	cin >> a >> b >> c >> d;
	MyMatrix m2(a, b, c, d);
	cout << "enter third matrix ";
	cin >> a >> b >> c >> d;
	MyMatrix m3(a, b, c, d);
	CheckEqual(m1, m2, m3);
	PrintDet(m1, m2, m3);
	PrintAXBPlusC(m1, m2, m3);
	DeleteMatrixB(m2);
	cout << "enter new second  matrix " << endl;;
	cin >> a >> b >> c >> d;
	MyMatrix m2new(a, b, c, d);
	PrintAXBPlusC(m1, m2new, m3);

	return 0;
}

void CheckEqual(const MyMatrix& m1, const MyMatrix& m2, const MyMatrix& m3 )
{
	if (m1.is_equal(m2))
	{
		cout << "matrix 1 and 2 is qeual" << endl;
	}
	if (m1.is_equal(m3))
	{
		cout << "matrix 1 and 3 is qeual" << endl;
	}
	if (m2.is_equal(m3))
	{
		cout << "matrix 2 and 3 is qeual" << endl;
	}

}
void PrintDet(const MyMatrix& m1, const MyMatrix& m2, const MyMatrix& m3)
{
	float Det;
	Det = m1.det();
	cout << "Det of first matrix is = " << Det << endl;
	Det = m2.det();
	cout << "Det of second matrix is = " << Det << endl;
	Det = m3.det();
	cout << "Det of third matrix is = " << Det << endl;
}
void PrintAXBPlusC(const MyMatrix& m1, const MyMatrix& m2, const MyMatrix& m3)
{
	MyMatrix m4(m1);
	m4.mult(m2);
	m4.add(m3);
	cout << "AXB+C " << endl;
	m4.print();
	m4.~MyMatrix();
	
}
void DeleteMatrixB(const MyMatrix& m2)
{
	m2.~MyMatrix();
}


