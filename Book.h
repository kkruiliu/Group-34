#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <map>

//#include "Reviews.h"
using namespace std;

struct Book{
    string isbn;
    string author;
    string year;
    bool availability;
    //vector<Book> bookCollection;
    string rating;
    vector<string> bookRatings;
     
    // ISBN     BOOK OBJECT ratings 
    map<string, Book> bookCollection;

    Book();
    Book(string _isbn, string _author, string _year, bool _availability, string _rating, vector<string> _bookRatings);

    void instantiateBookCollection();
    void add_review();
    void print_ratings(string isbn);
    static bool searchBooks(string isbn);
};

Book::Book() {
    author = "";
    this->isbn = "-1";
    availability = false;
    year = ""; 
}
Book::Book(string _isbn, string _author, string _year, bool _availability, string _rating, vector<string> _bookRatings) {
    isbn = _isbn;
    author = _author;
    availability = _availability;
    year = _year;
    rating = _rating;

    for (int i = 0; i < _bookRatings.size(); i++) {
        bookRatings.push_back(bookRatings[i]);
    }
}

//Since we are preStoring Books onto the database...
//ALL BOOKS NEED TO BE STORED IN THE VECTOR. READ THE DATABASE AND CREATE BOOK OBJECTS
void Book::instantiateBookCollection() {
    fstream file("Database.json");		//Loads the file stream
    Json::Reader reader;				//Read and parse JSON data
    //Json::StyledStreamWriter writer;	//Write JSON data in human-readable form
    Json::Value data;					//Store JSON data and make it accessible
    reader.parse(file, data);			//Read a Value from a JSON document. 

    //Store all books from the "JSON database" into a vector for easier access. 
    for (auto const& id : data["books"].getMemberNames()) {

        if (id != "-1") {
            isbn = id;                      //Assign Book an ISBN number
            author = data["books"][id]["author"].asString();          //Assign author variable with name from database
            year = data["books"][id]["year"].asString();              //Assign year variable with year from database
            availability = data["books"][id]["available"].asBool();   //Assign availability variable with status from database
            rating = data["books"][id]["rating"].asString();

            for (int j = 0; j < data["books"][id]["Ratings"].size(); j++) {
                bookRatings.push_back(data["books"][id]["Ratings"][j].asString());
            }



            Book bookFromJSON(isbn, author, year, availability, rating, bookRatings); //Create object
            bookCollection.insert(pair<string, Book>(isbn, bookFromJSON));           //Store isbn and book into map
        }
    }
}


//add review parameter
void Book::add_review() {
    fstream file("Database.json");		//Loads the file stream
    Json::Reader reader;				//Read and parse JSON data
    Json::StyledStreamWriter writer;	//Write JSON data in human-readable form
    Json::Value data;					//Store JSON data and make it accessible
    reader.parse(file, data);			//Read a Value from a JSON document. 

    //Utilizing SMFL, Ask user if they want to leave a review...
    //Click on the star 1 - 5. Each star should have corresponding rating...
    //Grab the rating the User has selected and store that into the database
    //For now we use terminal as an example.
    cout << "Enter a rating from 1-5 for the returning book: " << endl;
    cin >> rating;
    //Add book rating to the database.... Store into JSON
    data["books"][isbn]["ratings"].append(rating);


    //UPDATE RATINGS of the current book------------------------------------------------------------ 
    //Access the current book ratings
    int average;
    int calculation;
    for (int i = 0; i < data["books"][isbn]["ratings"].size(); i++) {
        average += data["books"][isbn]["ratings"][i].asInt();
    }

    calculation = average / data["books"][isbn]["ratings"].size();  //INT
    rating = to_string(calculation);                                //Convert into string
    data["books"][isbn]["rating"] = rating;                         //Store into JSON      
    

    file.close();
    ofstream closer;
    closer.open("Database.json");
    closer.close();
    file.open("Database.json");
    writer.write(file, data);
}
void Book::print_ratings(string isbn) {
    fstream file("Database.json");		//Loads the file stream
    Json::Reader reader;				//Read and parse JSON data
    Json::StyledStreamWriter writer;	//Write JSON data in human-readable form
    Json::Value data;					//Store JSON data and make it accessible
    reader.parse(file, data);			//Read a Value from a JSON document. 

    /*for (int i = 0; i < data["books"][isbn]["ratings"].size(); i++) {
    }*/

    //PRINTS ALL RATINGS.
    for (auto it = bookCollection.begin(); it != bookCollection.end(); ++it){

        if (it->first == isbn) {

            for (int i = 0; i < it->second.bookRatings.size(); i++) {
                cout << it->second.bookRatings[i];
            }
        }
    }
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



