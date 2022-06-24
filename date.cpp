#include "stdafx.h"
#include<ctype.h>
#include<vector>
#include<fstream>
#include<iostream>
#include"date.h"


using namespace std;



date::date(int d, int m, int y)
{
	setDate(d, m, y);
}

bool isLeapyear(int year)
{
	int r = year % 33;
	return r == 1 || r == 5 || r == 9 || r == 13 || r == 17 || r == 22 || r == 26 || r == 30;
}
int  daysOfmonth(int m, int y)
{
	if (m < 7)
		return 31;
	else if (m < 12)
		return 30;
	else if (m == 12)
		return isLeapyear(y) ? 30 : 29;

}
void date::setDate(int d, int m, int y)
{
	string msg = "\n\n\t** This date is incorrect";
	
	day = d;
	month = m;
	year = y;
}

int date::getDay() { return day; }
int date::getMonth() { return month; }
int date::getYear() { return year; }

void date::printDate()
{
	std::cout << day << '/' << month << '/' << year << std::endl;
}



int daysCompare(date d1, date d2) {

	if (d1.getYear()>d2.getYear())
		return 1;
	else if (d1.getYear()<d2.getYear())
		return -1;
	else
	{
		if (d1.getMonth()>d2.getMonth())
			return 1;
		else if (d1.getMonth()<d2.getMonth())
			return -1;
		else
		{
			if (d1.getDay()>d2.getDay())
				return 1;
			else if (d1.getDay()<d2.getDay())
				return -1;
			else
				return 0;
		}

	}
}

void date::getdata_date(int d, int m, int y) {
	cout << "\n\t  Day:";
	cin >> d;
	cout << "\n\t  Month:";
	cin >> m;
	cout << "\n\t  Year:";
	cin >> y;

	setDate(d, m, y);
}