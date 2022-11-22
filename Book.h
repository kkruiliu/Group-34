#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "User.h"
#include "Reviews.h"
using namespace std;

//TODO: ADD MORE IF YOU CAN OF ANYTHING ELSE WE MAY NEED
//Leaving Book class as public. If you think private is better lets discuss with the team.

struct Book{
    string isbn;
    string author;
    string year;
    bool availability;
   
    string reviews;
    vector<Reviews> review_history;

    Book();
    Book(string isbn);
    

    //When the user turns in a book prompt the option to add a review
    void add_review(string username);
    //Delete review if the user decided they don't want to keep it.
    void delete_review(Reviews review);
    //Print review History
    void print_reviews(vector<Reviews> review_history);
    //Print reviews based on filtered rating
    void print_filteredReviews(vector<Reviews> review_history, int rating);
    //addBook() database.
    //removeBooks database

    static bool searchBooks(string isbn);
};

Book::Book() {
    author = "";
    this->isbn = "-1";
    availability = false;
    year = "";
    reviews = "";
}

Book::Book(string _isbn) {
    fstream file("Database.json");		//Loads the file stream
    Json::Reader reader;				//Read and parse JSON data
    //Json::StyledStreamWriter writer;	//Write JSON data in human-readable form
    Json::Value data;					//Store JSON data and make it accessible

    reader.parse(file, data);			//Read a Value from a JSON document. 

    isbn = _isbn;                                     //Assign Book an ISBN number
    author = data["books"][isbn]["author"].asString();//Assign author variable with name from database
    year = data["books"][isbn]["year"].asString();    //Assign year variable with year from database
    availability = data["books"][isbn]["available"].asBool(); //Assign availability variable with status from database

    //reviews = "PULL REVIEWS FROM DATABASE";
    //review_history is empty till we add a review.
}


//add review parameter
void Book::add_review(string username) {
    fstream file("Database.json");		//Loads the file stream
    Json::Reader reader;				//Read and parse JSON data
    Json::StyledStreamWriter writer;	//Write JSON data in human-readable form
    Json::Value data;					//Store JSON data and make it accessible

    reader.parse(file, data);			//Read a Value from a JSON document. 

    cout << "Here at Books Without Boundaries, leaving reviews is very important to our success. We'd love to get your feedback on the current book that you have read." << endl;
    cout << "Enter (Y/N) to leave a review." << endl;
    char leave_review;
    cin >> leave_review;

    if (leave_review == 'Y' || 'y') {
        string reviewerName;
        string rating;
        string feedback;

        cout << "Name: " << endl;
        cin >> reviewerName;
        cout << "Enter a rating from 1-5 for the returning book: " << endl;
        cin >> rating;
        cout << "Tell us how the book was:  " << endl;
        cin >> feedback;

        //Reviews reviewObject(reviewerName, rating, feedback);
        //*NOTES* create map for REVIEWS

        //Assuming that we have a list of books to checkout from. Write the review to that corresponding book
        //* NOTES * since this is being written to the database, do we not have to create an object?

        data["books"][isbn]["reviewName"].append(reviewerName);
        data["books"][isbn]["rating"].append(rating);
        data["books"][isbn]["feedback"].append(feedback);

        cout << "We're so happy to hear from you. Thank you for providing us with valuable feedback!" << endl;

    }
    else {
        cout << "Thank you for your return. Have a nice day!";
    }


    //Writes to the database.
    file.close();
    ofstream closer;
    closer.open("Database.json");
    closer.close();
    file.open("Database.json");

    writer.write(file, data);

    //Not needed since we store in the database?
    //Push into review container.
    //review_history.push_back(Reviews);
}
void Book::delete_review(Reviews review) {
    //TODO: Iterate through review history and delete the selected review based on parameters given
}
void Book::print_reviews(vector<Reviews> review_history) {
    //TODO: Print all reviews with name, rating, and the feedback.
//    for (int i = 0; i < review_history.size; i++) {
//    }
}
void Book::print_filteredReviews(vector<Reviews> review_history, int rating) {
    //TODO: Print all review from selected rating.  with name and the feedback.
}

bool Book::searchBooks(string isbn){
    ifstream file("Database.json");
    Json::Reader reader;
    Json::Value data;

    reader.parse(file, data);

    bool available = false;

    if (data["books"].isMember(isbn)) {
        available = data["books"][isbn]["available"].asBool();
    }
    return available;
}



