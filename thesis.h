#ifndef THESIS_H
#define THESIS_H
#include<iostream>
#include<string>
#include"Books.h"


class thesis :public Books {

protected:
	std::string degree,college,group;
public:
	thesis(std::string ID = "", std::string title = "", std::string numpage = "0", std::string stock = "0", std::string degree = "",std::string college = "", std::string group = "");
	
	void set_degree(std::string degree);
	void set_college(std::string college);
	void set_group(std::string group);
	
	std::string get_degree();
	std::string get_college();
	std::string get_group();

	friend std::ostream  &operator <<(std::ostream &out, thesis &t);
	friend std::istream  &operator >> (std::istream &in, thesis &t);
	friend std::ofstream  &operator << (std::ofstream &out, std::vector<thesis> &t);


	void test_word(std::string);
};






#endif#pragma once
