#ifndef UNISTUDENT_H
#define  UNISTUDENT_H
#include<iostream>
#include<string>
#include"UniPerson.h"
#pragma once

class Student : public Person {


protected:

	std::string idnumber;
	std::string  grade;

	//std::vector<Course> Courses;
public:
	Student() {}
	Student(std::string name, std::string family, std::string phone, std::string Idnum, std::string age, std::string idnumber, std::string grade);
	
	void setIdnumber(std::string idnumber);
	void setgrade(std::string grade);

	std::string getIdnumber()const;
	std::string getgrade()const;


	void report() const;



	friend std::ostream  &operator <<(std::ostream &out, Student &l);
	friend std::istream  &operator >> (std::istream &in, Student &l);
	friend std::ofstream  &operator << (std::ofstream &out, std::vector<Student> &l);
};
#endif