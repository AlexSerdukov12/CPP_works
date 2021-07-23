#define _CRT_SECURE_NO_WARNINGS
#include "Winners.h"
#include "string.h"
#include <iostream>

using namespace std;
Winners::Winners()
{
	first_name = NULL;
	second_name = NULL;
	third_name = NULL;
	first_score = 0;
	second_score = 0;
	third_score = 0;
}
Winners::Winners(const Winners& copy)
{
	if (copy.first_name != NULL)
	{
		
		first_name = new char[strlen(copy.first_name) + 1];
		strcpy(first_name, copy.first_name);
		first_score = copy.first_score;
	}
	else
		first_name = NULL;

	if (copy.second_name != NULL)
	{
		second_name = new char[strlen(copy.second_name) + 1];
		strcpy(second_name, copy.second_name);
		second_score = copy.second_score;
	}
	else
		first_name = NULL;

	if (copy.third_name != NULL)
	{
		third_name = new char[strlen(copy.third_name) + 1];
		strcpy(third_name, copy.third_name);
		third_score = copy.third_score;
	}
	else
		first_name = NULL;
}
Winners::~Winners()
{
	if (first_name != NULL)
	{
		delete[] first_name;
		first_name = NULL;
	}

	if (first_name != NULL)
	{
		delete[] second_name;
		second_name = NULL;

	}

	if (first_name != NULL)
	{
		delete[] third_name;
		third_name = NULL;

	}
}
void Winners::Print()const
{
	if (first_score >= second_score && first_score >= third_score)
	{
		cout << "First Place is - " << first_name << " grade = " << first_score << endl;
		if (second_score >= third_score)
		{
			cout << "Second Place is - " << second_name << " grade = " << second_score << endl;
			cout << "Third Place is - " << third_name << " grade = " << third_score << endl;
		}
		else
		{
			cout << "Second Place is - " << third_name << " grade = " << third_score << endl;
			cout << "Third Place is - " << second_name << " grade = " << second_score << endl;
		}

	}
	else if (second_score >= first_score && second_score >= third_score)
	{
		cout << "First Place is - " << second_name << " grade = " << second_score << endl;
		if (first_score >= third_score)
		{
			cout << "Second Place is - " << first_name << " grade = " << first_score << endl;
			cout << "Third Place is - " << third_name << " grade = " << third_score << endl;
		}
		else
		{
			cout << "Second Place is - " << third_name << " grade = " << third_score << endl;
			cout << "Third Place is - " << first_name << " grade = " << first_score << endl;
		}
	}
	else if (third_score >= first_score && third_score >= second_score)
	{
		cout << "First Place is - " << third_name << " grade = " << third_score << endl;
		if (first_score >= second_score)
		{
			cout << "Second Place is - " << first_name << " grade = " << first_score << endl;
			cout << "Third Place is - " << second_name << " grade = " << second_score << endl;
		}
		else
		{
			cout << "Second Place is - " << second_name << " grade = " << second_score << endl;
			cout << "Third Place is - " << first_name << " grade = " << first_score << endl;
		}
	}
}
Winners::Winners(char* first_name1, char* second_name2, char* third_name3, int grade1, int grade2, int grade3)
{
	first_name = new char[strlen(first_name1) + 1];
	strcpy(first_name, first_name1);

	second_name = new char[strlen(second_name2) + 1];
	strcpy(second_name, second_name2);

	third_name = new char[strlen(third_name3) + 1];
	strcpy(third_name, third_name3);

	first_score = grade1;
	second_score = grade2;
	third_score = grade3;
}
void Winners::UpdateFunction(char* name, int grade)
{
	int ReturnMin = 0;
	///////////update exist grade//////////
	if (strcmp(first_name,name)==0)
	{
		if (first_score < grade)
		{
			first_score = grade;
		}
	}
	else if (strcmp(second_name, name) == 0)

	{
		if (second_score < grade)
		{
			second_score = grade;
		}
	}
	else if (strcmp(third_name, name) == 0)
	{
		if (third_score < grade)
		{
			third_score = grade;
		}
	}
	/////////change the lowest student with new name////////
	else
	{
		ReturnMin = SearchMin(first_score, second_score, third_score);

		if (grade > ReturnMin)
		{
			if (ReturnMin == first_score)
			{

				delete[] first_name;
				first_name = new char[strlen(name) + 1];
				strcpy(first_name, name);
				first_score = grade;
			}
			else if (ReturnMin == second_score)
			{
				delete[] second_name;
				second_name = new char[strlen(name) + 1];
				strcpy(second_name, name);
				second_score = grade;
			}
			else if (ReturnMin == third_score)
			{
				delete[] third_name;
				third_name = new char[strlen(name) + 1];
				strcpy(third_name, name);
				third_score = grade;
			}
		}
	}
}
int Winners::SearchMin(int a, int b, int c)
{
	if (a <= b && a <= c)
		return a;
	if (b <= a && b <= c)
		return b;
	if (c <= a && c <= b)
		return c;
	return 0;
}


