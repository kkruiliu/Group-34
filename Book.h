#include "User.h"
#include "Reviews.h"
using namespace std:

//TODO: ADD MORE IF YOU CAN OF ANYTHING ELSE WE MAY NEED
//Leaving Book class as public. If you think private is better lets discuss with the team.

struct Book{
    String author;
    string isbn;
    string reviews;
    vector<Reviews> review_history;

    Book(string author, string isbn);
    //When the user turns in a book prompt the option to add a review
    add_review(string name, int rating, string feedback);
    //Delete review if the user decided they don't want to keep it.
    delete_review(review review);
    //Print review History
    print_reviews(vector<Reviews> review_history);
    //Print reviews based on filtered rating
    print_filteredReviews(vector<Reviews> review_history, int rating);

    //search();
};

