#include "Data.h"
#include <iostream>
using namespace std;

Data::Data()
{
	this->day = 29;
	this->month = 1;
	this->year = 2000;
}
Data::Data(int day, int month, int year)
{
	
	this->day = day;
	this->month = month;
	this->year = year;
}
Data::~Data()
{

}
Data::Data(const Data& p)
{
	this->day = p.day;
	this->month = p.month;
	this->year = p.year;
}
void Data::print()
{
	cout << day << "/" << month << "/" << year << endl;
}
bool Data::operator==(const Data& b)
{
	if (year == b.year && month == b.month && day == b.day)
		return true;
	return false;
}
Data Data::operator=(const Data& a)
{
	year = a.year;
	month = a.month;
	day = a.day;
	return *this;
}
void Data::set(int day, int month, int year)
{
	if (year < 1)
		throw("Bad year");
	if(month>12 || month<1)
		throw("Bad month");

	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
	{
		if (day >= 31 || day < 1)
			throw("bad day");
	}
	if (month == 4 || month == 6 || month == 9 || month == 11)
	{
		if (day > 30 || day < 1)
			throw("bad day");
	}
	if (year % 4 != 0)
	{
		if (day > 28 || day < 1)
			throw("bad day");
	}
	if (year % 100 != 0)
	{
		if (day > 29 || day < 1)
			throw("bad day");
	}
	if (year % 400 != 0)
	{

		if (day > 28 || day < 1)
			throw("bad day");
	}

	this->month = month;
	this->year = year;
	this->day = day;
}

bool Data::operator <= (const Data& a)
{
	return false;
}
bool Data::operator != (const Data& a)
{
	if (this->year == a.year)
	{
		if (this->month == a.month)
		{
			if (this->day == a.day)
				return false;
		}
	}
	return true;
}
void Data::operator +=(int d)
{
	while (d > 0)
	{
		this->operator++();
		d--;
	}

}
bool Data::end_of_month()const
{
	if (month == 1 || month == 3 || month == 5 ||
		month == 7 || month == 8 || month == 10||
		month == 12)
		return (day == 31);
	if (month == 4 || month == 6 || month == 9 ||
		month == 11)
		return (day == 30);
	//month==2
	if (year % 4 != 0)
		return (day == 28);
	if (year % 100 != 0)
		return (day == 29);
	if (year % 400 != 0)
		return (day == 28);
	return (day == 29);
}
void Data::operator ++()
{
	if (end_of_month())
	{
		day = 1;
		if (month == 12)
			year++;
		else
		month = (month % 12) + 1;
	}
	else
		day++;
}

