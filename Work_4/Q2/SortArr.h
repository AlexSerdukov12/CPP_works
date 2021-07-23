#pragma once
#include <iostream>
using namespace std;
template<class T>
class SortArr
{
public:
	T* arr;
	int size;
	static int sum;
	static int number_of_objects;

public:
	SortArr();
	SortArr(T arr1[],int size);
	SortArr(const SortArr<T>& p);
	~SortArr();
	SortArr<T>& operator=(const SortArr<T>& p);
	bool operator==(const SortArr<T>& b);
	bool insert(const int get);
	friend ostream& operator<<(ostream& out, const SortArr<T>& p)
	{
		for (int i = 0; i < p.size; ++i)
			out << p.arr[i] << " ";
		out << endl;
		return out;
	}
	void static print_static()
	{
		cout << "Sum=:" << sum << endl;
		cout << "number_of_objects=:" << number_of_objects << endl;

	}
//print static
	static int get_sum() { return sum; };
	static int get_number_of_objects() { return number_of_objects; };

};


template <class  T> int SortArr<T>::number_of_objects = 0;

template <class T> int SortArr<T>::sum = 0;

template<class T>
SortArr<T>::SortArr()
{
	arr = NULL;
	size = 0;
	number_of_objects++;
}

template<class T>
SortArr<T>::SortArr(T arr1[], int size)
{
	bool flag = true;
	for (int i = 0;i < size - 1;++i)
	{
		if (arr1[i + 1] <= arr1[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
		this->size = size;

	else
		this->size = 1;

	arr = new T[this->size];
	for (int i = 0;i < this->size;++i)
	{
		this->arr[i] = arr1[i];
	}
	number_of_objects++;
	sum += this->size;;
}

template<class T>
SortArr<T>::SortArr(const SortArr<T>& p)
{
	
		this->size = p.size;
		arr = new T[p.size];
		for (int i = 0; i < this->size;++i)
		{
			this->arr[i] = p.arr[i];
		}
		this->sum += p.sum;
		number_of_objects++;
	
}

template<class T>
SortArr<T>::~SortArr()
{
	sum -= this->size;
	number_of_objects--;
	delete[] arr;
}

template<class T>
bool SortArr<T>::operator==(const SortArr<T>& b)
{

	for (int i = 0;i < this->size;++i)
	{
		if (this->arr[i] != b.arr[i])
		{
			return false;
		}
	}
	return true;
}

template<class T>
SortArr<T>& SortArr<T>::operator=(const SortArr<T>& p)
{
	if (this != &p)
	{
		size = p.size;
		delete[] arr;
		arr = new T[p.size];
		for (int i = 0;i < p.size; ++i)
			arr[i] = p.arr[i];
	}
	return *this;
}

template<class T>
bool SortArr<T>::insert(const int get)
{
	bool flag = false;
	T* temp = NULL;
	for (int i = 0; i < size; ++i)
	{
		if (arr[i] == get)
		{
			flag = true; ///////////number is exist , do nothing!!!
			break;
		}
	}

	if (flag)
	{
		return false;
	}
	else
	{
		size++;
		temp = new T[size];
			for (int i = 0; i < size - 1;++i)
			{
				if (arr[i] < get && get < arr[i + 1])
				{
					temp[i] = arr[i];
					temp[i + 1] = get;
					temp[i + 2] = arr[i+1];
					i += 2;
				}
				else
				{
					temp[i] = arr[i];
				}

			}
			
		delete arr;
		arr = new T[size];
		for (int i = 0;i < size;++i)
		{
			arr[i] = temp[i];
		}
		delete[] temp;
		sum++;
		return true;
	}
}
	

