#include "repo.h"
#include "book.h"
#include <fstream>
#include <iostream>
using namespace std;
Repository::Repository()
{
	this->filename.clear();
}
Repository::~Repository()
{

}
Repository::Repository(string filename)
{
	this->filename = filename;
	this->loadfromfile();
}
void Repository::create_book(Book& b) 
{
	this->books.push(b);
	this->savetofile();
}
priority_queue<Book, vector<Book>, Compare> Repository::read_books()
{
	return this->books;
}
void Repository::update_book(Book& old_book, Book& new_book)
{
	priority_queue<Book, vector<Book>, Compare> aux;
	Book auxb;
	while (!this->books.empty())
	{
		auxb = this->books.top();
		if (auxb == old_book)
			aux.push(new_book);
		else
			aux.push(auxb);
		this->books.pop();
	}
	while (!aux.empty())
	{
		this->books.push(aux.top());
		aux.pop();
	}
	this->savetofile();
}
void Repository::delete_book(Book& b)
{
	priority_queue<Book, vector<Book>, Compare> aux;
	Book auxb;
	while (!this->books.empty())
	{
		auxb = this->books.top();
		if (!(auxb == b))
			aux.push(auxb);
		this->books.pop();
	}
	while (!aux.empty())
	{
		this->books.push(aux.top());
		aux.pop();
	}
	this->savetofile();
}
Book Repository::get_one(string title)
{
	priority_queue<Book, vector<Book>, Compare> aux = this->books;
	Book auxb; // am avut putine probleme cu coada 

	while (!aux.empty())
	{
		auxb = aux.top();
		if (auxb.get_title() == title)
			return auxb;
		aux.pop();
	}
}

void Repository::loadfromfile()
{
	if (this->filename.size() != 0)
	{
		while (!this->books.empty())
			this->books.pop();
		ifstream f(this->filename);
		string title, autor;
		int year, id;
		while (f >> title >> autor >> year >> id)
		{
			Book b(title, autor, year);
			b.set_borrow(id);
			this->books.push(b);
		}
		f.close();
	}
}
void Repository::savetofile()
{
	if (this->filename.size() != 0)
	{
		ofstream f(this->filename, std::ostream::trunc);
		while (!this->books.empty())
		{
			Book b(this->books.top());
			f << b.get_title()<<" "<<b.get_autor()<<" "<<b.get_year()<<" "<<b.get_borrow()<< endl;
			this->books.pop();
		}
		this->loadfromfile();
		f.close();
	}
}