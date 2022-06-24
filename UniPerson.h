#ifndef UNIPERSON_H
#define  UNIPERSON_H
#include<iostream>
#include<string>
#pragma once



class Person {

protected:
	std::string name, family, address, phone,Idnum;
	std::string age;

public:

	Person() {}
	Person(std::string name, std::string family, std::string phone, std::string Idnum, std::string age);

	void setName(std::string name);
	void setFamily(std::string family);
	void setPhone(std::string phone);
	void setIDnum(std::string Idnum);
	void setAge(std::string age);

	std::string getName() const;
	std::string getFamily()const;
	std::string getId()const;
	std::string getPhone()const;
	std::string getAge()const;

	void report() const;


};

#endif