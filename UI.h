#pragma once
#include "service.h"
class UI {
private:
	Service service;
	void show_menu();
	void add_book();
	void show_books();
	void delete_book();
	void update_book();
	void borrow_book();
	void return_book();
public:
	UI();
	UI(Service& service);
	~UI();
	void run();
};