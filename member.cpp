#include "stdafx.h"
#include<iostream>
#include<string>
#include<ctype.h>
#include<vector>
#include<fstream>
#include<iomanip>
#include"person.h"
#include"member.h"

using namespace std;





member::member(std::string ID, std::string name , std::string family , string day , string month , string year , string nationalnum,
string type, string level, string stunum, string fine) {
	try {
		person(ID, name, family, day, month, year, nationalnum);
		set_type(type);
		set_fine(fine);
		set_stunum(stunum);
	}
	catch (string msg) { cout <<""; }
}


void member::set_type(string type) {
	
	string msg = "\n\t** This type not available ! Try again";

	if (type != "Student" && type != "student" && type != "Staff" && type != "staff")
		throw msg;

	

	this->type = type;
}
void member::set_level(string level) {

	string msg = "\n\t** This level not available ! Try again";

	if (level != "baccalaureate" && level != "Baccalaureate" && level != "postgraduate" &&
		level != "Postgraduate"&& level != "PhD")
		throw msg;



	this->level = level;
}
void member::set_stunum(string stunum) {
	test_num(stunum);
	this->stunum = stunum;
}
void member::set_fine(string fine) {
	this->fine = fine;
}



string member::get_type() { return type; }
string member::get_level() { return level; }
string member::get_stunum() { return stunum; }
string member::get_fine() { return fine; }



ostream  &operator <<(ostream &out, member &m) {
	out << m.get_ID() << "," << m.get_name() << "," << m.get_family() << "," << setfill('0') << setw(2) << m.get_day() << "," << setfill('0') << setw(2) <<
		m.get_month() << "," << setfill('0') << setw(2) << m.get_year() <<","<< m.get_nationalnum()<<","<<m.get_type()<< "," << 
		m.get_level() <<","<<m.get_stunum()<<","<<m.get_fine()<<endl;
	return out;
}
istream  &operator >> (istream &in, member &m) {
	in >> m.ID;
	in >>m.name;
	in >> m.family;
	in >> m.day;  in >> m.month;  in >> m.year;
	in >> m.nationalnum;
	in >> m.type;
	in >> m.level;
	in >> m.stunum;
	in >> m.fine;
	return in;
}
ofstream  &operator << (ofstream &out, vector<member> &m) {

	for (int i = 0;i < m.size();i++) {
		out << m[i].get_ID() << "," << m[i].get_name() << "," << m[i].get_family() << "," << setfill('0') << setw(2) << m[i].get_day() << "," << setfill('0') 
			<< setw(2) << m[i].get_month() << "," << setfill('0') << setw(2) << m[i].get_year() << ","
			<< m[i].get_nationalnum() << "," << m[i].get_type() << "," << m[i].get_level() << "," << m[i].get_stunum() << "," << m[i].get_fine() << endl;
		
	}
	return out;
}