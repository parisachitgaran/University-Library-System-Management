// final project.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include <sstream>
#include<iomanip>
#include"Books.h"
#include"book.h"
#include"librarian.h"
#include"magazine.h"
#include"member.h"
#include"person.h"
#include"thesis.h"
#include"borrow.h"
#include"date.h"
#include"Uniemployee.h"
#include"UniStudent.h"
#include"UniPerson.h"

using namespace std;

fstream f_book;
fstream f_thesis;
fstream f_magazine;
fstream f_member;
fstream f_librarian;
fstream f_borrow;
fstream f_University_employee;
fstream f_University_Student;


vector<book>vec_book;
vector<magazine>vec_magazine;
vector<thesis>vec_thesis;
vector<librarian>vec_librarian;
vector<member>vec_member;
vector<borrow>vec_borrow;
vector<Student>vec_Student;
vector<Employee>vec_Employee;

string  operator +(string m, const int &n) {
	int m_int = stoi(m);
	string d = to_string(m_int + n);
	return d;
}

//***************************** PASSWORD *****************************
void password_librarian();
void password_member();
//***************************** MENU *****************************
void MAIN_MENU();
void MenuLibrarian();
void MenuMember();
void book_menu();
void magazine_menu();
void member_menu();
void thesis_menu();
void librarian_menu();
void borrow_menu();

//***************************** VEC *********************************
void vecbook();
void vecmagazine();
void vecthesis();
void veclibrarian();
void vecmember();
void vecborrow();
void vecEmployee();
void vecStudent();


//***************************** getdata *****************************
void getdata_book();
void getdata_magazine();
void getdata_thesis();
void getdata_member();
void getdata_librarian();
void getdata_borrow();

//***************************** Edit ********************************
void Edit_book(string);
void Edit_magazine(string);
void Edit_thesis(string);
void Edit_member(string);
void Edit_librarian(string);
void Edit_borrow(string);

//***************************** Report book **************************
void menu_report_book();
void report_All_book();
void report_One_book();
void report_group_book(int c);
//************************** Report Magazine *************************
void menu_report_magazine();
void report_All_magazine();
void report_One_magazine();
//************************** Report Thesis ****************************
void menu_report_thesis();
void report_All_thesis();
void report_One_thesis();
//************************** Report Member ****************************
void menu_report_member();
void report_All_member_Student();
void report_One_member_Student();
void report_All_member_Employee();
void report_One_member_Employee();
//************************** Report Librarian *************************
void menu_report_librarian();
void report_All_librarian();
void report_One_librarian();

//************************** Fine ***********************************

void fine(string);
//************************** Report Borrow *************************
void report_All_borrow();
//************************** Search ****************************

void menu_search_borrow();
void search_by_writID();
void search_by_memberID();
void report_borrow_by_DeliveryDate();


//************************** Delete ****************************
void delete_book(string);
void delete_magazine(string);
void delete_thesis(string);
void delete_member(string);
void delete_librarian(string);
void delete_borrow(string);

//*********************** TEST AND CONTROL *********************
string test_book_ID(string);
int test_book_title(string);
int test_magazine(string);
string test_magazine_ID(string);
string test_thesis_ID(string);

int control_borrow_member(string);


bool test_member_Employee(string ID);
bool test_member_Student(string ID);


//*********************** ADD FUNCTION *********************
void Add_number_magazine_ID(string writID);
void Add_number_thesis_ID(string writID);
void Add_number_book_title(string);
void Add_number_book_ID(string);
void Add_number_magazine(string);



//*********************** DECREAS FUNCTION *********************
void decreas_book(string);
void decreas_magazine(string);
void decreas_thesis(string);


long int convert_to_day(int, int, int, int);
date date_Delivery(date, string);
string test_level_member(string);




int main()
{
	vecbook();
	vecmagazine();
	vecthesis();
	vecborrow();
	vecmember();
	veclibrarian();
	vecStudent();
	vecEmployee();



	MAIN_MENU();

	return 0;
}



void password_librarian() {

	string ID, nationalnum;
	char choise;
	int temp = 0;


	cout << "\n\n\n\t Please Enter your Information ";
	cout << "\n\n\t   ID : ";
	cin >> ID;
	cout << "\n\t   National Number : ";
	cin >> nationalnum;

	for (int i = 0;i < vec_librarian.size();i++) {
		if (vec_librarian[i].get_ID() == ID && vec_librarian[i].get_nationalnum() == nationalnum)
		{
			MenuLibrarian();
			temp = 1;
		}
	}

	if (temp == 0)
		cout << "\n\n\t ** ID or National Number is incorrect ";


}
void password_member() {

	string ID, nationalnum;
	char choise;
	int temp = 0;

	cout << "\n\t Please Enter your Information ";
	cout << "\n\n\t   ID : ";
	cin >> ID;
	cout << "\n\n\t   National Number : ";
	cin >> nationalnum;


	for (int i = 0;i < vec_member.size();i++) {

		if (vec_member[i].get_ID() == ID && vec_member[i].get_nationalnum() == nationalnum) {

			MenuMember();
			temp = 1;
		}
	}

	if (temp == 0)
		cout << "\n\n\t ** ID or National Number is incorrect ";
}



