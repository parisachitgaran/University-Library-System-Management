#pragma once
#ifndef DATE_H
#define DATE_H
#include<iostream>
#include<string>
#include<fstream>
#include<vector>

class date {
public:
	date(int d=0, int m=0, int y=0);
	void setDate(int d, int m, int y);

	void printDate();
	
	int getDay();
	int getMonth();
	int getYear();
	void getdata_date(int d, int m, int y);

	//void increas_date();
	
	
private:
	int day;
	int month;
	int year;
};

#endif