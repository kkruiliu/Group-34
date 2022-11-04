#include "Book.h"

Book::Book(string author, string isbn) {
    this->author = author;
//    this->isbn = isbn;
}

void Book::add_review(string name, int rating, string feedback) {
    //TODO: Create object with credentials provided and create the review.
    //Push into review container.

    //review_history.push_back(Reviews);
}
void Book::delete_review(Reviews review){
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