void book_menu() {
	int choise1;
	char choise2;
	string ID;
	do {
		system("cls");
		cout << "\n\n\t          BOOK MENU          ";
		cout << "\n\t ______________________________";
		cout << "\n\t|        1.  Add               |";
		cout << "\n\t|        2.  Edite             |";
		cout << "\n\t|        3.  Search            |";
		cout << "\n\t|        4.  Delete            |";
		cout << "\n\t|        5.  Report            |";
		cout << "\n\t|        6.  Back              |";
		cout << "\n\t|______________________________|";
		cout << "\n\n\t your choise ==> ";
		cin >> choise1;

		switch (choise1)
		{
		case 1:
		{
			getdata_book();

			break;
		}
		case 2:
		{
			cout << "\n\n\t Enter ID Book : ";
			cin >> ID;
			Edit_book(ID);
			break;
		}
		case 3:
		{
			report_One_book();
			break;
		}
		case 4:
		{
			cout << "\n\n\t Enter ID Book : ";
			cin >> ID;
			delete_book(ID);
			break;
		}
		case 5:
		{
			menu_report_book();
			break;
		}
		default:
			break;
		}

		cout << "\n\n\t#### Are you back to Book Menu ? (y/n)";
		cin >> choise2;

	} while (choise2 == 'y' || choise2 == 'Y');

}
void magazine_menu() {
	int choise1;
	string ID;
	char choise2;
	do {
		system("cls");
		cout << "\n\n\t        MAGAZINE MENU         ";
		cout << "\n\t ______________________________";
		cout << "\n\t|        1.  Add               |";
		cout << "\n\t|        2.  Edite             |";
		cout << "\n\t|        3.  Search            |";
		cout << "\n\t|        4.  Delete            |";
		cout << "\n\t|        5.  Report            |";
		cout << "\n\t|        6.  Back              |";
		cout << "\n\t|______________________________|";
		cout << "\n\n\t your choise ==> ";
		cin >> choise1;

		switch (choise1)
		{
		case 1:
		{
			getdata_magazine();

			break;
		}
		case 2:
		{
			cout << "\n\n\t Enter ID Book : ";
			cin >> ID;
			Edit_magazine(ID);
			break;
		}
		case 3:
		{
			report_One_magazine();
			break;
		}
		case 4:
		{
			cout << "\n\n\t Enter ID Magazine : ";
			cin >> ID;
			delete_magazine(ID);
			break;
		}
		case 5:
		{
			menu_report_magazine();

			break;
		}
		default:
			break;
		}

		cout << "\n\n\t#### Are you back to Magazine Menu ? (y/n)";
		cin >> choise2;
	} while (choise2 == 'y' || choise2 == 'Y');
}
void thesis_menu() {
	int choise;
	string ID;
	char choise2;
	do {
		system("cls");
		cout << "\n\n\t        THESIS MENU          ";
		cout << "\n\t ______________________________";
		cout << "\n\t|        1.  Add               |";
		cout << "\n\t|        2.  Edite             |";
		cout << "\n\t|        3.  Search            |";
		cout << "\n\t|        4.  Delete            |";
		cout << "\n\t|        5.  Report            |";
		cout << "\n\t|        6.  Back              |";
		cout << "\n\t|______________________________|";
		cout << "\n\n\t your choise ==> ";
		cin >> choise;

		switch (choise)
		{
		case 1:
		{
			getdata_thesis();

			break;
		}
		case 2:
		{
			cout << "\n\n\t Enter ID Book : ";
			cin >> ID;
			Edit_thesis(ID);
			break;
		}
		case 3:
		{
			report_One_thesis();
			break;
		}
		case 4:
		{
			cout << "\n\n\t Enter ID Thesis : ";
			cin >> ID;
			delete_thesis(ID);
			break;
		}
		case 5:
		{
			menu_report_thesis();
			break;
		}
		default:
			break;
		}

		cout << "\n\n\t#### Are you back to Thesis Menu ? (y/n)";
		cin >> choise2;
	} while (choise2 == 'y' || choise2 == 'Y');
}
void member_menu() {
	int choise;
	string ID;
	char choise2;
	do {
		system("cls");
		cout << "\n\n\t        MEMBER MENU         ";
		cout << "\n\t ______________________________";
		cout << "\n\t|        1.  Add               |";
		cout << "\n\t|        2.  Edite             |";
		cout << "\n\t|        3.  Search            |";
		cout << "\n\t|        4.  Delete            |";
		cout << "\n\t|        5.  Report            |";
		cout << "\n\t|        6.  Payment Of Fine   |";
		cout << "\n\t|        7.  Back              |";
		cout << "\n\t|______________________________|";
		cout << "\n\n\t your choise ==> ";
		cin >> choise;

		switch (choise)
		{
		case 1:
		{
			getdata_member();

			break;
		}
		case 2:
		{
			cout << "\n\n\t Enter ID Member : ";
			cin >> ID;
			Edit_member(ID);
			break;
		}
		case 3:
		{
		START:
			string s;
			cout << "\n\n\t Student or Employee ?";
			cin >> s;
			if (s == "student" || s == "Student")
				report_One_member_Student();
			else if (s == "Employee" || s == "employee")
				report_One_member_Employee();
			else
				goto START;

			break;
		}
		case 4:
		{
			cout << "\n\n\t Enter ID Member : ";
			cin >> ID;
			delete_member(ID);
			break;
		}
		case 5:
		{
			menu_report_member();
			break;
		}
		case 6:
		{
			cout << "\n\n\t Enter ID Member : ";
			cin >> ID;
			fine(ID);
			break;
		}
		default:
			break;
		}

		cout << "\n\n\t#### Are you back to Member Menu ? (y/n)";
		cin >> choise2;
	} while (choise2 == 'y' || choise2 == 'Y');
}
void librarian_menu() {
	int choise;
	string ID;
	char choise2;
	do {
		system("cls");
		cout << "\n\n\t       LIBRARIAN MENU         ";
		cout << "\n\t ______________________________";
		cout << "\n\t|        1.  Add               |";
		cout << "\n\t|        2.  Edite             |";
		cout << "\n\t|        3.  Search            |";
		cout << "\n\t|        4.  Delete            |";
		cout << "\n\t|        5.  Report            |";
		cout << "\n\t|        6.  Back              |";
		cout << "\n\t|______________________________|";
		cout << "\n\n\t your choise ==> ";
		cin >> choise;

		switch (choise)
		{
		case 1:
		{
			getdata_librarian();

			break;
		}
		case 2:
		{
			cout << "\n\n\t Enter ID Librarian : ";
			cin >> ID;
			Edit_librarian(ID);
			break;
		}
		case 3:
		{
			//report_One_librarian();
			break;
		}
		case 4:
		{
			cout << "\n\n\t Enter ID Librarian : ";
			cin >> ID;
			delete_librarian(ID);
			break;
		}
		default:
			break;
		}

		cout << "\n\n\t#### Are you back to Librarian Menu ? (y/n)";
		cin >> choise2;
	} while (choise2 == 'y' || choise2 == 'Y');
}
void borrow_menu() {

	int choise;
	string ID, writID;

	char choise2;
	do {
		system("cls");
		cout << "\n\n\t       BORROW MENU         ";
		cout << "\n\t ______________________________";
		cout << "\n\t|        1.  Add               |";
		cout << "\n\t|        2.  Edite             |";
		cout << "\n\t|        3.  Search            |";
		cout << "\n\t|        4.  Delete            |";
		cout << "\n\t|        5.  Report            |";
		cout << "\n\t|        6.  Back              |";
		cout << "\n\t|______________________________|";
		cout << "\n\n\t your choise ==> ";
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			getdata_borrow();
			break;
		}
		case 2:
		{
			cout << "\n\n\t Enter ID Borrow : ";
			cin >> ID;
			Edit_borrow(ID);
			break;
		}
		case 3:
		{
			menu_search_borrow();   break;
		}
		case 4:
		{
			cout << "\n\n\t Enter Write ID : ";
			cin >> writID;
			delete_borrow(writID);
			break;
		}
		case 5:
		{
			int c;
			system("cls");
			cout << "\n\n\t       BORROW REPORT MENU         ";
			cout << "\n\t ____________________________________";
			cout << "\n\t|        1.  Report All              |";
			cout << "\n\t|        2.  Report By DeliveryDate  |";
			cout << "\n\t|        3.  Back                    |";
			cout << "\n\t|____________________________________|";
			cout << "\n\n\t your choise ==> ";
			cin >> c;
			switch (c)
			{
			case 1:
			{
				report_All_borrow(); break;
			}
			case 2:
			{
				report_borrow_by_DeliveryDate();   break;
			}
			default:
				break;
			}
			break;
		}
		default:
			break;
		}

		cout << "\n\n\n\t#### Are you back to Borrow Menu ? (y/n)";
		cin >> choise2;
	} while (choise2 == 'y' || choise2 == 'Y');
}
void MenuMember() {
	int choise, choise3;
	char choise2;
	do {
		system("cls");
		cout << "\n\n\t         Member Management            ";
		cout << "\n\t ____________________________________";
		cout << "\n\t|          1.  BORROW               |";
		cout << "\n\t|          2.  SEARCH               |";
		cout << "\n\t|          3.  REPORT               |";
		cout << "\n\t|          4.  Exit                 |";
		cout << "\n\t|___________________________________|";
		cout << "\n\n\t your choise ==> ";
		cin >> choise;

		switch (choise)
		{
		case 1:
		{
			getdata_borrow();
			break;
		}
		case 2:
		{
			system("cls");
			cout << "\n\n\t            SEARCH MENU            ";
			cout << "\n\t ______________________________________";
			cout << "\n\t|          1.  Search Book            |";
			cout << "\n\t|          2.  Search Magazine        |";
			cout << "\n\t|          3.  Search Thesis          |";
			cout << "\n\t|          4.  Back to Menu           |";
			cout << "\n\t|_____________________________________|";
			cout << "\n\n\t your choise ==> ";
			cin >> choise3;

			switch (choise3)
			{
			case 1:
			{
				report_One_book();
				break;
			}
			case 2:
			{
				report_One_magazine();
				break;
			}
			case 3:
			{
				report_One_thesis();
				break;
			}
			default:
				break;
			}
			break;
		}
		case 3:
		{
			system("cls");
			cout << "\n\n\t            REPORT MENU            ";
			cout << "\n\t ______________________________________";
			cout << "\n\t|          1.  Report Book            |";
			cout << "\n\t|          2.  Report Magazine        |";
			cout << "\n\t|          3.  Report Thesis          |";
			cout << "\n\t|          4.  Back to Menu           |";
			cout << "\n\t|_____________________________________|";
			cout << "\n\n\t your choise ==> ";
			cin >> choise3;

			switch (choise3)
			{
			case 1:
			{
				report_All_book();
				break;
			}
			case 2:
			{
				report_All_magazine();
				break;
			}
			case 3:
			{
				report_All_thesis();
				break;
			}
			default:
				break;
			}
			break;
		}

		default:
			break;
		}

		cout << "\n\n\t#### Are you back to Member Management ? (y/n)";
		cin >> choise2;
	} while (choise2 == 'y' || choise2 == 'Y');


}
void MenuLibrarian() {
	int choise;
	char choise2;
	do {
		system("cls");
		cout << "\n\n\t        Librarian Management            ";
		cout << "\n\t ____________________________________";
		cout << "\n\t|          1.  BOOK                 |";
		cout << "\n\t|          2.  MAGAZINE             |";
		cout << "\n\t|          3.  THESIS               |";
		cout << "\n\t|          4.  MEMBERS              |";
		cout << "\n\t|          5.  LIBRARIAN            |";
		cout << "\n\t|          6.  BORROW               |";
		cout << "\n\t|          7.  Exit                 |";
		cout << "\n\t|___________________________________|";
		cout << "\n\n\t your choise ==> ";
		cin >> choise;

		switch (choise)
		{
		case 1:
		{
			book_menu();  break;
		}
		case 2:
		{
			magazine_menu();  break;
		}
		case 3:
		{
			thesis_menu();  break;
		}
		case 4:
		{
			member_menu();  break;
		}
		case 5:
		{
			librarian_menu();  break;
		}
		case 6:
		{
			borrow_menu();
			break;
		}

		}

		cout << "\n\n\t#### Are you back to  Librarian Management ? (y/n)";
		cin >> choise2;
	} while (choise2 == 'y' || choise2 == 'Y');
}
void MAIN_MENU() {

	int choise;
	char choise2;
	do {
		system("cls");
		cout << "\n\t|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|";
		cout << "\n\t|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|";
		cout << "\n\n\t\t\t\tWELCOME TO UNIVERSITY SYSTEM";
		cout << "\n\n\t|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|/\\|";
		cout << "\n\t|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|\\/|";
		cout << "\n\n\n\t\t\t               MAIN MENU            ";
		cout << "\n\t\t\t    ___________________________________";
		cout << "\n\t\t\t   |          1.  MEMBER               |";
		cout << "\n\t\t\t   |          2.  LIBRARIAN            |";
		cout << "\n\t\t\t   |          4.  Exit                 |";
		cout << "\n\t\t\t   |___________________________________|";
		cout << "\n\n\t\t\t    your choise ==> ";
		cin >> choise;
		switch (choise)
		{
		case 1:
		{
			password_member();

			break;
		}
		case 2:
		{

			password_librarian();
			break;
		}
		default:
			break;
		}

		cout << "\n\n\t#### Are you back to Main Menu ? (y/n)";
		cin >> choise2;
	} while (choise2 == 'y' || choise2 == 'Y');

}


