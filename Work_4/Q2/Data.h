#pragma once
#include<iostream>
using namespace std;
class Data
{
protected:
	int day, month, year;
public:
	Data();
	Data(int day, int month, int year);
	Data(const Data& p);
	void set(int day, int month, int year);
	void print();
	~Data();
	bool operator==(const Data& b);
	Data operator=(const Data& a);
	friend ostream& operator<<(ostream& out, const  Data& p)
	{
		out << p.day << "/" << p.month << "/" << p.year << endl;;
		return out;
	}
	bool operator <= (const Data& a); 	////// àåôøàèåø <=
	bool operator != (const Data& a); 	////// àåôøàèåø !=
	void operator +=(int d);
	bool end_of_month()const;
	void operator ++();

};

