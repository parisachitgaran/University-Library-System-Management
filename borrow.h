#ifndef BORROW_H
#define BORROW_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>
#include"date.h"

#pragma once

class borrow {

protected:
	//std::string dayB,monthB,yearB, dayD, monthD, yearD;
	date dateB, dateD;
	std::string writID, memberID;
public:
	borrow(std::string writ = "", std::string member = "", int dB = 0, int mB = 0, int yB = 0, int dD = 0,
		int mD= 0, int yD = 0);

	void set_writID(std::string);
	void set_memberID(std::string);
	void set_dateB(int day, int month, int year);
	void set_dateD(int day, int month, int year);
	void setdate(date d);

	std::string get_writID();
	std::string get_memberID();


	int getdayB();
	int getmonthB();
	int getyearB();

	int getdayD();
	int getmonthD();
	int getyearD();

	date getdateborrow();
	
	
	friend std::fstream  &operator <<(std::fstream &out, borrow &b);
	
	friend std::fstream  &operator >>(std::fstream &in,std:: vector< borrow> &b);
	friend std::ofstream  &operator <<(std::ofstream &out2, std::vector<borrow> &f);
	//friend std::string   operator +(std::string b, const int& n);
	friend date operator +(date d, const int& n);
};
#endif