void getdata_book() {
	book newb;
	string ID, title, kind, numpage, num, stock;
	f_book.open("book.csv", fstream::app);

	if (!f_book.is_open())
		cout << "fbook Error !";


	cout << "\n\tTitle : ";
	cin >> title;

	if (test_book_title(title) == 0) {

		newb.set_title(title);

		cout << "\n\tID : ";
		cin >> ID;
		newb.set_ID(ID);

	START1:
		try {
			numpage.clear();
			cout << "\n\tPages Number : ";
			cin >> numpage;
			newb.set_numpage(numpage);
		}
		catch (string msg) {
			cout << msg;
			goto START1;
		}


	START2:
		try {
			num.clear();
			cout << "\n\tNumber : ";
			cin >> num;
			newb.set_num(num);
		}
		catch (string msg) {
			cout << msg;
			goto START2;
		}


	START3:
		try {
			stock.clear();
			cout << "\n\tStock : ";
			cin >> stock;
			newb.set_stock(stock);
		}
		catch (string msg) {
			cout << msg;
			goto START3;
		}


	START4:
		try {
			kind.clear();
			cout << "\n\tKind ( Engineering or  Sience or Theology or Literature or Other ): ";
			cin >> kind;
			newb.set_kind(kind);
		}
		catch (string msg) {
			cout << msg;
			goto START4;
		}

		f_book << newb;

		vec_book.push_back(newb);

	}

	else
	{
		Add_number_book_title(title);
	}

	f_book.close();
}
void getdata_thesis() {

	string ID, title, degree, college, group, numpage, num, stock;
	thesis thesis;

	f_thesis.open("thesis.csv", fstream::app);
	if (!f_thesis.is_open())
		cout << "f_thesis Error !";


	cout << "\n\tTitle : ";
	cin >> title;
	thesis.set_title(title);

	cout << "\n\tID : ";
	cin >> ID;
	thesis.set_ID(ID);



START1:
	try {
		numpage.clear();
		cout << "\n\tPages Number : ";
		cin >> numpage;
		thesis.set_numpage(numpage);
	}
	catch (string msg) {
		cout << msg;
		goto START1;
	}

START2:
	try {
		num.clear();
		cout << "\n\tNumber (0 or 1): ";
		cin >> num;
		if (num == "1" || num == "0") {
			thesis.set_num(num);
		}
		else
		{
			cout << "\n\t** Magazine Number is 0 or 1 .";
			goto START2;
		}
	}
	catch (string msg) {
		cout << msg;
		goto START2;
	}


START3:
	try {
		stock.clear();
		cout << "\n\tStock (0 or 1): ";
		cin >> stock;
		if (stock == "1" || stock == "0") {
			thesis.set_stock(stock);
		}
		else
		{
			cout << "\n\t** Magazine Stock is 0 or 1 .";
			goto START3;
		}
	}
	catch (string msg) {
		cout << msg;
		goto START3;
	}

START4:
	try {
		degree.clear();
		cout << "\n\tDegree : ";
		cin >> degree;
		thesis.set_degree(degree);
	}
	catch (string msg) {
		cout << msg;
		goto START4;
	}


START5:
	try {
		group.clear();
		cout << "\n\tGroup : ";
		cin >> group;
		thesis.set_group(group);
	}
	catch (string msg) {
		cout << msg;
		goto START5;
	}

START6:
	try {
		college.clear();
		cout << "\n\tCollege : ";
		cin >> college;
		thesis.set_college(college);
	}
	catch (string msg) {
		cout << msg;
		goto START6;
	}

	f_thesis << thesis;

	vec_thesis.push_back(thesis);

	f_thesis.close();
}
void getdata_magazine() {

	string ID, title, degree, college, group, numpage, num, stock;
	magazine magazine;


	cout << "\n\tTitle : ";
	cin >> title;
	if (test_book_title(title) == 0) {

		f_magazine.open("magazine.csv", fstream::app);
		if (!f_magazine.is_open())
			cout << "f_magazine Error !";

		magazine.set_title(title);

		cout << "\n\tID : ";
		cin >> ID;
		magazine.set_ID(ID);


	START1:
		try {
			numpage.clear();
			cout << "\n\tPages Number : ";
			cin >> numpage;
			magazine.set_numpage(numpage);
		}
		catch (string msg) {
			cout << msg;
			goto START1;
		}


	START2:
		try {
			num.clear();
			cout << "\n\tNumber : ";
			cin >> num;
			magazine.set_num(num);
		}
		catch (string msg) {
			cout << msg;
			goto START2;
		}


	START3:
		try {
			stock.clear();
			cout << "\n\tStock : ";
			cin >> stock;
			magazine.set_stock(stock);
		}
		catch (string msg) {
			cout << msg;
			goto START3;
		}

		f_magazine << magazine;
		vec_magazine.push_back(magazine);
		f_magazine.close();
	}
	else
		Add_number_magazine(title);
}
void getdata_member() {

	string ID, name, family, type, nationalnum, day, month, year, stunum, fine, level;
	member m;

	f_member.open("member.csv", fstream::app | fstream::out);



	cout << "\n\tID : ";
	cin >> ID;

	if (test_member_Employee(ID) == true || test_member_Student(ID) == true) {
		m.set_ID(ID);

	START1:
		try {
			name.clear();
			cout << "\n\tName : ";
			cin >> name;
			m.set_name(name);
		}
		catch (string msg) {
			cout << msg;
			goto START1;
		}


	START2:
		try {
			family.clear();
			cout << "\n\tFamily : ";
			cin >> family;
			m.set_family(family);
		}
		catch (string msg) {
			cout << msg;
			goto START2;
		}


	START3:
		try {
			day.clear();
			cout << "\n\tBirth day: ";
			cin >> day;
			m.set_birthday(day);
		}
		catch (string msg) {
			cout << msg;
			goto START3;
		}

	START4:
		try {
			month.clear();
			cout << "\n\tBirth month: ";
			cin >> month;
			m.set_birthmonth(month);
		}
		catch (string msg) {
			cout << msg;
			goto START4;
		}

	START5:
		try {
			year.clear();
			cout << "\n\tBirth year: ";
			cin >> year;
			m.set_birthyear(year);
		}
		catch (string msg) {
			cout << msg;
			goto START5;
		}

	START6:
		try {
			nationalnum.clear();
			cout << "\n\tNational Number : ";
			cin >> nationalnum;
			m.set_nationalnum(nationalnum);
		}
		catch (string msg) {
			cout << msg;
			goto START6;
		}


	START7:
		try {
			type.clear();
			cout << "\n\tType (Student or Staff): ";
			cin >> type;
			m.set_type(type);
		}
		catch (string msg) {
			cout << msg;
			goto START7;
		}

	START8:
		try {
			type.clear();
			cout << "\n\tLevel (Baccalaureate or Postgraduate or PhD): ";
			cin >> level;
			m.set_level(level);
		}
		catch (string msg) {
			cout << msg;
			goto START8;
		}


	START9:
		try {
			stunum.clear();
			cout << "\n\tStudent Number : ";
			cin >> stunum;
			m.set_stunum(stunum);
		}
		catch (string msg) {
			cout << msg;
			goto START9;
		}



		f_member << m;
		vec_member.push_back(m);
		f_member.close();
	}


	else
		cout << "\n\n\t*** This Member does not exist in university system.";


}
void getdata_librarian() {

	string ID, name, family, evidence, nationalnum, post, day, month, year;

	librarian librarian;


	f_librarian.open("librarian.csv", fstream::app);
	if (!f_librarian.is_open())
		cout << "f_librarian Error !";

	cout << "\n\tID : ";
	cin >> ID;
	librarian.set_ID(ID);


START1:
	try {
		name.clear();
		cout << "\n\tName : ";
		cin >> name;
		librarian.set_name(name);
	}
	catch (string msg) {
		cout << msg;
		goto START1;
	}

START2:
	try {
		family.clear();
		cout << "\n\tFamily : ";
		cin >> family;
		librarian.set_family(family);
	}
	catch (string msg) {
		cout << msg;
		goto START2;
	}


START3:
	try {
		day.clear();
		cout << "\n\tBirth day: ";
		cin >> day;
		librarian.set_birthday(day);
	}
	catch (string msg) {
		cout << msg;
		goto START3;
	}


START4:
	try {
		month.clear();
		cout << "\n\tBirth month: ";
		cin >> month;
		librarian.set_birthmonth(month);
	}
	catch (string msg) {
		cout << msg;
		goto START4;
	}


START5:
	try {
		year.clear();
		cout << "\n\tBirth year: ";
		cin >> year;
		librarian.set_birthyear(year);
	}
	catch (string msg) {
		cout << msg;
		goto START5;
	}


START6:
	try {
		nationalnum.clear();
		cout << "\n\tNational Number : ";
		cin >> nationalnum;
		librarian.set_nationalnum(nationalnum);
	}
	catch (string msg) {
		cout << msg;
		goto START6;
	}


START7:
	try {
		evidence.clear();
		cout << "\n\tEvidence : ";
		cin >> evidence;
		librarian.set_evidence(evidence);
	}
	catch (string msg) {
		cout << msg;
		goto START7;
	}


START8:
	try {
		post.clear();
		cout << "\n\tPost (Normal or Administrator) : ";
		cin >> post;
		librarian.set_post(post);
	}
	catch (string msg) {
		cout << msg;
		goto START8;
	}



	f_librarian << librarian;
	vec_librarian.push_back(librarian);
	f_librarian.close();

}
void getdata_borrow()
{

	int dayB = 0, monthB = 0, yearB = 0, dayD = 0, monthD = 0, yearD = 0;
	string memberID, writID;
	borrow borrow;

	f_borrow.open("borrow.csv", fstream::app);
	if (!f_borrow.is_open())
		cout << "f_borrow Error !";



	cout << "\n\tWriting ID : ";
	cin >> writID;

	if (test_book_ID(writID) == "book" || test_magazine_ID(writID) == "magazine" || test_thesis_ID(writID) == "thesis")
	{

		borrow.set_writID(writID);


		cout << "\n\tMember ID : ";
		cin >> memberID;
		if (control_borrow_member(memberID) < 3) {

			borrow.set_memberID(memberID);

			cout << "\n\tBorrow Date  ";
			cout << "\n\t  Day:";
			cin >> dayB;
			cout << "\n\t  Month:";
			cin >> monthB;
			cout << "\n\t  Year:";
			cin >> yearB;
			borrow.set_dateB(dayB, monthB, yearB);


			date date(dayB, monthB, yearB);

			borrow.setdate(date_Delivery(date, test_level_member(memberID)));


			f_borrow << borrow;
			vec_borrow.push_back(borrow);
			f_borrow.close();

			if (test_book_ID(writID) == "book")
				decreas_book(writID);
			else if (test_magazine_ID(writID) == "magazine")
				decreas_magazine(writID);
			else if (test_thesis_ID(writID) == "thesis")
				decreas_thesis(writID);

			cout << "\n\n\t *** your loan has been successfully registered ***";

		}
		else
			cout << "\n\n\t** Member with " << memberID << " ID borrowed 3 writing .";



	}
	else
		cout << "\n\t This is not available";
}


void vecbook() {


	string line, word;

	f_book.open("book.csv");

	while (getline(f_book, line)) {

		int count = 0;
		book B;

		stringstream s(line);

		while (getline(s, word, ',')) {


			try {
				if (count == 0)
					B.set_ID(word);
				else if (count == 1)
					B.set_title(word);
				else if (count == 2)
					B.set_numpage(word);
				else if (count == 3)
					B.set_num(word);
				else if (count == 4)
				{
					B.set_stock(word);
				}
				else if (count == 5)
					B.set_kind(word);
				count++;
			}
			catch (string msg)
			{
				cout << msg;
			}
		}
		vec_book.push_back(B);
	}




	f_book.close();


}
void vecmagazine() {

	vector<string>vecma;

	string line, word;

	f_magazine.open("magazine.csv");


	while (getline(f_magazine, line)) {
		magazine magazine;
		int count = 0;
		stringstream s(line);

		while (getline(s, word, ',')) {
			try {

				if (count == 0)
					magazine.set_ID(word);
				else if (count == 1)
					magazine.set_title(word);
				else if (count == 2)
					magazine.set_numpage(word);
				else if (count == 3)
					magazine.set_num(word);
				else if (count == 4)
					magazine.set_stock(word);

				count++;
			}
			catch (string msg)
			{
				cout << msg;
			}
		}
		vec_magazine.push_back(magazine);
	}


	f_magazine.close();

}
void vecthesis() {

	string line, word;

	f_thesis.open("thesis.csv");


	while (getline(f_thesis, line)) {
		thesis thesis;
		int count = 0;

		stringstream s(line);

		while (getline(s, word, ',')) {

			try {
				if (count == 0)
					thesis.set_ID(word);
				else if (count == 1)
					thesis.set_title(word);
				else if (count == 2)
					thesis.set_numpage(word);
				else if (count == 3)
					thesis.set_num(word);
				else if (count == 4)
					thesis.set_stock(word);
				else if (count == 5)
					thesis.set_degree(word);
				else if (count == 6)
					thesis.set_college(word);
				else if (count == 7)
					thesis.set_group(word);

				count++;
			}
			catch (string msg)
			{
				cout << msg;
			}
		}
		vec_thesis.push_back(thesis);
	}



	f_thesis.close();
}
void veclibrarian() {

	string line, word;

	f_librarian.open("librarian.csv");



	while (getline(f_librarian, line)) {
		librarian librarian;
		int count = 0;

		stringstream s(line);

		while (getline(s, word, ',')) {

			try {
				if (count == 0)
					librarian.set_ID(word);
				else if (count == 1)
					librarian.set_name(word);
				else if (count == 2)
					librarian.set_family(word);
				else if (count == 3)
					librarian.set_birthday(word);
				else if (count == 4)
					librarian.set_birthmonth(word);
				else if (count == 5)
					librarian.set_birthyear(word);
				else if (count == 6)
					librarian.set_nationalnum(word);
				else if (count == 7)
					librarian.set_evidence(word);
				else if (count == 8)
					librarian.set_post(word);

				count++;
			}
			catch (string msg) {
				cout << msg;
			}
		}
		vec_librarian.push_back(librarian);
	}

	f_librarian.close();



}
void vecmember() {

	string line, word;


	f_member.open("member.csv");


	while (getline(f_member, line)) {
		member member;
		int count = 0;

		stringstream s(line);

		while (getline(s, word, ',')) {

			try {
				if (count == 0)
					member.set_ID(word);
				else if (count == 1)
					member.set_name(word);
				else if (count == 2)
					member.set_family(word);
				else if (count == 3)
					member.set_birthday(word);
				else if (count == 4)
					member.set_birthmonth(word);
				else if (count == 5)
					member.set_birthyear(word);
				else if (count == 6)
					member.set_nationalnum(word);
				else if (count == 7)
					member.set_type(word);
				else if (count == 8)
					member.set_level(word);
				else if (count == 9)
					member.set_stunum(word);
				else if (count == 10)
					member.set_fine(word);
				count++;
			}
			catch (string msg)
			{
				cout << " ";
			}
		}
		vec_member.push_back(member);
	}



	f_member.close();
}
void vecborrow() {

	int temp = 0;
	string line, word;


	f_borrow.open("borrow.csv");


	while (getline(f_borrow, line)) {
		borrow borrow;
		int w1, w2, w3, w4, w5, w6, count = 0;

		stringstream s(line);

		while (getline(s, word, ',')) {
			try {

				if (count == 0) {
					borrow.set_writID(word);
				}
				else if (count == 1) {
					borrow.set_memberID(word);
				}

				else if (count == 2)
				{
					w1 = stoi(word);
				}
				else if (count == 3) {
					w2 = stoi(word);
				}
				else if (count == 4) {
					w3 = stoi(word);
					borrow.set_dateB(w3, w2, w1);
				}


				else if (count == 5) {
					w4 = stoi(word);
				}
				else if (count == 6) {
					w5 = stoi(word);
				}
				else if (count == 7) {
					w6 = stoi(word);
					borrow.set_dateD(w6, w5, w4);
				}
				count++;
			}
			catch (string msg)
			{
				cout << msg;
			}

		}
		vec_borrow.push_back(borrow);
	}


	f_borrow.close();
}
void vecEmployee() {
	string line, word;

	f_University_employee.open("Employee.csv");
	if (!f_University_employee)
		cout << "!f_University_employee";

	while (getline(f_University_employee, line)) {
		Employee Employee;
		int count = 0;

		stringstream s(line);

		while (getline(s, word, ',')) {


			if (count == 0)
				Employee.setcodeEmployee(word);
			else if (count == 1)
				Employee.setName(word);
			else if (count == 2)
				Employee.setFamily(word);
			else if (count == 3)
				Employee.setPhone(word);
			else if (count == 4)
				Employee.setIDnum(word);
			else if (count == 5)
				Employee.setAge(word);

			count++;

		}
		vec_Employee.push_back(Employee);
	}

	f_University_employee.close();
}
void vecStudent() {
	string line, word;

	f_University_Student.open("Student.csv");
	if (!f_University_Student)
		cout << "!f_University_Student";


	while (getline(f_University_Student, line)) {
		Student Student;
		int count = 0;

		stringstream s(line);

		while (getline(s, word, ',')) {


			if (count == 0)
				Student.setIdnumber(word);
			else if (count == 1)
				Student.setName(word);
			else if (count == 2)
				Student.setFamily(word);
			else if (count == 3)
				Student.setPhone(word);
			else if (count == 4)
				Student.setIDnum(word);
			else if (count == 5)
				Student.setAge(word);
			else if (count == 6)
				Student.setgrade(word);

			count++;

		}
		vec_Student.push_back(Student);
	}

	f_University_Student.close();
}



