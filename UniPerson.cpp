#include "stdafx.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<conio.h>
#include<fstream>
#include<map>
#include"UniPerson.h"
using namespace std;

Person::Person(string name, string family, string phone, string Idnum, string age) {

	this->name = name;
	(*this).family = family;
	this->phone = phone;
	this->age = age;
}

void Person::setName(string name) {
	this->name = name;
}
void Person::setFamily(string family) {
	this->family = family;
}
void Person::setPhone(string phone) {
	this->phone = phone;
}
void Person::setAge(string age) {
	this->age = age;
}

string Person::getName() const {
	return name;
}
string Person::getFamily()const {
	return family;
}
string Person::getId()const {
	return Idnum;
}
string Person::getPhone()const {
	return phone;
}
string Person::getAge()const {
	return age;
}
void Person::setIDnum(string Idnum) {
	this->Idnum = Idnum;
}
void Person::report() const {

	cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << endl;

}
