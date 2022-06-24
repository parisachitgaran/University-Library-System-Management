#pragma once
#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
#pragma once

class person {
protected:
	std::string ID,name,family, nationalnum;
	std::string day,month,year;
public:
	person(std::string ID = "", std::string name = "", std::string family = "", std::string day= "",
		std::string month= "", std::string year= "", std::string nationalnum = "");

	void set_ID(std::string ID);
	void set_name(std::string name);
	void set_family(std::string family);
	void set_birthday(std::string day);
	void set_birthmonth( std::string month);
	void set_birthyear( std::string year);
	void set_nationalnum(std::string nationalnum);

	std::string get_ID();
	std::string get_name();
	std::string get_family();
	std::string get_day();
	std::string get_month();
	std::string get_year();
	std::string get_nationalnum();

	void test_word(std::string);
	void test_num( std::string);



	 //friend   bool operator !=(std::string &, std::string &);
};
#endif