void Edit_book(string ID) {

	int choise, temp = 0;
	string  title, kind, numpage, num, stock;

	f_book.open("book.csv");
	if (!f_book)
		cout << "f_book Error !";
	for (int i = 0;i < vec_book.size();i++)
	{
		if (vec_book[i].get_ID() == ID) {
			system("cls");
			cout << "\n\n\t________________________";
			cout << "\n\t|   1. ID               |";
			cout << "\n\t|   2. Title            |";
			cout << "\n\t|   3. Pages Number     |";
			cout << "\n\t|   4. Number           |";
			cout << "\n\t|   5. Stock            |";
			cout << "\n\t|   6. Kind             |";
			cout << "\n\t|   7. back to menu     |";
			cout << "\n\t|_______________________|";
			cout << "\n\n\t your choise ==> ";
			cin >> choise;

			try {
				switch (choise)
				{
				case 1:
				{
					cout << "\n\tID : ";
					cin >> ID;
					vec_book[i].set_ID(ID);

					break;
				}
				case 2:
				{
					cout << "\n\tTitle : ";
					cin >> title;
					vec_book[i].set_title(title);

					break;
				}
				case 3:
				{
					cout << "\n\tPages Number : ";
					cin >> numpage;
					vec_book[i].set_numpage(numpage);

					break;
				}
				case 4:
				{
					cout << "\n\tNumber : ";
					cin >> num;
					vec_book[i].set_num(num);

					break;
				}
				case 5:
				{
					cout << "\n\tStock : ";
					cin >> stock;
					vec_book[i].set_stock(stock);

					break;
				}
				case 6:
				{
					cout << "\n\tKind ( Engineering or  Sience or Theology or Literature or Other ): ";
					cin >> stock;
					vec_book[i].set_kind(kind);

					break;
				}
				case 7:
					break;

				}
			}
			catch (string msg)
			{
				cout << msg;
			}
			temp = 1;
		}


	}


	if (temp = 1) {
		ofstream Of_book;
		Of_book.open("book2.csv", ios::out);
		if (!Of_book)
			cout << "Of_book Error !";
		Of_book << vec_book;

		Of_book.close();
		f_book.close();


		if (remove("book.csv") != 0)
			cout << "errorin deleting original file!" << endl;
		if (rename("book2.csv", "book.csv") != 0)
			cout << "error in renaming output file!" << endl;

		cout << "\n\n\t*** Book with " << ID << " ID edited ***";
	}
	else if (temp = 0) {
		cout << "\n\t entered ID is not available !\n";
		f_book.close();
	}

}
void Edit_thesis(string ID) {

	int choise, temp = 0;
	string  title, kind, numpage, num, stock, degree, college, group;


	f_thesis.open("thesis.csv");
	if (!f_thesis)
		cout << "f_thesis Error !";
	for (int i = 0;i < vec_thesis.size();i++)
	{
		if (vec_thesis[i].get_ID() == ID) {
			system("cls");
			cout << "\n\n\t_______________________";
			cout << "\n\t|   1. ID               |";
			cout << "\n\t|   2. Title            |";
			cout << "\n\t|   3. Pages Number     |";
			cout << "\n\t|   4. Stock            |";
			cout << "\n\t|   5. Degree           |";
			cout << "\n\t|   6. College          |";
			cout << "\n\t|   7. Group            |";
			cout << "\n\t|   8. back to menu     |";
			cout << "\n\t|_______________________|";
			cout << "\n\n\t your choise ==> ";
			cin >> choise;

			try {
				switch (choise)
				{
				case 1:
				{
					cout << "\n\tID : ";
					cin >> ID;
					vec_thesis[i].set_ID(ID);
					break;
				}
				case 2:
				{
					cout << "\n\tTitle : ";
					cin >> title;
					vec_thesis[i].set_title(title);
					break;
				}
				case 3:
				{
					cout << "\n\tPages Number : ";
					cin >> numpage;
					vec_thesis[i].set_numpage(numpage);
					break;
				}
				case 4:
				{
					cout << "\n\tStock ( 0 or 1 ): ";
					cin >> stock;
					vec_thesis[i].set_stock(stock);

					break;
				}
				case 5:
				{
					cout << "\n\tDegree : ";
					cin >> degree;
					vec_thesis[i].set_degree(degree);

					break;
				}
				case 6:
				{
					cout << "\n\tCollege : ";
					cin >> college;
					vec_thesis[i].set_college(college);

					break;
				}
				case 7:
				{
					cout << "\n\tGroup : ";
					cin >> group;
					vec_thesis[i].set_group(group);

					break;
				}
				case 8:
					break;

				}

			}
			catch (string msg)
			{
				cout << msg;
			}temp = 1;
		}
	}


	if (temp = 1) {
		ofstream Of_thesis;
		Of_thesis.open("thesis2.csv", ios::out);
		if (!Of_thesis)
			cout << "Of_thesis Error !";
		Of_thesis << vec_thesis;

		Of_thesis.close();
		f_thesis.close();

		if (remove("thesis.csv") != 0)
			cout << "errorin deleting original file!" << endl;
		if (rename("thesis2.csv", "thesis.csv") != 0)
			cout << "error in renaming output file!" << endl;

		cout << "\n\n\t*** Thesis with " << ID << " ID edited ***";

	}
	else if (temp = 0) {
		cout << "\n\t entered ID is not available !\n";
		f_thesis.close();
	}

}
void Edit_magazine(string ID) {

	int choise, temp = 0;
	string  title, kind, numpage, num, stock;


	f_magazine.open("magazine.csv");
	if (!f_magazine)
		cout << "f_magazine Error !";
	for (int i = 0;i < vec_magazine.size();i++)
	{
		if (vec_magazine[i].get_ID() == ID) {
			system("cls");
			cout << "\n\n\t_______________________";
			cout << "\n\t|   1. ID               |";
			cout << "\n\t|   2. Title            |";
			cout << "\n\t|   3. Pages Number     |";
			cout << "\n\t|   4. Number           |";
			cout << "\n\t|   5. Stock            |";
			cout << "\n\t|   6. back to menu     |";
			cout << "\n\t|_______________________|";
			cout << "\n\n\t your choise ==> ";
			cin >> choise;

			try {
				switch (choise)
				{
				case 1:
				{
					cout << "\n\tID : ";
					cin >> ID;
					vec_magazine[i].set_ID(ID);
					break;
				}
				case 2:
				{
					cout << "\n\tTitle : ";
					cin >> title;
					vec_magazine[i].set_title(title);
					break;
				}
				case 3:
				{
					cout << "\n\tPages Number : ";
					cin >> numpage;
					vec_magazine[i].set_numpage(numpage);
					break;
				}
				case 4:
				{
					cout << "\n\tNumber : ";
					cin >> num;
					vec_magazine[i].set_num(num);
					break;
				}
				case 5:
				{
					cout << "\n\tStock : ";
					cin >> stock;
					vec_magazine[i].set_stock(stock);

					break;
				}
				case 6:
					break;

				}
			}
			catch (string msg)
			{
				cout << msg;
			}
			temp = 1;
		}
	}


	if (temp = 1) {
		ofstream Of_magazine;
		Of_magazine.open("magazine2.csv", ios::out);
		if (!Of_magazine)
			cout << "of_magazine Error !";
		Of_magazine << vec_magazine;

		Of_magazine.close();
		f_magazine.close();

		if (remove("magazine.csv") != 0)
			cout << "errorin deleting original file!" << endl;
		if (rename("magazine2.csv", "magazine.csv") != 0)
			cout << "error in renaming output file!" << endl;

		cout << "\n\n\t*** Magazine with " << ID << " ID edited ***";
	}
	else if (temp = 0) {
		cout << "\n\n\t entered ID is not available !\n";
		f_magazine.close();
	}

}
void Edit_member(string ID) {

	int choise, temp = 0;
	string  name, family, type, nationalnum, day, month, year, stunum, fine, level;

	f_member.open("member.csv");
	if (!f_member)
		cout << "f_member Error !";
	for (int i = 0;i < vec_member.size();i++)
	{
		if (vec_member[i].get_ID() == ID) {
			system("cls");
			cout << "\n\n\t________________________";
			cout << "\n\t|   1.  ID               |";
			cout << "\n\t|   2.  Name             |";
			cout << "\n\t|   3.  Family           |";
			cout << "\n\t|   4.  Type             |";
			cout << "\n\t|   5.  National Number  |";
			cout << "\n\t|   6.  BirthDay         |";
			cout << "\n\t|   7.  BirthMonth       |";
			cout << "\n\t|   8.  BirthYear        |";
			cout << "\n\t|   9.  Student Number   |";
			cout << "\n\t|   10. Level            |";
			cout << "\n\t|   11. Fine             |";
			cout << "\n\t|   12. Back To Menu     |";
			cout << "\n\t|________________________|";
			cout << "\n\n\t your choise ==> ";
			cin >> choise;
			try {
				switch (choise)
				{
				case 1:
				{
					cout << "\n\tID : ";
					cin >> ID;
					vec_member[i].set_ID(ID);
					break;
				}
				case 2:
				{
					cout << "\n\tName : ";
					cin >> name;
					vec_member[i].set_name(name);
					break;
				}
				case 3:
				{
					cout << "\n\tFamily : ";
					cin >> family;
					vec_member[i].set_family(family);
					break;
				}
				case 4:
				{
					cout << "\n\tType (Student or Staff): ";
					cin >> type;
					vec_member[i].set_type(type);
					break;
				}
				case 5:
				{
					cout << "\n\tNational Number : ";
					cin >> nationalnum;
					vec_member[i].set_nationalnum(nationalnum);

					break;
				}
				case 6:
				{
					cout << "\n\tBirthDay : ";
					cin >> day;
					vec_member[i].set_birthday(day);

					break;
				}
				case 7:
				{
					cout << "\n\tBirthMonth : ";
					cin >> month;
					vec_member[i].set_birthmonth(month);

					break;
				}
				case 8:
				{
					cout << "\n\tBirthYear : ";
					cin >> year;
					vec_member[i].set_birthyear(year);

					break;
				}
				case 9:
				{
					cout << "\n\tStudent Number : ";
					cin >> stunum;
					vec_member[i].set_stunum(stunum);

					break;
				}
				case 10:
				{
					cout << "\n\tLevel (Baccalaureate or Postgraduate or PhD): ";
					cin >> level;
					vec_member[i].set_level(level);

					break;
				}
				case 11:
				{
					cout << "\n\tFine : ";
					cin >> fine;
					vec_member[i].set_fine(fine);

					break;
				}
				case 12:
					break;

				}temp = 1;
			}
			catch (string msg) { cout << msg; }

		}

	}


	if (temp = 1) {
		ofstream Of_member;
		Of_member.open("member2.csv", ios::out);
		if (!Of_member)
			cout << "Of_member Error !";
		Of_member << vec_member;

		Of_member.close();
		f_member.close();

		if (remove("member.csv") != 0)
			cout << "errorin deleting original file!" << endl;
		if (rename("member2.csv", "member.csv") != 0)
			cout << "error in renaming output file!" << endl;

		cout << "\n\n\t*** Member with " << ID << " ID edited ***";
	}
	else if (temp = 0) {
		cout << "\n\n\t entered ID is not available !\n";
		f_member.close();
	}


}
void Edit_librarian(string ID) {

	int choise, temp = 0;
	string  name, family, evidence, nationalnum, post, day, month, year;

	f_librarian.open("librarian.csv");
	if (!f_librarian)
		cout << "f_librarian Error !";
	for (int i = 0;i < vec_librarian.size();i++)
	{
		if (vec_librarian[i].get_ID() == ID) {
			system("cls");
			cout << "\n\n\t________________________";
			cout << "\n\t|   1.  ID               |";
			cout << "\n\t|   2.  Name             |";
			cout << "\n\t|   3.  Family           |";
			cout << "\n\t|   4.  National Number  |";
			cout << "\n\t|   5.  BirthDay         |";
			cout << "\n\t|   6.  BirthMonth       |";
			cout << "\n\t|   7.  BirthYear        |";
			cout << "\n\t|   8.  Evidence         |";
			cout << "\n\t|   9.  Post             |";
			cout << "\n\t|   10. Back To Menu     |";
			cout << "\n\t|________________________|";
			cout << "\n\n\t your choise ==> ";
			cin >> choise;
			try {

				switch (choise)
				{
				case 1:
				{
					cout << "\n\tID : ";
					cin >> ID;
					vec_librarian[i].set_ID(ID);
					break;
				}
				case 2:
				{
					cout << "\n\tName : ";
					cin >> name;
					vec_librarian[i].set_name(name);
					break;
				}
				case 3:
				{
					cout << "\n\tFamily : ";
					cin >> family;
					vec_librarian[i].set_family(family);
					break;
				}
				case 4:
				{
					cout << "\n\tNational Number : ";
					cin >> nationalnum;
					vec_librarian[i].set_nationalnum(nationalnum);

					break;
				}
				case 5:
				{
					cout << "\n\tBirthDay : ";
					cin >> day;
					vec_librarian[i].set_birthday(day);

					break;
				}
				case 6:
				{
					cout << "\n\tBirthMonth : ";
					cin >> month;
					vec_librarian[i].set_birthmonth(month);

					break;
				}
				case 7:
				{
					cout << "\n\tBirthYear : ";
					cin >> year;
					vec_librarian[i].set_birthyear(year);

					break;
				}
				case 8:
				{
					cout << "\n\tEvidence : ";
					cin >> evidence;
					vec_librarian[i].set_evidence(evidence);

					break;
				}
				case 9:
				{
					cout << "\n\tPost : ";
					cin >> post;
					vec_librarian[i].set_post(post);

					break;
				}
				case 10:
					break;

				}
			}
			catch (string msg)
			{
				cout << msg;
			}
			temp = 1;
		}
	}


	if (temp = 1) {
		ofstream Of_librarian;
		Of_librarian.open("librarian2.csv", ios::out);
		if (!Of_librarian)
			cout << "Of_librarian Error !";
		Of_librarian << vec_librarian;

		Of_librarian.close();
		f_librarian.close();

		if (remove("librarian.csv") != 0)
			cout << "errorin deleting original file!" << endl;
		if (rename("librarian2.csv", "librarian.csv") != 0)
			cout << "error in renaming output file!" << endl;

		cout << "\n\n\t*** Librarian with " << ID << " ID edited ***";
	}
	else if (temp = 0) {
		cout << "\n\n\t entered ID is not available !\n";
		f_librarian.close();
	}

}
void Edit_borrow(string ID) {

	int temp = 0;
	f_borrow.open("borrow.csv");
	if (!f_borrow)
		cout << "f_borrow Error !";


	for (int i = 0;i < vec_borrow.size();i++) {
		if (vec_borrow[i].get_writID() == ID)
		{
			int n = 7;
			date s;
			s = vec_borrow[i].getdateborrow() + n;
			vec_borrow[i].setdate(s);

			ofstream of_borrow;
			of_borrow.open("borrow2.csv", ios::out);

			of_borrow << vec_borrow;

			of_borrow.close();
			f_borrow.close();


			if (remove("borrow.csv") != 0)
				cout << "errorin deleting original file!" << endl;
			if (rename("borrow2.csv", "borrow.csv") != 0)
				cout << "error in renaming output file!" << endl;

			cout << "\n\n\t*** Borrow with " << ID << " ID edited ***";
			temp = 1;

		}
	}

	if (temp == 0)cout << "\n\n\t entered ID is not available !\n";
}



