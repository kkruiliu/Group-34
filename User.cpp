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
	//TODO: ITERATE THROUGH CURRENT CHECKOUTS AND REMOVE BOOK
	checkout_history.push_back(book);
}
void User::pushChanges() {
	//TODO: UPDATE DATABASE USING USER OBJECT
}