#include "stdafx.h"
#include<iostream>
#include<string>
#include<ctype.h>
#include<stdexcept>
#include"person.h"

using namespace std;


person::person(string ID, string name, string family, string day, string month, string year, string nationalnum) {
	try {
		set_ID(ID);
		set_name(name);
		set_family(family);
		set_birthday(day);
		set_birthmonth(month);
		set_birthyear(year);
		set_nationalnum(nationalnum);
	}
	catch (string msg) { cout << ""; }
}


void person::test_word(string w) {
	string msg = "\n\t** You can only letters !";
	for (int i = 0;i < w.size();i++)
		if (!isalpha(w[i]))
			throw msg;
}
void person::test_num( string n) {
	int x = 0;

	string msg1 = "\n\t** You can only number ! Try agian";
	string msg2 = "\n\t** The number of characters is incottect . Try agian ";
	
	
	for (int k = 0;k < n.length();k++)
		if (isalpha(n[k]))
				throw msg1;
		

}

void person::set_ID(string ID) {
	this->ID = ID;
}
void person::set_name(string name) {

	test_word(name);

	this->name = name;
}
void person::set_family(string family) {

	test_word(family);

	this->family = family;
}
void person::set_birthday(string day) {
	string msg1 = "\n\t** You can only number ! Try agian";

	for (int k = 0;k < day.length();k++)
		for (int i = 58, j = 33;i <= 126, j <= 47;i++, j++)
		{
			if (day[k] == i || day[k] == j)
				throw msg1;
		}
	this->day = day;

}
void person::set_birthmonth(string month) {
	string msg1 = "\n\t** You can only number ! Try agian";

	for (int k = 0;k < month.length();k++)
		for (int i = 58, j = 33;i <= 126, j <= 47;i++, j++)
		{
			if (month[k] == i || month[k] == j)
				throw msg1;
		}
	this->month = month;


}
void person::set_birthyear(string year) {
	string msg1 = "\n\t** You can only number ! Try agian";

	for (int k = 0;k < year.length();k++)
		for (int i = 58, j = 33;i <= 126, j <= 47;i++, j++)
		{
			if (year[k] == i || year[k] == j)
				throw msg1;
		}
	this->year = year;

}
void person::set_nationalnum(string nationalnum) {
	
		test_num(nationalnum);

	this->nationalnum = nationalnum;
}

string person::get_ID() { return ID; }
string person::get_name() { return name; }
string person::get_family() { return family; }
string person::get_day() { return day; }
string person::get_month() { return month; }
string person::get_year() { return year; }
string person::get_nationalnum() { return nationalnum; }


