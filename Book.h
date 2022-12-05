#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include "Database.h"

//#include "Reviews.h"
using namespace std;

struct Book {
    string isbn;
    string author;
    string year;
    string name;
    bool availability;
    string rating;
    map<string, string> bookRatings;

    Book();
    Book(string _isbn);
    Book(string _isbn, string _name, string _author, string _year);

    void add_review(string username, string review);

    static void addBook(string _isbn, string _name, string _author, string _year);
    static void removeBook(string _isbn);
    static vector<Book> getBookCollection();
    static vector<Book> searchBooks(string query);
};

Book::Book() {
    author = "";
    name = "";
    isbn = "-1";
    availability = false;
    year = "";
    rating = "Unrated";
}
Book::Book(string _isbn) {
    Json::Value data = readData();
    if (data["books"].isMember(_isbn)) {
        author = data["books"][_isbn]["author"].asString();
        isbn = _isbn;
        availability = data["books"][_isbn]["available"].asBool();
        name = data["books"][_isbn]["name"].asString();
        year = data["books"][_isbn]["year"].asString();
        rating = data["books"][_isbn]["rating"];
        for (auto const& rating : data["books"][_isbn]["ratings"]) {
            bookRatings[rating] = data["books"][_isbn]["ratings"][rating];
        }
    }
    else {
        author = "";
        name = "";
        isbn = "-1";
        availability = false;
        year = "";
        rating = "Unrated";
    }
}
Book::Book(string _isbn, string _name, string _author, string _year) {
    isbn = _isbn;
    author = _author;
    name = _name;
    availability = true;
    year = _year;
    rating = "Unrated";

    Json::Value data = readData();

    Json::Value book;
    book["author"] = _author;
    book["available"] = true;
    book["name"] = _name;
    book["year"] = _year;
    book["rating"] = "Unrated";
    book["ratings"] = Json::Value;

    data["books"][_isbn] = book;
    writeData(data);
}

//add review parameter
void Book::add_review(string username, string review) {

    Json::Value data = readData();					//Store JSON data and make it accessible

    //Utilizing SMFL, Ask user if they want to leave a review...
    //Click on the star 1 - 5. Each star should have corresponding rating...
    //Grab the rating the User has selected and store that into the database
    //For now we use terminal as an example.

    //Add book rating to the database.... Store into JSON
    data["books"][isbn]["ratings"]["username"] = review;


    //UPDATE RATINGS of the current book------------------------------------------------------------ 
    //Access the current book ratings
    double total = 0;
    for (auto const& user : data["books"][isbn]["ratings"].getMemberNames()) {
        total += stod(data["books"][isbn]["ratings"][user].asString());
    }

    double calculation = total / data["books"][isbn]["ratings"].getMemberNames().size();
    rating = to_string(calculation);                                //Convert into string
    data["books"][isbn]["rating"] = rating;                         //Store into JSON      


    writeData(data);
    this->rating = rating;
    this->bookRatings[username] = review;
}

void Book::addBook(string _isbn, string _name, string _author, string _year) {
    Book(_isbn, _name, _author, _year);
}

void Book::removeBook(string _isbn) {
    Json::Value data = readData();
    data["books"].removeMember(_isbn);
    writeData(data);
}

//Since we are preStoring Books onto the database...
//ALL BOOKS NEED TO BE STORED IN THE VECTOR. READ THE DATABASE AND CREATE BOOK OBJECTS
vector<Book> Book::getBookCollection() {

    Json::Value data = readData();					//Store JSON data and make it accessible
    vector<Book> books;

    //Store all books from the "JSON database" into a vector for easier access. 
    for (auto const& id : data["books"].getMemberNames()) {
        if (id != "-1")
            books.push_back(Book(id));
    }
    return books;
}

vector<Book> Book::searchBooks(string query) {
    vector<Book> results;
    for (Book book : getBookCollection()) {
        if (book.name.find(query) != string::npos) {
            results.push_back(book);
        }
    }

    return results;
}

