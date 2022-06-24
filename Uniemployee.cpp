#include "stdafx.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<conio.h>
#include<fstream>
#include<map>
#include"UniPerson.h"
#include"Uniemployee.h"
using namespace std;



Employee::Employee(string name, string family, string phone, string Idnum, string age, string IdEmployee) {
	Person(name, family, phone,Idnum, age);

	this->codeEmployee = codeEmployee;
	
}

void Employee::setcodeEmployee(string codeEmployee) {


	this->codeEmployee = codeEmployee;

}

string Employee::getcodeEmployee()const {

	return codeEmployee;
}

void Employee::report() const {

	cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << setw(4) 
		<< codeEmployee << endl;

}



ostream  &operator <<(ostream &out, Employee &l) {
	out << l.getcodeEmployee() << "," << l.getName() << "," << l.getFamily() << "," << l.getPhone() << "," << l.getId() <<","  << l.getAge() << endl;
	return out;
}
istream  &operator >> (istream &in, Employee &l) {
	in >> l.codeEmployee;
	in >> l.name;
	in >> l.family;
	in >> l.phone;  
	in >> l.Idnum;
	in >> l.age;

	return in;
}
ofstream  &operator <<(ofstream &out, vector<Employee> &l) {

	for (int i = 0;i < l.size();i++) {
		out << l[i].getcodeEmployee() << "," << l[i].getName() << "," << l[i].getFamily() << "," << l[i].getPhone() << "," << l[i].getId() << "," << l[i].getAge() << endl;
		
	}
	return out;
}