//BOOK
void menu_report_book() {

	int choise;
	system("cls");
	cout << "\n\n\t         REPORT MENU          ";
	cout << "\n\t _________________________________";
	cout << "\n\t|        1.  All Reports          |";
	cout << "\n\t|        2.  One Report           |";
	cout << "\n\t|        3.  Engineering Group    |";
	cout << "\n\t|        4.  Sience Group         |";
	cout << "\n\t|        5.  Theology Group       |";
	cout << "\n\t|        6.  Literature Group     |";
	cout << "\n\t|        7.  Other Group          |";
	cout << "\n\t|        8.  Back                 |";
	cout << "\n\t|_________________________________|";
	cout << "\n\n\t your choise ==> ";
	cin >> choise;
	switch (choise)
	{
	case 1:
	{
		report_All_book(); break;
	}
	case 2:
	{
		report_One_book(); break;
	}
	case 3:
	{
		report_group_book(choise); break;
	}
	case 4:
	{
		report_group_book(choise); break;
	}
	case 5:
	{
		report_group_book(choise); break;
	}
	case 6:
	{
		report_group_book(choise); break;
	}
	case 7:
	{
		report_group_book(choise); break;
	}
	default:
		break;
	}
}
void report_All_book() {
	system("cls");
	cout << "\n   *********************************************************************************************************";
	cout << "\n       ID              TITLE              PAGES NUMBER          NUMBER          STOCK             KIND      ";
	cout << "\n   *********************************************************************************************************\n";

	for (int i = 0;i < vec_book.size();i++)
		cout << setw(8) << vec_book[i].get_ID() << setw(21) << vec_book[i].get_title() << setw(20) << vec_book[i].get_numpage() << setw(20) << vec_book[i].get_num() <<
		setw(16) << vec_book[i].get_stock() << setw(17) << vec_book[i].get_kind() << endl;

}
void report_One_book() {
	int temp = 0;
	string id;
	cout << "\n\t Enter Title Book : ";
	cin >> id;

	for (int i = 0;i < vec_book.size();i++)
	{

		if (vec_book[i].get_ID() == id) {
			system("cls");
			cout << "\n   *********************************************************************************************************";
			cout << "\n       ID              TITLE              PAGES NUMBER          NUMBER          STOCK             KIND   ";
			cout << "\n   *********************************************************************************************************\n";

			cout << setw(8) << vec_book[i].get_ID() << setw(21) << vec_book[i].get_title() << setw(20) << vec_book[i].get_numpage() << setw(20) << vec_book[i].get_num() <<
				setw(16) << vec_book[i].get_stock() << setw(17) << vec_book[i].get_kind() << endl;
			temp = 1;
		}

	}
	if (temp == 0)
		cout << "This Book is not available .";


}
void report_group_book(int c) {
	system("cls");
	cout << "\n   ***************************************************************************************";
	cout << "\n       ID              TITLE              PAGES NUMBER          NUMBER          STOCK     ";
	cout << "\n   ***************************************************************************************\n";
	if (c == 3) {
		for (int i = 0;i < vec_book.size();i++)
			if (vec_book[i].get_kind() == "Engineering" || vec_book[i].get_kind() == "engineering")
				cout << setw(8) << vec_book[i].get_ID() << setw(21) << vec_book[i].get_title() << setw(20) << vec_book[i].get_numpage() << setw(20) << vec_book[i].get_num() <<
				setw(16) << vec_book[i].get_stock() << endl;

	}
	if (c == 4) {
		for (int i = 0;i < vec_book.size();i++)
			if (vec_book[i].get_kind() == "Sience" || vec_book[i].get_kind() == "sience")
				cout << setw(8) << vec_book[i].get_ID() << setw(21) << vec_book[i].get_title() << setw(20) << vec_book[i].get_numpage() << setw(20) << vec_book[i].get_num() <<
				setw(16) << vec_book[i].get_stock() << endl;

	}
	if (c == 5) {
		for (int i = 0;i < vec_book.size();i++)
			if (vec_book[i].get_kind() == "Theology" || vec_book[i].get_kind() == "theology")
				cout << setw(8) << vec_book[i].get_ID() << setw(21) << vec_book[i].get_title() << setw(20) << vec_book[i].get_numpage() << setw(20) << vec_book[i].get_num() <<
				setw(16) << vec_book[i].get_stock() << endl;

	}
	if (c == 6) {
		for (int i = 0;i < vec_book.size();i++)
			if (vec_book[i].get_kind() == "Literature" || vec_book[i].get_kind() == "literature")
				cout << setw(8) << vec_book[i].get_ID() << setw(21) << vec_book[i].get_title() << setw(20) << vec_book[i].get_numpage() << setw(20) << vec_book[i].get_num() <<
				setw(16) << vec_book[i].get_stock() << endl;

	}
	if (c == 7) {
		for (int i = 0;i < vec_book.size();i++)
			if (vec_book[i].get_kind() == "Other" || vec_book[i].get_kind() == "other")
				cout << setw(8) << vec_book[i].get_ID() << setw(21) << vec_book[i].get_title() << setw(20) << vec_book[i].get_numpage() << setw(20) << vec_book[i].get_num() <<
				setw(16) << vec_book[i].get_stock() << endl;

	}
}
//MAGAZINE
void menu_report_magazine() {
	int choise;
	system("cls");
	cout << "\n\n\t         REPORT MENU          ";
	cout << "\n\t _________________________________";
	cout << "\n\t|        1.  All Reports          |";
	cout << "\n\t|        2.  One Report           |";
	cout << "\n\t|        3.  Back                 |";
	cout << "\n\t|_________________________________|";
	cout << "\n\n\t your choise ==> ";
	cin >> choise;
	switch (choise)
	{
	case 1:
	{
		report_All_magazine(); break;
	}
	case 2:
	{
		report_One_magazine(); break;
	}
	default:
		break;
	}
}
void report_All_magazine() {
	system("cls");
	cout << "\n   ***************************************************************************************";
	cout << "\n       ID              TITLE              PAGES NUMBER          NUMBER          STOCK     ";
	cout << "\n   ***************************************************************************************\n";

	for (int i = 0;i < vec_magazine.size();i++)
		cout << setw(8) << vec_magazine[i].get_ID() << setw(19) << vec_magazine[i].get_title() << setw(20) << vec_magazine[i].get_numpage() << setw(20)
		<< vec_magazine[i].get_num() << setw(16) << vec_magazine[i].get_stock() << endl;

}
void report_One_magazine() {
	int temp = 0;
	string id;
	cout << "\n\t Enter ID Magazine : ";
	cin >> id;

	for (int i = 0;i < vec_magazine.size();i++)
	{
		if (vec_book[i].get_ID() == id) {
			system("cls");
			cout << "\n   ***************************************************************************************";
			cout << "\n       ID              TITLE              PAGES NUMBER          NUMBER          STOCK     ";
			cout << "\n   ***************************************************************************************\n";
			for (int i = 0;i < vec_magazine.size();i++)
				cout << setw(8) << vec_magazine[i].get_ID() << setw(19) << vec_magazine[i].get_title() << setw(20) << vec_magazine[i].get_numpage() << setw(20)
				<< vec_magazine[i].get_num() << setw(16) << vec_magazine[i].get_stock() << endl;
			temp = 1;
		}

	}
	if (temp == 0)
		cout << "This Magazine is not available .";
}
//THESIS
void menu_report_thesis() {
	int choise;
	system("cls");
	cout << "\n\n\t         REPORT MENU          ";
	cout << "\n\t _________________________________";
	cout << "\n\t|        1.  All Reports          |";
	cout << "\n\t|        2.  One Report           |";
	cout << "\n\t|        3.  Back                 |";
	cout << "\n\t|_________________________________|";
	cout << "\n\n\t your choise ==> ";
	cin >> choise;
	switch (choise)
	{
	case 1:
	{
		report_All_thesis(); break;
	}
	case 2:
	{
		report_One_thesis(); break;
	}
	default:
		break;
	}
}
void report_All_thesis() {

	system("cls");
	cout << "\n   ********************************************************************************************************************************";
	cout << "\n       ID           TITLE           PAGES NUMBER          NUMBER          STOCK          DEGREE          COLLAGE          GROUP  ";
	cout << "\n   ********************************************************************************************************************************\n";

	for (int i = 0;i < vec_thesis.size();i++)
		cout << setw(8) << vec_thesis[i].get_ID() << setw(19) << vec_thesis[i].get_title() << setw(20) << vec_thesis[i].get_numpage()
		<< setw(16) << vec_thesis[i].get_num() << setw(16) << vec_thesis[i].get_stock() << setw(16) << vec_thesis[i].get_degree() << setw(16) <<
		vec_thesis[i].get_college() << setw(16) << vec_thesis[i].get_group() << endl;

}
void report_One_thesis() {
	int temp = 0;
	string id;
	cout << "\n\t Enter ID Thesis : ";
	cin >> id;

	for (int i = 0;i < vec_thesis.size();i++)
	{
		if (vec_thesis[i].get_ID() == id) {
			system("cls");
			cout << "\n   ********************************************************************************************************************************";
			cout << "\n       ID           TITLE           PAGES NUMBER          NUMBER          STOCK          DEGREE          COLLAGE          GROUP  ";
			cout << "\n   ********************************************************************************************************************************\n";

			for (int i = 0;i < vec_thesis.size();i++)
				cout << setw(8) << vec_thesis[i].get_ID() << setw(19) << vec_thesis[i].get_title() << setw(20) << vec_thesis[i].get_numpage()
				<< setw(16) << vec_thesis[i].get_num() << setw(16) << vec_thesis[i].get_stock() << setw(16) << vec_thesis[i].get_degree() << setw(16) <<
				vec_thesis[i].get_college() << setw(16) << vec_thesis[i].get_group() << endl;
			temp = 1;

		}

	}
	if (temp == 0)
		cout << "This Thesis is not available .";
}
//MEMBER
void menu_report_member() {
	int choise;
	system("cls");
	cout << "\n\n\t         REPORT MENU          ";
	cout << "\n\t __________________________________________";
	cout << "\n\t|        1.  All Reports                   |";
	cout << "\n\t|        2.  All Student Reports           |";
	cout << "\n\t|        3.  All Employee Reports          |";
	cout << "\n\t|        4.  Back                          |";
	cout << "\n\t|__________________________________________|";
	cout << "\n\n\t your choise ==> ";
	cin >> choise;
	switch (choise)
	{
	case 1:
	{
		report_All_member_Student();
		cout << endl << endl << endl << endl;
		report_All_member_Employee();

		break;
	}
	case 2:
	{
		report_All_member_Student();  break;
	}
	case 3:
	{
		report_All_member_Employee();  break;
	}
	default:
		break;
	}
}
void report_All_member_Student() {


	system("cls");
	cout << "\n   ********************************************************************************************************************************************************";
	cout << "\n       ID       NAME       FAMILY      BIRTHDATE      NATIONAL NUMBER       TYPE      LEVEL      STUDENT NUMBER      FINE      PHONE     AGE     GRADE ";
	cout << "\n   ********************************************************************************************************************************************************\n";


	for (int i = 0;i < vec_member.size();i++)
	{
		for (int j = 0;j < vec_Student.size();j++)
		{
			if (vec_member[i].get_ID() == vec_Student[j].getIdnumber()) {

				cout << setw(8) << vec_member[i].get_ID() << setw(13) << vec_member[i].get_name() << setw(13) << vec_member[i].get_family() << setw(8)
					<< vec_member[i].get_year() << "/" << setfill(' ') << setw(2) << vec_member[i].get_month() << "/" << setfill(' ') << setw(2) << vec_member[i].get_day()
					<< setw(15) << vec_member[i].get_nationalnum() << setw(16) << vec_member[i].get_type() << setw(13) << vec_member[i].get_level() << setw(16)
					<< vec_member[i].get_stunum() << setw(13) << vec_member[i].get_fine() << "  ";


				cout << setw(10) << vec_Student[j].getPhone() << setw(8) << vec_Student[j].getAge() << setw(8) << vec_Student[j].getgrade() << "\n\n";
			}
		}
	}
}
void report_One_member_Student() {
	int temp = 0;
	string id;
	cout << "\n\t Enter ID Member : ";
	cin >> id;

	for (int i = 0;i < vec_member.size();i++)
	{
		if (vec_member[i].get_ID() == id) {
			system("cls");
			cout << "\n   ********************************************************************************************************************************************************";
			cout << "\n       ID       NAME       FAMILY      BIRTHDATE      NATIONAL NUMBER       TYPE      LEVEL      STUDENT NUMBER      FINE      PHONE     AGE     GRADE ";
			cout << "\n   ********************************************************************************************************************************************************\n";



			for (int j = 0;j < vec_Student.size();j++)
			{
				if (vec_member[i].get_ID() == vec_Student[j].getIdnumber()) {

					cout << setw(8) << vec_member[i].get_ID() << setw(13) << vec_member[i].get_name() << setw(13) << vec_member[i].get_family() << setw(8)
						<< vec_member[i].get_year() << "/" << setfill(' ') << setw(2) << vec_member[i].get_month() << "/" << setfill(' ') << setw(2) << vec_member[i].get_day()
						<< setw(15) << vec_member[i].get_nationalnum() << setw(16) << vec_member[i].get_type() << setw(13) << vec_member[i].get_level() << setw(16)
						<< vec_member[i].get_stunum() << setw(13) << vec_member[i].get_fine() << "  ";


					cout << setw(10) << vec_Student[j].getPhone() << setw(8) << vec_Student[j].getAge() << setw(8) << vec_Student[j].getgrade() << "\n\n";
				}
			}

			temp = 1;
		}

	}



	if (temp == 0)
		cout << "This Member is not available .";
}
void report_All_member_Employee() {


	system("cls");
	cout << "\n   *********************************************************************************************************************************************";
	cout << "\n       ID       NAME       FAMILY      BIRTHDATE      NATIONAL NUMBER       TYPE      LEVEL      STUDENT NUMBER      FINE      PHONE     AGE  ";
	cout << "\n   *********************************************************************************************************************************************\n";

	for (int i = 0;i < vec_member.size();i++)
	{
		for (int j = 0;j < vec_Employee.size();j++)
		{
			if (vec_member[i].get_ID() == vec_Employee[j].getcodeEmployee()) {

				cout << setw(8) << vec_member[i].get_ID() << setw(13) << vec_member[i].get_name() << setw(13) << vec_member[i].get_family() << setw(8)
					<< vec_member[i].get_year() << "/" << setfill(' ') << setw(2) << vec_member[i].get_month() << "/" << setfill(' ') << setw(2) << vec_member[i].get_day()
					<< setw(15) << vec_member[i].get_nationalnum() << setw(16) << vec_member[i].get_type() << setw(13) << vec_member[i].get_level() << setw(16)
					<< vec_member[i].get_stunum() << setw(13) << vec_member[i].get_fine() << "  ";


				cout << setw(10) << vec_Employee[j].getPhone() << setw(8) << vec_Employee[j].getAge() << "\n\n";
			}
		}
	}
}
void report_One_member_Employee() {
	int temp = 0;
	string id;
	cout << "\n\t Enter ID Member : ";
	cin >> id;

	for (int i = 0;i < vec_member.size();i++)
	{
		if (vec_member[i].get_ID() == id) {
			system("cls");
			cout << "\n   *************************************************************************************************************************************************";
			cout << "\n       ID       NAME       FAMILY      BIRTHDATE      NATIONAL NUMBER       TYPE      LEVEL      STUDENT NUMBER       FINE       PONE        AGE       ";
			cout << "\n   *************************************************************************************************************************************************\n";


			for (int j = 0;j < vec_Employee.size();j++)
			{
				if (vec_member[i].get_ID() == vec_Employee[j].getcodeEmployee()) {

					cout << setw(8) << vec_member[i].get_ID() << setw(13) << vec_member[i].get_name() << setw(13) << vec_member[i].get_family() << setw(8)
						<< vec_member[i].get_year() << "/" << setfill(' ') << setw(2) << vec_member[i].get_month() << "/" << setfill(' ') << setw(2) << vec_member[i].get_day()
						<< setw(15) << vec_member[i].get_nationalnum() << setw(16) << vec_member[i].get_type() << setw(13) << vec_member[i].get_level() << setw(16)
						<< vec_member[i].get_stunum() << setw(13) << vec_member[i].get_fine() << "  ";


					cout << setw(10) << vec_Employee[j].getPhone() << setw(8) << vec_Employee[j].getAge() << "\n\n";
				}
			}
		}

		temp = 1;
	}


	if (temp == 0)
		cout << "This Member is not available .";
}
//LIBRARIAN
void menu_report_librarian() {
	int choise;
	system("cls");
	cout << "\n\n\t         REPORT MENU          ";
	cout << "\n\t _________________________________";
	cout << "\n\t|        1.  All Reports          |";
	cout << "\n\t|        2.  One Report           |";
	cout << "\n\t|        3.  Back                 |";
	cout << "\n\t|_________________________________|";
	cout << "\n\n\t your choise ==> ";
	cin >> choise;
	switch (choise)
	{
	case 1:
	{
		report_All_librarian(); break;
	}
	case 2:
	{
		report_One_librarian(); break;
	}
	default:
		break;
	}
}
void report_All_librarian() {
	system("cls");
	cout << "\n   ********************************************************************************************************************";
	cout << "\n       ID         NAME         FAMILY        BIRTHDATE         NATIONAL NUMBER             EVIDENCE           POST  ";
	cout << "\n   ********************************************************************************************************************\n";

	for (int i = 0;i < vec_librarian.size();i++)
		cout << setw(8) << vec_librarian[i].get_ID() << setw(17) << vec_librarian[i].get_name() << setw(17) << vec_librarian[i].get_family() << setw(16)
		<< vec_librarian[i].get_year() << "/" << vec_librarian[i].get_month() << "/" << vec_librarian[i].get_day() <<
		setw(16) << vec_librarian[i].get_evidence() << setw(16) << vec_librarian[i].get_post() << endl;
}
void report_One_librarian() {
	int temp = 0;
	string id;
	cout << "\n\t Enter ID Librarian : ";
	cin >> id;

	for (int i = 0;i < vec_librarian.size();i++)
	{
		if (vec_librarian[i].get_ID() == id) {
			system("cls");
			cout << "\n   ********************************************************************************************************************";
			cout << "\n       ID         NAME         FAMILY        BIRTHDATE         NATIONAL NUMBER             EVIDENCE           POST  ";
			cout << "\n   ********************************************************************************************************************\n";

			for (int i = 0;i < vec_librarian.size();i++)
				cout << setw(8) << vec_librarian[i].get_ID() << setw(17) << vec_librarian[i].get_name() << setw(17) << vec_librarian[i].get_family() << setw(16)
				<< vec_librarian[i].get_year() << "/" << vec_librarian[i].get_month() << "/" << vec_librarian[i].get_day() <<
				setw(16) << vec_librarian[i].get_evidence() << setw(16) << vec_librarian[i].get_post() << endl;
			temp = 1;
		}

	}
	if (temp == 0)
		cout << "This Librarian is not available .";
}
//BORROW
void menu_search_borrow() {
	int choise;
	system("cls");
	cout << "\n\n\t          SEARCH MENU          ";
	cout << "\n\t ____________________________________";
	cout << "\n\t|        1.  Search by writeID       |";
	cout << "\n\t|        2.  Search by mamberID      |";
	cout << "\n\t|        3.  Back                    |";
	cout << "\n\t|____________________________________|";
	cout << "\n\n\t your choise ==> ";
	cin >> choise;
	switch (choise)
	{
	case 1:
	{
		search_by_writID();
		break;
	}
	case 2:
	{
		search_by_memberID();
		break;
	}
	default:
		break;
	}
}
void search_by_writID() {

	string writeID;
	cout << "\n\t Enter Write ID : ";
	cin >> writeID;
	system("cls");
	cout << "\n\n      ***************************";
	cout << "\n\t        " << writeID;
	cout << "\n      ***************************\n";

	for (int i = 0;i < vec_borrow.size();i++) {
		if (vec_borrow[i].get_writID() == writeID) {
			for (int j = 0;j < vec_member.size();j++)
				if (vec_member[j].get_ID() == vec_borrow[i].get_memberID())
					cout << "\t" << vec_borrow[i].get_memberID() << "    " << vec_member[j].get_name() << " " << vec_member[j].get_family() << endl;
		}
	}

}
void search_by_memberID() {

	string memberID;
	cout << "\n\t Enter Member ID : ";
	cin >> memberID;
	system("cls");
	cout << "\n\n      ***************************";
	cout << "\n\t        " << memberID;
	cout << "\n      ***************************\n";

	for (int i = 0;i < vec_borrow.size();i++) {
		if (vec_borrow[i].get_memberID() == memberID) {
			for (int j = 0;j < vec_book.size();j++)
				if (vec_book[j].get_ID() == vec_borrow[i].get_writID())
					cout << "\t " << vec_book[j].get_ID() << "   " << vec_book[j].get_title() << endl;
		}
	}

}
void report_borrow_by_DeliveryDate() {

	int day, month, year;

	cout << "\n\tEnter Delivery Date";
	cout << "\n\t  Day:";
	cin >> day;
	cout << "\n\t  Month:";
	cin >> month;
	cout << "\n\t  Year:";
	cin >> year;
	system("cls");
	cout << "\n\n      ***************************";
	cout << "\n\t        " << year << "/" << setfill(' ') << setw(2) << month << "/" << setfill(' ') << setw(2) << day;
	cout << "\n      ***************************\n";


	for (int i = 0;i < vec_borrow.size();i++) {

		if (vec_borrow[i].getdayD() == day && vec_borrow[i].getmonthD() == month && vec_borrow[i].getyearD() == year) {
			cout << "\t\t" << vec_borrow[i].get_memberID() << "    " << vec_borrow[i].get_writID() << endl;
		}
	}

}
void report_All_borrow() {

	system("cls");
	cout << "\n\t   ***************************************************************************";
	cout << "\n\t       MEMBER ID           WRITE ID         BOROOW DATE         DELIVERYDATE";
	cout << "\n\t   ***************************************************************************\n";

	for (int i = 0;i < vec_borrow.size();i++) {


		cout << setw(15) << vec_borrow[i].get_memberID() << setw(13) << vec_borrow[i].get_writID() << setw(13) << vec_borrow[i].getyearB()<<
			"/" << vec_borrow[i].getmonthB()<<"/"<< vec_borrow[i].getdayB() << setw(13)<< vec_borrow[i].getyearD() <<
			"/" << vec_borrow[i].getmonthD() << "/" << vec_borrow[i].getdayD()<<endl;

	}

}



