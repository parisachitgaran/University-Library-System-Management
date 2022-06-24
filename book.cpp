
#include "stdafx.h"
#include<iostream>
#include<string>
#include<ctype.h>
#include<vector>
#include<fstream>
#include"Books.h"
#include"book.h"
using namespace std;

book::book(string ID, string title, string numpage,string num, string stock, string kind) {
	try{
	Books(ID, title, num,numpage, stock);
	set_kind(kind);
	
	}
	catch (string msg) { cout << ""; }
}


void book::set_kind(string kind)  {

	int x = 0;
	string msg = "\n\t** This kind not available ! Try again";
	
	if (kind != "Engineering" && kind != "engineering" && kind != "Sience" && kind != "sience" && kind != "Theology"
		&& kind != "theology" && kind!= "Literature" && kind != "literature" && kind != "Other" && kind != "other")
		throw msg;
	
	this->kind = kind;
}


string book::get_kind() { return kind; }

fstream  &operator <<(fstream &out, book &b) {
	out << b.get_ID() << "," << b.get_title() << "," << b.get_numpage() << "," << b.get_num() << "," << b.get_stock() << "," << b.get_kind() << endl;
	return out;
}
fstream  &operator >>(fstream &in, book &b) {
	in >> b.ID;
	in >> b.title;
	in >> b.numpage;
	in >> b.num;
	in >> b.stock;
	in >> b.kind;
	return in;
}
ofstream  &operator << (ofstream &out, vector<book> &b) {
	
	for (int i = 0;i < b.size();i++) {
		out << b[i].get_ID() << "," << b[i].get_title() << "," << b[i].get_numpage() << "," << b[i].get_num() << "," <<
			b[i].get_stock() << "," << b[i].get_kind() << endl;
	}
		return out;
}
string  operator -(string m, int &n) {
	int m_int = stoi(m);
	string d = to_string(m_int - n);
	return d;
}
