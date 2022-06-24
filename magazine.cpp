#include "stdafx.h"
#include<iostream>
#include<string>
#include<ctype.h>
#include<vector>
#include<fstream>
#include"Books.h"
#include"magazine.h"
using namespace std;

magazine::magazine(string ID, string title, string num,string numpage, string stock) {
	Books(ID, title, num,numpage, stock);
}



ostream  &operator <<(ostream &out, magazine &m) {
	out << m.get_ID() << "," << m.get_title()<< "," <<m.get_numpage() << "," << m.get_num() << "," << m.get_stock() << endl;
	return out;
}
istream  &operator >> (istream &in, magazine &m) {
	in >> m.ID;
	in >> m.title;
	in >> m.numpage;
	in >> m.num;
	in >> m.stock;
	
	return in;
}
ofstream  &operator << (ofstream &out, vector<magazine> &m) {

	for (int i = 0;i < m.size();i++) {
		out << m[i].get_ID() << "," << m[i].get_title() << "," << m[i].get_numpage() << "," << m[i].get_num() << "," << m[i].get_stock() << endl;
	
	}
	return out;
}




