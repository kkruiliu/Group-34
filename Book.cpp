#include "Book.h"

Book::Book() {
    author = "N/A";
    isbn = 0;
}
Book::Book(string author, int isbn) {
    this->author = author;
    this->isbn = isbn;
}

void Book::add_review(string name, int rating, string feedback) {
    //TODO: Create object with credentials provided and create the review.
    //Push into review container.
    review_history.pushback(review);
}
void Book::delete_review(review review){
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