void fine(string ID) {
	f_borrow.open("borrow.csv");
	if (!f_borrow)
		cout << "f_borrow Error !";

	int d = 0, m = 0, y = 0;
	int mt, mb;
	cout << "\n\tToday Date  ";
	cout << "\n\t  Day:";
	cin >> d;
	cout << "\n\t  Month:";
	cin >> m;
	cout << "\n\t  Year:";
	cin >> y;

	date today(d, m, y);


	for (int i = 0;i < vec_borrow.size();i++) {

		if (vec_borrow[i].get_memberID() == ID) {


			if (today.getMonth() < 7) mt = 31;
			else mt = 30;

			if (vec_borrow[i].getmonthD() < 7)mb = 31;
			else mb = 30;

			long int daysDelivery = convert_to_day(vec_borrow[i].getdayD(), vec_borrow[i].getmonthD(), vec_borrow[i].getyearD(), mb);
			long int daysToday = convert_to_day(today.getDay(), today.getMonth(), today.getYear(), mt);


			if (daysDelivery >= daysToday)
				cout << "\n\t ** Delivery date has not yet passed **";
			else
			{
				long int fine;

				fine = (daysToday - daysDelivery) * 500;

				for (int i = 0;i < vec_member.size();i++)
					if (vec_member[i].get_ID() == ID)
					{
						try {
							vec_member[i].set_fine(to_string(fine));
						}
						catch (string msg)
						{
							cout << msg;
						}
					}

				cout << "\n\t**** You have to pay " << fine << "tomans for the fine ";


				ofstream Of_member;
				Of_member.open("member2.csv", ios::out);
				if (!Of_member)
					cout << "Of_member Error !";
				Of_member << vec_member;

				Of_member.close();
				f_member.close();

				if (remove("member.csv") != 0)
					cout << "errorin deleting original file!" << endl;
				if (rename("member2.csv", "member.csv") != 0)
					cout << "error in renaming output file!" << endl;
			}
		}
		else
			cout << "\n\t ** There is no member with this ID.";
	}
}


