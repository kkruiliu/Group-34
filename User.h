#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include "Database.h"

using namespace std;

class User
{
	std::string username;
	std::vector<std::string> checkout_history;
	std::string current_checkout;
	std::string checkout_date;
public:
	User(std::string username);
	User(string username, string password);
	User();
	std::string getUsername();
	std::vector<std::string> getCheckoutHistory();
	std::string getCurrentCheckout();
	bool checkoutBook(std::string isbn);
	void returnBook();
	void print();
};

//Constructor that takes a username and populates the rest of the info from the database
User::User(string username) {
	this->username = username;

	Json::Value data = readData();

	for(int i=0; i<data["users"][username]["checkout_history"].size(); i++){
		checkout_history.push_back(data["users"][username]["checkout_history"][i].asString());
	}
	current_checkout = data["users"][username]["current_checkout"].asString();
	checkout_date = data["users"][username]["checkout_date"].asString();
}

//Constructor that creates a new user and writes it to the database
User::User(string username, string password) {
	this->username = username;

	Json::Value data = readData();

	Json::Value user;
	user["checkout_date"] = "Never";
	user["checkout_history"] = Json::arrayValue;
	user["current_checkout"] = "-1";
	user["password"] = password;

	data["users"][username] = user;
	writeData(data);

}

//Null user object
User::User() {
	this->username = "NULL";
	this->current_checkout = "-1";
	this->checkout_date = "Never";
}

//Prints user details to the terminal (for debugging)
void User::print(){
	cout << "==============================" << endl;
	cout << "Username is " << username << endl;
	cout << "\nCheckout List: " << endl;
	for(auto it = begin(checkout_history); it != end(checkout_history); ++it){
		cout << *it << endl;
	}
	if(current_checkout != "-1"){
		cout << "\nCurrent Checkout is " << current_checkout << endl; 
		cout << "It was checked out on " << checkout_date << endl;
	}else{
		cout << "\nNothing is currently checked out" << endl;
	}
	cout << "==============================" << endl;
}
std::string User::getUsername() {
	return username;
}
std::vector<string> User::getCheckoutHistory() {
	return checkout_history;
}
std::string User::getCurrentCheckout() {
	return current_checkout;
}

//Checks the book out for a user, updating the object and database
bool User::checkoutBook(string isbn) {

	Json::Value data = readData();
	
	if (current_checkout == "-1" && data["books"][isbn]["available"].asBool()) {
		current_checkout = isbn;

		data["users"][username]["current_checkout"] = isbn;
		
		data["users"][username]["checkout_history"].append(current_checkout);
		checkout_history.push_back(current_checkout);

		time_t now = time(0);
		string date_time = ctime(&now);
		date_time = date_time.substr(4, 7) + date_time.substr(20, 4);
		data["users"][username]["checkout_date"] = date_time;
		checkout_date = date_time;

		data["books"][isbn]["available"] = false;

		writeData(data);
		return true;
	}
	return false;
}

//Returns the book that a user previous checked out, updating the object and database
void User::returnBook() {
	if(current_checkout != "-1"){
		Json::Value data = readData();

		data["books"][current_checkout]["available"] = true;
		
		current_checkout = "-1";
		checkout_date = "";

		data["users"][username]["current_checkout"] = "-1";
		data["users"][username]["checkout_date"] = "";
		
		writeData(data);
	}
}
