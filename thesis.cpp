#include "stdafx.h"
#include<iostream>
#include<string>
#include<ctype.h>
#include<vector>
#include<fstream>
#include"Books.h"
#include"thesis.h"
using namespace std;
string msg = "** Word entered is incorrect !";


thesis::thesis(string ID, string title, string numpage, string stock, string degree,string college,string group) {
	Books(ID, title,num, numpage, stock);
	try{
	set_degree(degree);
	set_college(college);
	set_group(group);
	}
	catch (string msg) { cout << ""; }
}

void thesis::test_word(string w) {
	string msg = "\n\t** You can only letters !";
	for (int i = 0;i < w.size();i++)
		if (!isalpha(w[i]))
			throw msg;
}



void thesis::set_degree(string degree) {
	
	test_word(degree);
	this->degree = degree;
}
void thesis::set_college(string college) {
	test_word(college);
	this->college = college;
}
void thesis::set_group(string group) {
	test_word(group);
	this->group = group;
}


string thesis::get_degree() { return degree; }
string thesis::get_college() { return college; }
string thesis::get_group() { return group; }

ostream  &operator <<(ostream &out, thesis &t) {
	out << t.get_ID() << "," << t.get_title() << "," << t.get_num() << "," << t.get_numpage() << ","  << t.get_stock()
		<< "," <<t.get_degree() << "," << t.get_college() << "," << t.get_group() << endl;
	return out;
}
istream  &operator >> (istream &in, thesis &t) {
	in >> t.ID;
	in >>t.title;
	in >> t.num;
	in >> t.numpage;
	in >> t.stock;
	in >> t.degree;
	in >> t.college;
	in >> t.group;
	return in;
}
ofstream  &operator << (ofstream &out, vector<thesis> &t) {

	for (int i = 0;i < t.size();i++) {
		out << t[i].get_ID() << "," << t[i].get_title()<< "," << t[i].get_num() << "," << t[i].get_numpage() <<  "," << t[i].get_stock()
			<< "," << t[i].get_degree() << "," << t[i].get_college() << "," << t[i].get_group() << endl;

	}
	return out;
}