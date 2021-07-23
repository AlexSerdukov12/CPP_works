#include "Data.h"
#include "SortArr.h"
#include <iostream>

using namespace std;

void insert_number_to_array(int* arr, int size)
{
	int number;
	for (int i = 0; i < size;++i)
	{
		cout << "insert numer:";
		cin >> number;
		arr[i]=number;
	}
}

int main()
{
	/// //////////////////////////// get 2 arries/////////
	
	int* arr_1,* arr_2;
	int size_of_array_1, size_of_array_2;
	cout << " enter size of first array and of the second: ";
	cin >> size_of_array_1 >> size_of_array_2;
	arr_1 = new int[size_of_array_1];
	arr_2 = new int[size_of_array_2];
	insert_number_to_array(arr_1, size_of_array_1);
	insert_number_to_array(arr_2, size_of_array_2);
	SortArr<int> arr_first(arr_1, size_of_array_1);
	SortArr<int> arr_second(arr_2, size_of_array_2);
	if (arr_first == arr_second)
		cout << "arries is equal" << endl;
	else
		cout << "arries isnt equal" << endl;

	 ////////////////////////// get 2 dates/////////
	Data a[2];
	int day, month, year;
	cout << "Enter day,month,year:";
	cin >> day >> month >> year;
	try
	{
		a[0].set(day, month, year);
	}
	catch (const char* p)
	{
		cout << p << endl;
	}
	cout << "Enter day,month,year:";
	cin >> day >> month >> year;
	try
	{
		a[1].set(day, month, year);
	}
	catch (const char* p)
	{
		cout << p << endl;
	}

	SortArr<Data> data_1(a, 2);
	if (data_1.arr[0] == data_1.arr[1])
		cout << "dates is equal" << endl;
	else
		cout << "dates isnt equal" << endl;
	
	/////////////////////////////////////////////////
	
	/////////// now insert number////////////
	int number;
	cout << "insert number: ";
	cin >> number;
	data_1.arr[0] += (number);
	data_1.arr[1] += (number);
	arr_first.insert(number);
	arr_second.insert(number);
	
	cout << data_1;
	cout << arr_first;
	cout << arr_second;
	
	SortArr<int>::print_static();
	cout << endl;
	SortArr<Data>::print_static();
	cout << endl;
	
	delete[] arr_1, arr_2, a;
}
