#include "MySet.h"
#include <iostream>
using namespace std;

ostream& operator<<(ostream& os, const MySet& myset);

int main()
{
	int* Array1,
		* Array2;
	int size1, size2, k, CounterHowMuchNumbersLeft, NumberToSearch;
	///////////////////////////////////////////// array1///////////

	cout << "Enter size of A: ";
	cin >> size1;
	/////////////////new array1
	Array1 = new int[size1];
	CounterHowMuchNumbersLeft = size1;
	/////////////////////get numbers into array1
	for (int i = 0;i < size1;++i)
	{
		cout << "insert number , left: " << CounterHowMuchNumbersLeft << " numbers to fill" << endl;
		cin >> Array1[i];

		CounterHowMuchNumbersLeft--;
	}
	///////////////////////////////////////////// array2///////////
	cout << "Enter size of B: ";
	cin >> size2;
	/////////////////new array2
	Array2 = new int[size2];
	CounterHowMuchNumbersLeft = size2;
	/////////////////////get numbers into array2

	for (int i = 0;i < size2;++i)
	{
		cout << "insert number , left: " << CounterHowMuchNumbersLeft << " numbers to fill" << endl;
		cin >> Array2[i];

		CounterHowMuchNumbersLeft--;
	}
	////////////////
	MySet M1(Array1, size1);
	MySet M2(Array2, size2);
	////////////
	cout << "enter k :";
	cin >> k;
	cout << endl;
	MySet M3 = (M1 + M2) * k;
	cout << M3;
	//////////////////total sum
	int Sum = 0;
	Sum += M1.total_sum();
	Sum += M2.total_sum();
	Sum += M3.total_sum();
	cout << "Total sum of elements is " << Sum << endl;

	///////////////////////////////
	cout << "enter k :";
	cin >> k;
	M3 = (M1 - M2) * k;
	cout << M3;
	





	///////////////////////////////////search
	cout << "enter a number to search:";
	cin >> NumberToSearch;
	cout << endl;
	if (M1 && NumberToSearch)
		cout << NumberToSearch << " in 1" << endl;
	else
		cout << NumberToSearch << " is not in 1" << endl;
	if (M2 && NumberToSearch)
		cout << NumberToSearch << " in 2" << endl;
	else
		cout << NumberToSearch << " is not in 2" << endl;
	if (M3 && NumberToSearch)
		cout << NumberToSearch << " in 3" << endl;
	else
		cout << NumberToSearch << " is not in 3" << endl;
	/////////////////////////search over




	//////////////////total sum
	Sum = 0;
	Sum += M1.total_sum();
	Sum += M2.total_sum();
	Sum += M3.total_sum();

	cout << "Total sum of elements is " << Sum << endl;

	//////////////////////////////FREEEEEEEEEEEEEEEEEEEEEEEEEEE

	delete[] Array1;
	delete[] Array2;
	
	return 0;
}



ostream& operator<<(ostream& os, const MySet& myset)
{
	for (int i = 0; i < myset.M_size; ++i)
	{
		os << myset.MyArray[i] << " ";
	}
	os << endl;
	return os;
}
