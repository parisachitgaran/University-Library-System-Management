#ifndef MAGAZINE_H
#define  MAGAZINE_H
#include<iostream>
#include<string>
#include"Books.h"


class magazine :public Books {

public:
	magazine(std::string ID = "", std::string title = "", std::string num = "", std::string numpage = "", std::string stock = "");

	

	friend std::ostream  &operator <<(std::ostream &out, magazine &m);
	friend std::istream  &operator >> (std::istream &in, magazine &m);
	friend std::ofstream  &operator << (std::ofstream &out, std::vector<magazine> &m);
	
	
};






#endif#pragma once
