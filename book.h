#pragma once
#ifndef BOOK_H
#define BOOK_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"Books.h"


class book:public Books {

protected:
	std::string kind;
public:
	book(std::string ID = "", std::string title = "", std::string numpage = "", std::string num = "", std::string stock = "", std::string kind = "");
	
	void set_kind(std::string kind);

	
	std::string get_kind();
	
	

   friend std::fstream  &operator <<(std::fstream &out, book &b);
   friend std::fstream  &operator >>(std::fstream &in, book &b);
   friend std::ofstream  &operator << (std::ofstream &out, std::vector<book> &b);
  friend std::string   operator -(std::string b, int& n);
 // friend std::string   operator +(std::string b, const int& n);
   
   
};






#endif