#include "User.h"
User::User(int id) {
	this->id = id;
	name = "Default"; //TODO: RETRIEVE NAME FROM DATABASE
	//TODO: RETRIEVE CHECKOUT HISTORY FROM DATABASE
	//TODO: RETRIEVE CURRENT CHECKOUTS FROM DATABASE
}
std::string User::getName() {
	return name;
}
int User::getId() {
	return id;
}
std::vector<Book> User::getCheckoutHistory() {
	return checkout_history;
}
std::vector<Book> User::getCurrentCheckouts() {
	return current_checkouts;
}
void User::checkoutBook(Book book) {
	current_checkouts.push_back(book);
}
void User::returnBook(Book book) {
	for (int i = 0; i<current_checkouts.size(); i++) {
		if (current_checkouts[i].isbn == book.isbn) {
			current_checkouts.erase(current_checkouts.begin() + i);
			break;
		}
	}
	checkout_history.push_back(book);
}
void User::pushChanges() {
	//TODO: UPDATE DATABASE USING USER OBJECT
}