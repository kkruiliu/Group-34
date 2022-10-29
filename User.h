#pragma once
#include <string>
#include <vector>
#include "Book.h"

class User
{
	std::string name;
	int id;
	std::vector<Book> checkout_history;
	std::vector<Book> current_checkouts;
public:
	User(int id);
	std::string getName();
	int getId();
	std::vector<Book> getCheckoutHistory();
	std::vector<Book> getCurrentCheckouts();
	void checkoutBook(Book book);
	void returnBook(Book book);
	void pushChanges();
};