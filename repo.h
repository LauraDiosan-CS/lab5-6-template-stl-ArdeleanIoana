#pragma once
#include "book.h"
#include <queue>

class Compare
{
public:
	bool operator() (Book& b1, Book& b2)
	{
		return b1<b2;
	} // a fo nevoie sa fac asta ca sa mearga 
	// < > nu mergeau 
};
class Repository {
	priority_queue<Book,vector<Book>,Compare> books;
	string filename;
public:
	Repository();
	Repository(string filename);
	~Repository();

	void create_book(Book& b);
	priority_queue<Book, vector<Book>, Compare> read_books();
	void update_book(Book& old_book, Book& new_book);
	void delete_book(Book& b);
	Book get_one(string title);

	void savetofile();
	void loadfromfile();
};