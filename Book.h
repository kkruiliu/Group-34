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
    bool availability;
    string rating;
    map<string, string> bookRatings;

    Book();
    Book(string _isbn);
    Book(string _isbn, string name, string _author, string _year);

    void add_review(string username, string review);

    static map<string, Book> getBookCollection();
};

Book::Book() {
    author = "";
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
        year = data["books"][_isbn]["year"].asString();
        rating = data["books"][_isbn]["rating"];
        for (auto const& rating : data["books"][_isbn]["ratings"]) {
            bookRatigns[rating] = data["books"][_isbn]["ratings"][rating];
        }
    }
    else {
        author = "";
        isbn = "-1";
        availability = false;
        year = "";
        rating = "Unrated";
    }
}
Book::Book(string _isbn, string name, string _author, string _year) {
    isbn = _isbn;
    author = _author;
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

