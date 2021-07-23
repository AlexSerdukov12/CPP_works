#include "MySet.h"
MySet::MySet()
{
	MyArray = NULL;
	M_size = 0;
}
MySet::MySet(int* myarray, int size)
{
	M_size = size;
	MyArray = new int[M_size];
	for (int i = 0; i < M_size; ++i)
		MyArray[i] = (myarray)[i];

}
MySet::MySet(const MySet& myset)
{
	M_size = myset.M_size;
	MyArray = new int[M_size];
	for (int i = 0; i < M_size; ++i)
		MyArray[i] = myset.MyArray[i];
}

MySet::	~MySet()
{
	delete[] MyArray;
}

MySet MySet::operator=(const MySet& p)
{
	if (this != &p)
	{
		M_size = p.M_size;
		delete[] MyArray;
		MyArray = new int[p.M_size];
		for (int i = 0;i < p.M_size; ++i)
			MyArray[i] = p.MyArray[i];
	}
	return *this;
}

MySet MySet::operator+(const MySet& p)
{
	MySet NewP;
	NewP.M_size = M_size;
	int AddNewNumberToU = 0;
	int Temp = M_size;
	for (int j = 0; j < p.M_size; ++j)
	{
		for (int i = 0; i < M_size; ++i)
			{
			if (p.MyArray[j] != MyArray[i])
			{
				AddNewNumberToU++;
				if (AddNewNumberToU == Temp)
				{
					NewP.M_size++;
					AddNewNumberToU = 0;
				}

			}
		}
		AddNewNumberToU = 0;
	}
	int WhereToInsertNewNumbers = NewP.M_size;
	AddNewNumberToU = 0;

	NewP.MyArray = new int[NewP.M_size];
	int  k = 0;
	for ( k ; k < M_size; ++k)
	{
		NewP.MyArray[k] = MyArray[k];
	}

	int temp = M_size;
	for (int j = 0; j < p.M_size; ++j)

	{
		for (int i = 0; i < M_size; ++i)
		{
			if (p.MyArray[j] != MyArray[i])
			{
				AddNewNumberToU++;
				if (AddNewNumberToU == Temp)
				{
					NewP.MyArray[k] = p.MyArray[j];
					k++;

				}

			}
		}
		AddNewNumberToU = 0;
	}

	return NewP;
}






MySet MySet::operator-(const MySet& p)
{
	MySet NewP;
	NewP.M_size = M_size;
	for (int i = 0; i < M_size; ++i)
	{
		for (int j = 0; j < p.M_size; ++j)
		{
			if (MyArray[i] == p.MyArray[j])
			{
					NewP.M_size--;
			}
		}
	}
	NewP.MyArray = new int[NewP.M_size];
	int counter = 0;
	int Temp = p.M_size;
	int k = 0;
	for (int i = 0; i < M_size; ++i)
	{
		for (int j = 0; j < p.M_size; ++j)
		{
			if (MyArray[i] != p.MyArray[j])
			{
				counter++;
				if (counter == Temp)
				{
					NewP.MyArray[k] = MyArray[i];
						k++;
					counter = 0;
				}
				
			}
		}
		counter = 0;
	}
	return NewP;
}



MySet MySet::operator*(int Number)
{

	for (int i = 0; i < M_size; ++i)
		MyArray[i] *= Number;

	return *this;

}

bool MySet::operator&&(int CheckIfNumberExists)
{
	for (int i = 0;i < M_size; ++i)
	{
		if (MyArray[i] == CheckIfNumberExists)
			return true;
	}
	return false;
}
int MySet::total_sum()
{
	int Sum = 0;
	for (int i = 0; i < M_size;++i)
	{
		Sum += MyArray[i];
	}
	return Sum;
}