void delete_book(string ID) {
	int choise, temp = 0;
	string  title, kind, numpage, num, stock;

	f_book.open("book.csv");
	if (!f_book)
		cout << "f_book Error !";


	for (int i = 0;i < vec_book.size();i++)
		if (vec_book[i].get_ID() == ID)
		{
			vec_book.erase(vec_book.begin() + i);
			temp = 1;
		}

	if (temp = 1) {
		ofstream Of_book;
		Of_book.open("book2.csv", ios::out);
		if (!Of_book)
			cout << "Of_book Error !";

		Of_book << vec_book;

		Of_book.close();
		f_book.close();

		if (remove("book.csv") != 0)
			cout << "errorin deleting original file!" << endl;
		if (rename("book2.csv", "book.csv") != 0)
			cout << "error in renaming output file!" << endl;

		cout << "\n\t*** Book whit ID " << ID << " deleted .****";


	}
	else if (temp = 0) {
		cout << "\n\n\t entered ID is not available !\n";
		f_book.close();
	}
}
void delete_magazine(string ID) {
	int choise, temp = 0;
	string  title, kind, numpage, num, stock;

	f_magazine.open("magazine.csv");
	if (!f_magazine)
		cout << "f_magazine Error !";


	for (int i = 0;i < vec_magazine.size();i++)
		if (vec_magazine[i].get_ID() == ID)
		{
			vec_magazine.erase(vec_magazine.begin() + i);
			temp = 1;
		}

	if (temp = 1) {
		ofstream of_magazine;
		of_magazine.open("magazine2.csv", ios::out);
		if (!of_magazine)
			cout << "Of_magazine Error !";

		of_magazine << vec_magazine;

		of_magazine.close();
		f_magazine.close();

		if (remove("magazine.csv") != 0)
			cout << "errorin deleting original file!" << endl;
		if (rename("magazine2.csv", "magazine.csv") != 0)
			cout << "error in renaming output file!" << endl;

		cout << "\n\t*** Mgazine whit ID " << ID << " deleted .****";

	}
	else if (temp = 0) {
		cout << "\n\n\t entered ID is not available !\n";
		f_magazine.close();
	}
}
void delete_thesis(string ID) {
	int choise, temp = 0;
	string  title, kind, numpage, num, stock, degree, college, group;

	f_thesis.open("thesis.csv");
	if (!f_thesis)
		cout << "f_thesis Error !";


	for (int i = 0;i < vec_thesis.size();i++)
		if (vec_thesis[i].get_ID() == ID)
		{
			vec_thesis.erase(vec_thesis.begin() + i);
			temp = 1;
		}

	if (temp = 1) {
		ofstream Of_thesis;
		Of_thesis.open("thesis2.csv", ios::out);
		if (!Of_thesis)
			cout << "Of_thesis Error !";

		Of_thesis << vec_thesis;

		Of_thesis.close();
		f_thesis.close();

		if (remove("thesis.csv") != 0)
			cout << "errorin deleting original file!" << endl;
		if (rename("thesis2.csv", "thesis.csv") != 0)
			cout << "error in renaming output file!" << endl;


		cout << "\n\t*** Thesis whit ID " << ID << " deleted .***";

	}
	else if (temp = 0) {
		cout << "\n\n\t entered ID is not available !\n";
		f_thesis.close();
	}
}
void delete_member(string ID) {

	int choise, temp = 0;
	string  name, family, type, nationalnum, day, month, year, stunum, fine;

	f_member.open("member.csv");
	if (!f_member)
		cout << "f_member Error !";
	for (int i = 0;i < vec_member.size();i++)
	{
		if (vec_member[i].get_ID() == ID)
		{
			vec_member.erase(vec_member.begin() + i);
			temp = 1;
		}

	}


	if (temp = 1) {
		ofstream Of_member;
		Of_member.open("member2.csv", ios::out);
		if (!Of_member)
			cout << "Of_member Error !";
		Of_member << vec_member;

		Of_member.close();
		f_member.close();

		if (remove("member.csv") != 0)
			cout << "errorin deleting original file!" << endl;
		if (rename("member2.csv", "member.csv") != 0)
			cout << "error in renaming output file!" << endl;


		cout << "\n\t*** Member whit ID " << ID << " deleted .***";
	}
	else if (temp = 0) {
		cout << "\n\n\t entered ID is not available !\n";
		f_member.close();
	}

}
void delete_librarian(string ID) {

	int choise, temp = 0;
	string  name, family, evidence, nationalnum, post, day, month, year;

	f_librarian.open("librarian.csv");
	if (!f_librarian)
		cout << "f_librarian Error !";
	for (int i = 0;i < vec_librarian.size();i++)
	{
		if (vec_librarian[i].get_ID() == ID)
		{
			vec_librarian.erase(vec_librarian.begin() + i);
			temp = 1;
		}
	}


	if (temp = 1) {
		ofstream Of_librarian;
		Of_librarian.open("librarian2.csv", ios::out);
		if (!Of_librarian)
			cout << "Of_librarian Error !";
		Of_librarian << vec_librarian;

		Of_librarian.close();
		f_librarian.close();

		if (remove("librarian.csv") != 0)
			cout << "errorin deleting original file!" << endl;
		if (rename("librarian2.csv", "librarian.csv") != 0)
			cout << "error in renaming output file!" << endl;

		cout << "\n\t*** Librarian whit ID " << ID << " deleted .***";

	}
	else if (temp = 0) {
		cout << "\n\n\t entered ID is not available !\n";
		f_librarian.close();
	}

}
void delete_borrow(string writID) {

	int temp = 0;
	f_borrow.open("borrow.csv");
	if (test_book_ID(writID) == "book" || test_magazine_ID(writID) == "magazine" || test_thesis_ID(writID) == "thesis")
	{
		for (int i = 0;i < vec_borrow.size();i++)
		{

			if (vec_borrow[i].get_writID() == writID)
			{
				vec_borrow.erase(vec_borrow.begin() + i);



				if (test_book_ID(writID) == "book")
					Add_number_book_ID(writID);
				else if (test_magazine_ID(writID) == "magazine")
					Add_number_magazine_ID(writID);
				else if (test_thesis_ID(writID) == "thesis")
					Add_number_thesis_ID(writID);


				temp = 1;
			}
		}
	}

	if (temp = 1) {
		ofstream of_borrow;
		of_borrow.open("borrow2.csv", ios::out);
		if (!of_borrow)
			cout << "of_borrow Error !";
		of_borrow << vec_borrow;

		of_borrow.close();
		f_borrow.close();

		if (remove("borrow.csv") != 0)
			cout << "errorin deleting original file!" << endl;
		if (rename("borrow2.csv", "borrow.csv") != 0)
			cout << "error in renaming output file!" << endl;

		cout << "\n\t*** Borrow whit Wtite ID " << writID << " deleted .***";

	}
	else if (temp = 0) {
		cout << "\n\n\t entered WritID is not available !\n";
		f_borrow.close();
	}
}



