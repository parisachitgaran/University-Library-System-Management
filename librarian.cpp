#include "stdafx.h"
#include<iostream>
#include<string>
#include<ctype.h>
#include<vector>
#include<fstream>
#include<iomanip>
#include"person.h"
#include"librarian.h"

using namespace std;

librarian::librarian(string ID, string name, string family, string day, string month, string year, string nationalnum,string evidence, string post) {
	try{
	person(ID, name, family, day, month, year, nationalnum);
	set_evidence(evidence);
	set_post(post);
	}
	catch (string msg) { cout << ""; }
}




void librarian::set_evidence(string evidence) {

	test_word(evidence);
	this->evidence = evidence;
}
void librarian::set_post(string post) {
	string msg = "\n\t** This post not available ! Try again";

	if (post != "Normal" && post != "normal" && post != "Administrator" && post != "administrator" )
		throw msg;

	this->post = post;
}


string librarian::get_evidence() { return evidence; }
string librarian::get_post() { return post; }

ostream  &operator <<(ostream &out, librarian &l) {
	out << l.get_ID() << "," << l.get_name() << "," << l.get_family() << "," << setfill('0') << setw(2) << l.get_day() << "," << setfill('0') << setw(2) << l.get_month() << "," << l.get_year() << ","
		<< l.get_nationalnum() << "," << l.get_evidence() << "," << l.get_post() << endl;
	return out;
}
istream  &operator >> (istream &in, librarian &l) {
	in >> l.ID;
	in >> l.name;
	in >> l.family;
	in >> l.day;  in >> l.month;  in >> l.year;
	in >> l.nationalnum;
	in >> l.evidence;
	in >> l.post;
	
	return in;
}
ofstream  &operator <<(ofstream &out, vector<librarian> &l) {

	for (int i = 0;i < l.size();i++) {
		out << l[i].get_ID() << "," << l[i].get_name() << "," << l[i].get_family() << "," << setfill('0') << setw(2) << l[i].get_day() << "," << setfill('0') << setw(2) << l[i].get_month() << "," << l[i].get_year() << ","
			<< l[i].get_nationalnum() << "," << l[i].get_evidence() << "," << l[i].get_post() << endl;
	}
	return out;
}