#define _CRT_SECURE_NO_WARNINGS

#pragma once
class Winners
{
	char* first_name;
	char* second_name;
	char* third_name;

	int first_score, second_score, third_score;
public:
	Winners();
	Winners(const Winners& copy);
	Winners(char* first_name, char* second_name, char* third_name, int FirstGrade, int SecondGrade, int ThirdGrade);
	~Winners();
	void Print()const;
	void UpdateFunction(char* name, int grade);
	int SearchMin(int a, int b, int  c);

};

