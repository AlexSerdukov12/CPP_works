#pragma once
class MyMatrix
{
	float mat[2][2];
public:
	MyMatrix();
	MyMatrix(int a, int b, int c, int d);
	MyMatrix(const MyMatrix& mymatrix);
	~MyMatrix();
	void set(const MyMatrix& mymatrix);
	void set(int a, int b, int c, int d);
	void print() const;
	float det() const ;
	void add(const MyMatrix& m);
	void mult(const MyMatrix& m);
	bool is_equal(const MyMatrix& m) const;
};