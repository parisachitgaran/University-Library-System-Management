#ifndef MEMBER_H
#define  MEMBER_H
#include<iostream>
#include<string>
#include"person.h"
#pragma once

class member:public person{
protected:
	std::string level;
	std::string type;
	std::string stunum;
	std::string fine;
public:
	member(std::string ID = "", std::string name = "", std::string family = "", std::string day = "", std::string month = "",
		std::string year = "", std::string nationalnum = "",
		std::string type="", std::string level = "", std::string stunum="", std::string fine="0");

	void set_level(std::string level);
	void set_type(std::string type);
	void set_stunum(std::string stunum);
	void set_fine(std::string fine);

	std::string get_level();
	std::string get_type();
	std::string get_stunum();
	std::string get_fine();

	friend std::ostream  &operator <<(std::ostream &out, member &m);
	friend std::istream  &operator >> (std::istream &in, member &m);
	friend std::ofstream  &operator << (std::ofstream &out, std::vector<member> &m);

	
};




#endif
