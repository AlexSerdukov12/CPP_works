#pragma once
#include <string.h>
#include <iostream>


using namespace std;
class MyString
{

	char* MyArray;

public:
	MyString();
	MyString(char* Array);
	MyString(const MyString& p);
	~MyString();
	MyString operator=(const MyString& p);
	friend ostream& operator<<(ostream& os, const MyString& myset);
	void operator >> (char* newstring);
	MyString operator+=(MyString& myset);
	void operator-=(char k);
	void operator*(int  Multi);
	char operator[](int choosen)const;
	int total_length();
	int total_digits();




};

