#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "Reviews.h"
using namespace std;

//TODO: ADD MORE IF YOU CAN OF ANYTHING ELSE WE MAY NEED
//Leaving Book class as public. If you think private is better lets discuss with the team.

struct Book{
    string name;
    string author;
    string isbn;

    string reviews;
    vector<Reviews> review_history;

    Book(string isbn);
    Book();

    //When the user turns in a book prompt the option to add a review
    void add_review();
    //Delete review if the user decided they don't want to keep it.
    void delete_review(Reviews review);
    //Print review History
    void print_reviews(vector<Reviews> review_history);
    //Print reviews based on filtered rating
    void print_filteredReviews(vector<Reviews> review_history, int rating);

    //search();
};

