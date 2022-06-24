#ifndef UNIEMPLOYEE_H
#define  UNIEMPLOYEE_H
#include<iostream>
#include<string>
#include"UniPerson.h"
#pragma once

class Employee :public Person {

protected:
	std::string codeEmployee;
	

public:
	Employee() {}
	Employee(std::string name, std::string family, std::string phone, std::string Idnum, std::string age, std::string codeEmployee);
	
	void setcodeEmployee(std::string codeEmployee);

	std::string getcodeEmployee()const;
	
	
	void report() const;

	friend std::ostream  &operator <<(std::ostream &out, Employee &l);
	friend std::istream  &operator >> (std::istream &in, Employee &l);
	friend std::ofstream  &operator << (std::ofstream &out, std::vector<Employee> &l);

};

#endif