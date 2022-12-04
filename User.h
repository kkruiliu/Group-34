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
	std::string name;
	std::string username;
	std::vector<std::string> checkout_history;
	std::string current_checkout;
	std::string checkout_date;
public:
	User(std::string username);
	std::string getName();
	std::string getUsername();
	std::vector<std::string> getCheckoutHistory();
	std::string getCurrentCheckout();
	void checkoutBook(std::string isbn);
	void returnBook();
	void print();
};

User::User(string username) {
	this->username = username;

	Json::Value data = readData();

	name = data["users"][username]["name"].asString();
	for(int i=0; i<data["users"][username]["checkout_history"].size(); i++){
		checkout_history.push_back(data["users"][username]["checkout_history"][i].asString());
	}
	current_checkout = data["users"][username]["current_checkout"].asString();
	checkout_date = data["users"][username]["checkout_date"].asString();
}
void User::print(){
	cout << "==============================" << endl;
	cout << "Username is " << username << endl;
	cout << "\nName is " << name << endl;
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
std::string User::getName() {
	return name;
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
void User::checkoutBook(string isbn) {
	current_checkout = isbn;

	Json::Value data = readData();

	data["users"][username]["current_checkout"] = isbn;

	time_t now = time(0);
	string date_time = ctime(&now);
	date_time = date_time.substr(4, 7) + date_time.substr(20, 4);
	data["users"][username]["checkout_date"] = date_time;
	checkout_date = date_time;

	writeData(data);

}
void User::returnBook() {
	if(current_checkout != "-1"){

		Json::Value data = readData();
		
		data["users"][username]["checkout_history"].append(current_checkout);
		checkout_history.push_back(current_checkout);
		current_checkout = "-1";
		checkout_date = "";

		data["users"][username]["current_checkout"] = "-1";
		data["users"][username]["checkout_date"] = "";
		
		writeData(data);
	}
}