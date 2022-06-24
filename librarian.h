#pragma once
#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include<iostream>
#include<string>
#include"person.h"

class librarian :public person {
protected:
	std::string evidence,post;
	
public:
	librarian(std::string ID = "", std::string name = "", std::string family = "", std::string day = "", std::string month = "",
		std::string year = "", std::string nationalnum = "",
		std::string evidence="", std::string post="");

	void set_evidence(std::string evidence);
	void set_post(std::string post);
	
	std::string get_evidence();
	std::string get_post();

	friend std::ostream  &operator <<(std::ostream &out, librarian &l);
	friend std::istream  &operator >> (std::istream &in, librarian &l);
	friend std::ofstream  &operator << (std::ofstream &out, std::vector<librarian> &l);

	

};















#endif