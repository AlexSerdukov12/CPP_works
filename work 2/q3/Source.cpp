#include "MyString.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const MyString& p);




int main()
{
	char FirstString[30], SecondString[30], digit;
	cin >> FirstString >> SecondString;
	MyString A(FirstString);
	MyString B(SecondString);
	
	MyString C=A += B;
	cout << "String A : " << A << endl;
	cout << "String B : " << B << endl;
	cout << "String C : " << C << endl;

	//////////////////////////////////////////////////total length
	int sum = 0;
	sum = sum + A.total_length();
	sum = sum + B.total_length();
	sum = sum + C.total_length();

	cout << "Total length = " << sum << endl;
	//////////////////////////////////////////////////total digits
	int Digit = 0;
	Digit = Digit + A.total_digits();
	Digit = Digit + B.total_digits();
	Digit = Digit + C.total_digits();
	cout << "Total Digits = "<< Digit << endl;
	//////////////////////////////////////////////////
	cout << "Enter New C String : ";
	cin >> FirstString;
	C >> FirstString;
	////////////////////////////////////////////////print
	cout << "String A : " << A << endl;
	cout << "String B : " << B << endl;
	cout << "String C : " << C << endl;

	//////////////////////////////////////////////////total length
	sum = 0;
	sum = sum + A.total_length();
	sum = sum + B.total_length();
	sum = sum + C.total_length();

	cout << "Total length = " << sum << endl;
	//////////////////////////////////////////////////total digits
	 Digit = 0;
	Digit = Digit + A.total_digits();
	Digit = Digit + B.total_digits();
	Digit = Digit + C.total_digits();
	cout << "Total Digits = " << Digit << endl;
	/////////////////////////////////////////insert k;
	int k;
	cout << "Insert K : ";
	cin >> k;
	char remove=C[k];
	A -= remove;
	B -= remove;
	C -= remove;

	cout << A << endl;
	cout << B << endl;
	cout << C << endl;
	//////////////////////////////////////////////////total length
	sum = 0;
	sum = sum + A.total_length();
	sum = sum + B.total_length();
	sum = sum + C.total_length();

	cout << "Total length = " << sum << endl;
	//////////////////////////////////////////////////total digits
	Digit = 0;
	Digit = Digit + A.total_digits();
	Digit = Digit + B.total_digits();
	Digit = Digit + C.total_digits();
	cout << "Total Digits = " << Digit << endl;

	int multi;
	cout << "Enter multi: ";
	cin >> multi;
	A* multi;
	B* multi;
	C* multi;


	cout << "String A : " << A << endl;
	cout << "String B : " << B << endl;
	cout << "String C : " << C << endl;
	//////////////////////////////////////////////////total length
	sum = 0;
	sum = sum + A.total_length();
	sum = sum + B.total_length();
	sum = sum + C.total_length();

	cout << "Total length = " << sum << endl;
	//////////////////////////////////////////////////total digits
	Digit = 0;
	Digit = Digit + A.total_digits();
	Digit = Digit + B.total_digits();
	Digit = Digit + C.total_digits();
	cout << "Total Digits = " << Digit << endl;
	return 0;

}
ostream& operator<<(ostream& os, const MyString& p)
{
	os << p.MyArray;
	return os;
}

