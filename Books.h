#ifndef BOOKS_H
#define BOOKS_H
#include<iostream>
#include<string>
#pragma once

class Books {
protected:
	std::string ID, title;
	std::string numpage, num, stock;
public:
	Books(std::string ID = "", std::string title = "", std::string num = "", std::string numpage = "", std::string stock = "");

	void set_ID(std::string ID);
	void set_title(std::string title);
	void set_numpage(std::string numpage);
	void set_stock(std::string stock);
	void set_num(std::string num);

	std::string get_ID();
	std::string get_title();
	std::string get_num();
	std::string get_numpage();
	std::string get_stock();

	void test_num( std::string);
	void test_stock();
	

};
#endif // !BOOK.H

#pragma once
