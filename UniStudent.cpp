#include "stdafx.h"
#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
#include<conio.h>
#include<fstream>
#include<map>
#include"UniPerson.h"
#include"UniStudent.h"
using namespace std;

Student::Student(string name, string family, string phone,string Idnum, string age, string idnumber, string grade) {
	Person(name, family, phone,Idnum, age);

	this->idnumber = idnumber;
	this->grade = grade;

}


void Student::setIdnumber(string idnumber) {

	this->idnumber = idnumber;

}
void Student::setgrade(string grade) {

	this->grade = grade;

}



string Student::getIdnumber()const {	return idnumber;  }
string Student::getgrade()const { return grade; }


void Student::report() const {

	cout << name << setw(6) << " " << family << setw(10) << address << setw(4) << phone << setw(4) << age << setw(4) << idnumber << setw(4) << grade << endl;

}


ostream  &operator <<(ostream &out, Student &l) {
	out << l.getIdnumber() << "," << l.getName() << "," << l.getFamily() << "," << l.getPhone() << "," << l.getId() << "," << l.getAge() << "," << l.getgrade() << endl;
	return out;
}
istream  &operator >> (istream &in, Student &l) {
	in >> l.idnumber;
	in >> l.name;
	in >> l.family;
	in >> l.phone;
	in >> l.Idnum;
	in >> l.age;
	in >> l.grade;


	return in;
}
ofstream  &operator <<(ofstream &out, vector<Student> &l) {

	for (int i = 0;i < l.size();i++) {
		out << l[i].getIdnumber() << "," << l[i].getName() << "," << l[i].getFamily() << "," << l[i].getPhone() << "," << l[i].getId() << "," << l[i].getAge() << "," << l[i].getgrade() << endl;

	}
	return out;
}