int test_book_title(string title) {
	int temp = 0;
	for (int i = 0;i < vec_book.size();i++) {
		if (vec_book[i].get_title() == title)
			temp++;
	}
	return temp;
}
string test_book_ID(string writID) {
	string temp = "0";
	for (int i = 0;i < vec_book.size();i++) {
		if (vec_book[i].get_ID() == writID)
			temp = "book";
	}
	return temp;
}
string test_magazine_ID(string writID) {
	string temp = "0";
	for (int i = 0;i < vec_magazine.size();i++) {
		if (vec_magazine[i].get_ID() == writID)
			temp = "magazine";
	}
	return temp;
}
string test_thesis_ID(string writID) {
	string temp = "0";
	for (int i = 0;i < vec_thesis.size();i++) {
		if (vec_thesis[i].get_ID() == writID)
			temp = "thesis";
	}
	return temp;
}
int test_magazine(string title) {
	int temp = 0;
	for (int i = 0;i < vec_magazine.size();i++) {
		if (vec_magazine[i].get_title() == title)
			temp++;
	}
	return temp;
}
int control_borrow_member(string memberID) {
	int temp = 0;
	for (int i = 0;i < vec_borrow.size();i++) {
		if (vec_borrow[i].get_memberID() == memberID)
			temp++;
	}
	return temp;
}

bool test_member_Employee(string ID) {

	for (int i = 0;i < vec_Employee.size();i++) {
		if (vec_Employee[i].getcodeEmployee() == ID) {
			return true;
		}
	}

}
bool test_member_Student(string ID) {

	for (int i = 0;i < vec_Student.size();i++) {
		if (vec_Student[i].getIdnumber() == ID) {
			return true;
		}
	}

}



void Add_number_book_title(string title) {

	f_book.open("book.csv");


	for (int i = 0;i < vec_book.size();i++) {
		if (vec_book[i].get_title() == title)
		{
			string s;
			int n = 1;
			s = vec_book[i].get_num() + n;
			vec_book[i].set_num(s);

			ofstream Of_book;
			Of_book.open("book2.csv", ios::out);

			Of_book << vec_book;

			Of_book.close();
			f_book.close();


			if (remove("book.csv") != 0)
				cout << "errorin deleting original file!" << endl;
			if (rename("book2.csv", "book.csv") != 0)
				cout << "error in renaming output file!" << endl;
		}

	}

}
void Add_number_magazine_ID(string writID) {

	f_magazine.open("magazine.csv");

	try {
		for (int i = 0;i < vec_magazine.size();i++) {
			if (vec_magazine[i].get_ID() == writID)
			{
				string s;
				int n = 1;
				s = vec_magazine[i].get_stock() + n;
				vec_magazine[i].set_stock(s);

				ofstream Of_magazine;
				Of_magazine.open("magazine2.csv", ios::out);

				Of_magazine << vec_magazine;

				Of_magazine.close();
				f_magazine.close();


				if (remove("magazine.csv") != 0)
					cout << "errorin deleting original file!" << endl;
				if (rename("magazine2.csv", "magazine.csv") != 0)
					cout << "error in renaming output file!" << endl;
			}

		}
	}
	catch (string msg)
	{
		cout << msg;
	}

}
void Add_number_thesis_ID(string writID) {

	f_thesis.open("thesis.csv");

	try {
		for (int i = 0;i < vec_thesis.size();i++) {
			if (vec_thesis[i].get_ID() == writID)
			{
				string s;
				int n = 1;
				s = vec_thesis[i].get_stock() + n;
				vec_thesis[i].set_stock(s);

				ofstream Of_thesis;
				Of_thesis.open("thesis2.csv", ios::out);

				Of_thesis << vec_thesis;

				Of_thesis.close();
				f_thesis.close();


				if (remove("thesis.csv") != 0)
					cout << "errorin deleting original file!" << endl;
				if (rename("thesis2.csv", "thesis.csv") != 0)
					cout << "error in renaming output file!" << endl;
			}

		}
	}
	catch (string msg)
	{
		cout << msg;
	}

}
void Add_number_book_ID(string writID) {

	f_book.open("book.csv");

	try {
		for (int i = 0;i < vec_book.size();i++) {
			if (vec_book[i].get_ID() == writID)
			{
				string s;
				int n = 1;
				s = vec_book[i].get_stock() + n;
				vec_book[i].set_stock(s);

				ofstream Of_book;
				Of_book.open("book2.csv", ios::out);

				Of_book << vec_book;

				Of_book.close();
				f_book.close();


				if (remove("book.csv") != 0)
					cout << "errorin deleting original file!" << endl;
				if (rename("book2.csv", "book.csv") != 0)
					cout << "error in renaming output file!" << endl;
			}

		}
	}
	catch (string msg)
	{
		cout << msg;
	}

}
void Add_number_magazine(string title) {
	f_magazine.open("magazine.csv");
	try {
		for (int i = 0;i < vec_magazine.size();i++) {
			if (vec_magazine[i].get_title() == title)
			{
				string s = vec_magazine[i].get_num() + 1;
				vec_magazine[i].set_num(s);

				ofstream Of_magazine;
				Of_magazine.open("magazine2.csv", ios::out);

				Of_magazine << vec_magazine;

				Of_magazine.close();
				f_magazine.close();


				if (remove("magazine.csv") != 0)
					cout << "errorin deleting original file!" << endl;
				if (rename("magazine2.csv", "magazine.csv") != 0)
					cout << "error in renaming output file!" << endl;
			}

		}
	}
	catch (string msg)
	{
		cout << msg;
	}
}



void decreas_book(string writID) {
	f_book.open("book.csv");
	try {
		for (int i = 0;i < vec_book.size();i++) {
			if (vec_book[i].get_ID() == writID) {
				int n = 1;
				string s;
				s = vec_book[i].get_stock() - n;
				vec_book[i].set_stock(s);

				ofstream Of_book;
				Of_book.open("book2.csv", ios::out);

				Of_book << vec_book;

				Of_book.close();
				f_book.close();


				if (remove("book.csv") != 0)
					cout << "errorin deleting original file!" << endl;
				if (rename("book2.csv", "book.csv") != 0)
					cout << "error in renaming output file!" << endl;
			}
		}
	}
	catch (string msg)
	{
		cout << msg;
	}
}
void decreas_magazine(string writID) {
	f_magazine.open("magazine.csv");
	try {
		for (int i = 0;i < vec_magazine.size();i++) {
			if (vec_magazine[i].get_ID() == writID) {
				int n = 1;
				string s;
				s = vec_magazine[i].get_stock() - n;
				vec_magazine[i].set_stock(s);

				ofstream of_magazine;
				of_magazine.open("magazine2.csv", ios::out);

				of_magazine << vec_magazine;

				of_magazine.close();
				f_magazine.close();


				if (remove("magazine.csv") != 0)
					cout << "errorin deleting original file!" << endl;
				if (rename("magazine2.csv", "magazine.csv") != 0)
					cout << "error in renaming output file!" << endl;
			}
		}
	}
	catch (string msg)
	{
		cout << msg;
	}
}
void decreas_thesis(string writID) {
	f_thesis.open("thesis.csv");
	try {
		for (int i = 0;i < vec_thesis.size();i++) {
			if (vec_thesis[i].get_ID() == writID) {
				int n = 1;
				string s;
				s = vec_thesis[i].get_stock() - n;
				vec_thesis[i].set_stock(s);

				ofstream Of_thesis;
				Of_thesis.open("thesis2.csv", ios::out);

				Of_thesis << vec_thesis;

				Of_thesis.close();
				f_thesis.close();


				if (remove("thesis.csv") != 0)
					cout << "errorin deleting original file!" << endl;
				if (rename("thesis2.csv", "thesis.csv") != 0)
					cout << "error in renaming output file!" << endl;
			}
		}
	}
	catch (string msg)
	{
		cout << msg;
	}
}



long int convert_to_day(int day, int month, int year, int m) {
	long int days;

	days = (year * 365) + (month*m) + (day);
	cout << days << endl;
	return days;
}
date date_Delivery(date b, string level) {

	if (level == "baccalaureate")
		return b + 14;

	else if (level == "postgraduate")
		return b + 21;
	else if (level == "PhD")
		return b + 30;
}

string test_level_member(string memberID) {
	for (int i = 0;i < vec_member.size();i++) {
		if (vec_member[i].get_ID() == memberID)
			return vec_member[i].get_level();
	}
}





