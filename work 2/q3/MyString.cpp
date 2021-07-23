#define _CRT_SECURE_NO_WARNINGS
#include "MyString.h"
#include <iostream>
#include <string.h>

MyString::MyString()
{
	MyArray = NULL;
}
MyString::MyString(char* Array)
{	
	MyArray = new char[strlen(Array) + 1];
	strcpy(MyArray, Array);
}
MyString::MyString(const MyString& p)
{
	MyArray = new char[strlen(p.MyArray)+1];
	strcpy(MyArray, p.MyArray);

}
MyString::~MyString()
{
	delete[] MyArray;
}
void MyString::operator >> (char* newstring)
{
	if (MyArray != NULL)
	{
		delete[] MyArray;
		MyArray = new char[strlen(newstring) + 1];
		strcpy(MyArray, newstring);
	}
	else
	{
		MyArray = new char[strlen(newstring) + 1];
		strcpy(MyArray, newstring);
	}

}
MyString MyString::operator=(const MyString& p)
{
	p.MyArray;
	MyArray = new char[strlen(p.MyArray) + 1];
	strcpy(MyArray, p.MyArray);
	return *this;

}
MyString MyString::operator+=(MyString& myset)
{
	MyString C;
	C.MyArray = new char[strlen(MyArray) + strlen(myset.MyArray) + 1];
	strcpy(C.MyArray, MyArray);
	strcat(C.MyArray, myset.MyArray);
	return C;

}
void MyString::operator-=(char k)
{
	char* P_MyArray;
	int lengthOldString = strlen(MyArray);

	int lengthNewString = strlen(MyArray);
	for (int i = 0;i < lengthOldString + 1;++i)
	{
		if (MyArray[i] == k)
		{
			lengthNewString--;
		}
	}
	if (lengthNewString == lengthOldString)
	{
		return ;
	}
	P_MyArray = new char[lengthNewString+1];
	int p = 0;
	int j = 0;
	for (int i = 0;i < lengthOldString + 1;++i)
	{
		if (MyArray[i] != k)
		{
			if (i == lengthOldString)
			{
				j = 0;
			}

			P_MyArray[p] = MyArray[j];
			p++;
		}
		j++;
		if (j == lengthNewString + 1)
		{
			P_MyArray[p] = '\0';
			break;
		}	
	}
	delete[] MyArray;
	MyArray = new char[lengthNewString + 1];
	strcpy(MyArray, P_MyArray);
	delete[] P_MyArray;

}
void MyString::operator*(int  Multi)
{
	int i = 0, j = 0,  k = 0;
	char* P_MyArray = new char[strlen(MyArray) + 1];
	strcpy(P_MyArray, MyArray);
	delete[] MyArray;
	MyArray = new char[strlen(P_MyArray)* Multi +1 ];

	for (j;j < strlen(P_MyArray) * Multi+1;++j)
	{
		if (k == strlen(P_MyArray))
			k = 0;;

		MyArray[i] = P_MyArray[k];
		i++;
		k++;
		if (i == strlen(P_MyArray) * Multi )
		{
			MyArray[i] = '\0';
			break;

		}
	}
	delete[] P_MyArray;

}
char MyString::operator[](int choosen)const
{
	return MyArray[choosen];
}
int MyString::total_length()
{
	int size = 0;
	size += strlen(MyArray);
	return size;
}
int MyString::total_digits()
{
	int Digit = 0;
	for (int i = 0; i < strlen(MyArray);++i)
	{
		if (MyArray[i] >= '0' && MyArray[i] <= '9')
		{
			Digit++;
		}
	}
	return Digit;
}
