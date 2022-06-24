#include "stdafx.h"
#include<iostream>
#include<string>
#include<ctype.h>
#include<vector>
#include<fstream>
#include<iostream>
#include<iomanip>
#include"borrow.h"
#include"date.h"


using namespace std;

borrow::borrow(std::string writ, std::string member, int dB, int mB, int yB, int dD, int mD, int yD) {

	set_memberID(member);
	set_writID(writ);

	set_dateB(dB, mB, yB);
	set_dateD(dD, mD, yD);
}

void borrow::set_writID(string writ) {
	writID = writ;
}
void borrow::set_memberID(string member) {
	memberID = member;
}
void borrow::set_dateB(int d, int m, int y) {
	
	dateB.setDate(d, m, y);
	
}
void borrow::set_dateD(int d, int m, int y) {
	
	dateD.setDate(d, m, y);

}

date borrow::getdateborrow() {
	return dateD;
}
void borrow::setdate(date d) {
	try {
		dateD.setDate(d.getDay(), d.getMonth(), d.getYear());
	}
	catch (string msg) { cout <<msg; }
}

string borrow::get_writID() { return writID; }
string borrow::get_memberID() { return memberID; }

int borrow::getdayB() { return dateB.getDay(); }
int borrow::getmonthB() { return dateB.getMonth(); }
int borrow::getyearB() { return dateB.getYear(); }

int borrow::getdayD() { return dateD.getDay(); }
int borrow::getmonthD() { return dateD.getMonth(); }
int borrow::getyearD() { return dateD.getYear(); }


bool isLeapYear(int year)
{
	int r = year % 33;
	return r == 1 || r == 5 || r == 9 || r == 13 || r == 17 || r == 22 || r == 26 || r == 30;
}
int  daysOfMonth(int m, int y)
{
	if (m < 7)
		return 31;
	else if (m < 12)
		return 30;
	else if (m == 12)
		return isLeapYear(y) ? 30 : 29;

}

fstream  &operator <<(fstream &out, borrow &b) {
	out << b.get_writID() << "," << b.get_memberID() << "," << b.getyearB() << "," << setfill('0') << setw(2) << b.getmonthB() << "," << setfill('0') << setw(2)
		<< b.getdayB() << "," << b.getyearD() << "," << setfill('0') << setw(2) << b.getmonthD()
		<< "," << setfill('0') << setw(2) << b.getdayD() << endl;

	return out;
}
fstream  &operator >> (fstream &in, vector< borrow> &b) {
	for (int i = 0;i < b.size();i++) {
		in >> b[i].writID;
		in >> b[i].memberID;
		string dB = to_string(b[i].getdayB()), mB = to_string(b[i].getmonthB()), yB = to_string(b[i].getyearB());
		string dD = to_string(b[i].getdayD()), mD = to_string(b[i].getmonthD()), yD = to_string(b[i].getyearD());
		in >> dB >> mB >> yB;
		in >> dD >> mD >> yD;
	}

	return in;
}

ofstream  &operator <<(ofstream &out2, vector<borrow> &f) {
	for (int i = 0;i < f.size();i++) {
		out2 << f[i].get_writID() << "," << f[i].get_memberID() << "," << f[i].getyearB() << "," << setfill('0') << setw(2) << f[i].getmonthB() << "," 
			<< setfill('0') << setw(2) << f[i].getdayB() << "," << f[i].getyearD()
			<< "," << f[i].getmonthD() << "," << f[i].getdayD() << endl;
	}
	return out2;

}


date  operator +(date d, const int &n) {

	int day = d.getDay();
	int month = d.getMonth();
	int year = d.getYear();
	int day2;
	day2 = day + n;
	if (day2 > daysOfMonth(month, year)) {
		day2 = day2- daysOfMonth(month, year);
		month++;
		if (month > 12) {
			month = 1;
			year++;
		}
	}
	
		d.setDate(day2, month, year);
	
	return d;

}