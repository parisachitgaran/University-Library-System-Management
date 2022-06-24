
//#ifndef BOOK_CPP
//#define BOOK_CPP

#include "stdafx.h"
#include<iostream>
#include<sstream>
#include<string>
#include<ctype.h>
#include"Books.h"
using namespace std;

bool testnum(int n)
{
	return n >= 0;
}

Books::Books(string ID, string title,string num, string numpage, string stock) {
	set_ID(ID);
	set_title(title);
	set_numpage(numpage);
	set_stock(stock);
}

void Books::test_num(string n) {

	string msg1 = "\n\t** You can only number ! Try agian";
	//string msg3 = "Mobile does not start with 0 . Try agian";

	for (int k = 0;k < n.length();k++)
		if (isalpha(n[k]))
			throw msg1;

}
void Books::test_stock() {

	string msg2 = "\n\t** stock must be less than or equal to all book. Try again";

	int n, s;
	stringstream ss, nn;
	ss << num;
	ss >> n;
	nn << stock;
	nn >> s;
	if (n < s)
		throw msg2;

}

void Books::set_ID(string ID) {

	this->ID = ID;
}
void Books::set_title(string title) {
	this->title = title;
}
void Books::set_numpage(string numpage) {

	test_num(numpage);
	this->numpage = numpage;
}
void Books::set_num(string num) {

	test_num(num);
	this->num = num;
}
void Books::set_stock(string stock) {

	test_num(stock);
	test_stock();
	
	
	this->stock = stock;
}


string Books::get_ID() { return ID; }
string Books::get_title() { return title; }
string Books::get_numpage() { return numpage; }
string Books::get_num() { return num; }
string Books::get_stock() { return stock; }











