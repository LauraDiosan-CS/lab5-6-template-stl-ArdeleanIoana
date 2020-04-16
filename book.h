#pragma once
#include <string>
#include <ostream>

using namespace std;

class Book {
private:
	string title;
	string autor;
	int year;
	int id_borrow; 
public:
	Book(); 
	Book(string title, string autor, int year);
	Book(const Book& b);
	~Book();

	void set_title(string title);
	void set_autor(string autor);
	void set_year(int year);
	void set_borrow(int id_borrow);

	string get_title();
	string get_autor();
	int get_year();
	int get_borrow();
	
	Book& operator=(const Book& b);
	bool operator==(const Book& b);
	bool operator>(const Book& b);
	bool operator<(const Book& b);
	friend ostream& operator<<(ostream& os, const Book& b);
	
};

