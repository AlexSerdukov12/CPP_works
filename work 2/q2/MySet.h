#pragma once
#include <iostream>
using namespace std;

class MySet
{
	int* MyArray;
	int M_size;
public:
	MySet();
	MySet(int* myarray, int size);
	MySet(const MySet& myset);
	~MySet();
	MySet operator=(const MySet& myset);
	friend ostream& operator<<(ostream& os, const MySet& myset);
	MySet operator+(const MySet& myset);
	MySet operator-(const MySet& myset);
	MySet operator*(int  myset);
	bool operator&&(int myset);
	int total_sum();

};
