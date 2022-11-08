#include "Book.h"

Book::Book(string _author, string _isbn, string _reviews) {
    author = _author;
    isbn = _isbn;
    reviews = _reviews;

    //review_history is empty till we add a review.
}

void Book::add_review() {
    //TODO: Create object with credentials provided and create the review.
    //Reviews reviewObject;
    char leave_review;

    cout << "Have time to spare? Leave a review" <<endl;
    cout << "Enter:(Y/N)" << endl;
    cin >> leave_review;

    if (leave_review == 'Y'){
        string review;
        string rating;

        cout << "Please enter a rating from 1-5 for the returning book" <<endl;
        cin >> rating;
        cout << "Please enter a review for the book you are returning: " <<endl;
        cin >> review;

        //Assuming that we have a list of books to checkout from.
        //

        cout << "We're so happy to hear from you. Thank you for providing us with valuable feedback!";

    }
    else {
        cout << "Thank you for your return. Have a nice day!";
    }



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

