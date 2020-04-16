#include "service.h"
#include <iostream>
using namespace std;
Service::Service()
{

}
Service::Service(Repository& Repo)
{
	this->repo = Repo;
}
Service::~Service()
{

}
void Service::add_book(string title, string autor, int year)
{
	Book b(title, autor, year);
	repo.create_book(b);
}
priority_queue<Book, vector<Book>, Compare> Service::get_all()
{
	return this->repo.read_books();
}
void Service::delete_book(string title)
{
	Book b(this->repo.get_one(title));
	this->repo.delete_book(b);
}

void Service::update_book(string old_title, string new_title, string autor, int year)
{
	Book b(this->repo.get_one(old_title));
	Book b2(new_title, autor, year);
	this->repo.update_book(b, b2);
}

void Service::borrow_book(int id, string title)
{
	Book b(this->repo.get_one(title));
	if (b.get_borrow() != 0)
		cout << "already borrowed" << endl;
	else
	{
		Book b2 = b;
		b2.set_borrow(id);
		this->repo.update_book(b, b2);
	}
}
void Service::return_book( string title)
{
	Book b(this->repo.get_one(title)); // creaza o copie dupa cartea respectiva
	Book b2 = b; // creaza o a2a carte tot aceleasi prorietati
	if (b2.get_borrow() == 0)
		cout<<"can not return"<<endl;
	else {
		b2.set_borrow(0); // dar cu id-ul schimbat
		this->repo.update_book(b, b2); // sa adaug un if aici? 
	}
}