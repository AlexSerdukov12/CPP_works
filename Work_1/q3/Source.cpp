#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Winners.h"
using namespace std;

void main()
{
	char firstname[30], secondname[30], thirdname[30], NewName[30];
	int firstgrade, secondgrade, thirdgrade, NewGrade;

	cout << "enter first name then the second and the last name" << endl;
	cin >> firstname >> secondname >> thirdname;

	cout << "enter first grade then the second and the last grade" << endl;
	cin >> firstgrade >> secondgrade >> thirdgrade;


	Winners p1(firstname, secondname, thirdname, firstgrade, secondgrade, thirdgrade);

	p1.Print();

	cout << "enter name and new grade" << endl;
	cin >> NewName >> NewGrade;

	p1.UpdateFunction(NewName, NewGrade);

	p1.Print();

	cout << "enter name and new grade" << endl;
	cin >> NewName >> NewGrade;

	p1.UpdateFunction(NewName, NewGrade);

	p1.Print();

	p1.~Winners();

}

