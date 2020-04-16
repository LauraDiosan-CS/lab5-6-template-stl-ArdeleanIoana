#pragma once
#include "repo.h"
class Service 
{
	Repository repo;
public:
	Service();
	Service(Repository& Repo);
	~Service();
	void add_book(string title, string autor, int year);
	priority_queue<Book, vector<Book>, Compare> get_all();
	void delete_book(string title);
	void update_book(string old_title, string new_title, string autor, int year);
	void borrow_book(int id, string title);
	void return_book(string title);
};