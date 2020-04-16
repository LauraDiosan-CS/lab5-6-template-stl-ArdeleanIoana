#include "UI.h"
#include <iostream>
using namespace std;
UI::UI()
{

}
UI::~UI()
{

}
UI::UI(Service& service)
{
	this->service = service;
}
void UI::show_menu()
{
	cout << "1. add book" << endl;
	cout << "2. show books" << endl;
	cout << "3. update book" << endl;
	cout << "4. delete book" << endl;
	cout << "5. borrow book" << endl;
	cout << "6. return book" << endl;
	cout << "x. stop program" << endl;
}
void UI::add_book()
{
	string title, autor;
	int year;
	cout << "title: ";
	cin >> title;
	cout << "autor: ";
	cin >> autor;
	cout << "year: ";
	cin >> year;
	this->service.add_book(title, autor, year);
	cout << "book added" << endl;
}
void UI::show_books()
{
	priority_queue<Book, vector<Book>, Compare> books = this->service.get_all();
	cout << "books: " << endl;
	while (!books.empty())
	{
		cout << books.top() << endl;
		books.pop();
	}
}
void UI::delete_book()
{
	cout << "title of the book to delete: ";
	string title;
	cin >> title;
	this->service.delete_book(title);
}
void UI::update_book()
{
	string old_title, title, autor;
	int year;
	cout << "title of the book to delete: ";
	cin >> old_title;
	cout << "new title: ";
	cin >> title;
	cout << "new autor: ";
	cin >> autor;
	cout << "new year: ";
	cin >> year;
	this->service.update_book(old_title, title, autor, year);
}
void UI::borrow_book()
{
	string title;
	int id;
	cout << "title of the book: ";
	cin >> title;
	cout << "client id: ";
	cin >> id;
	this->service.borrow_book(id, title);
}
void UI::return_book()
{
	string title;
	cout << "title: ";
	cin >> title;
	this->service.return_book(title);
}
void UI::run()
{
	char choice;
	while (true)
	{
		this->show_menu();
		cin >> choice;
		if (choice == '1')
			this->add_book();
		else if (choice == '2')
			this->show_books();
		else if (choice == '3')
			this->update_book();
		else if (choice == '4')
			this->delete_book();
		else if (choice == '5')
			this->borrow_book();
		else if (choice == '6')
			this->return_book();
		else if (choice == 'x')
			break;
		else
			cout << "no such command" << endl;
	}
}