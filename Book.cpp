//#include "Book.h"
//
//Book::Book() {
//    author = "";
//    this->isbn = "-1";
//    availability = false;
//    year = "";
//    reviews = "";
//}
//
//Book::Book(string _isbn) {
//    fstream file("Database.json");		//Loads the file stream
//    Json::Reader reader;				//Read and parse JSON data
//    Json::StyledStreamWriter writer;	//Write JSON data in human-readable form
//    Json::Value data;					//Store JSON data and make it accessible
//
//    reader.parse(file, data);			//Read a Value from a JSON document. 
//
//    isbn = _isbn;                                     //Assign Book an ISBN number
//    author = data["books"][isbn]["author"].asString();//Assign author variable with name from database
//    year = data["books"][isbn]["year"].asString();    //Assign year variable with year from database
//  
//    availability = data["books"][isbn]["available"].asBool(); //Assign availability variable with status from database
//
//    //reviews = "PULL REVIEWS FROM DATABASE";
//    
//    //review_history is empty till we add a review.
//}
//
//
//
//void Book::add_review(string isbn) {
//    fstream file("Database.json");		//Loads the file stream
//    Json::Reader reader;				//Read and parse JSON data
//    Json::StyledStreamWriter writer;	//Write JSON data in human-readable form
//    Json::Value data;					//Store JSON data and make it accessible
//
//    reader.parse(file, data);			//Read a Value from a JSON document. 
//    //TODO: Create object with credentials provided and create the review.
//    //Reviews feedback;
//    char leave_review;
//
//    cout << "Here at Books Without Boundaries, leaving reviews is very important to our success. We'd love to get your feedback on the current book that you have read." <<endl;
//    cout << "Enter (Y/N) to leave a review." << endl;
//    cin >> leave_review;
//
//    if (leave_review == 'Y' || 'y') {
//        string reviewerName;
//        string rating;
//        string feedback;
//        
//        cout << "Name: " << endl;
//        cout << "Enter a rating from 1-5 for the returning book: " <<endl;
//        cin >> rating;
//        cout << "Tell us how the book was:  " <<endl;
//        cin >> feedback;
//
//        //Reviews reviewObject(reviewerName, rating, feedback);
//  
//        //Assuming that we have a list of books to checkout from. Write that review to that book
//        data["books"][isbn]["reviewName"] = reviewerName;
//        data["books"][isbn]["rating"] = rating;
//        data["books"][isbn]["feedback"] = feedback;
//
//        cout << "We're so happy to hear from you. Thank you for providing us with valuable feedback!" << endl;
//
//        file.close();
//        ofstream closer;
//        closer.open("Database.json");
//        closer.close();
//        file.open("Database.json");
//
//        writer.write(file, data);
//    }
//    else {
//        cout << "Thank you for your return. Have a nice day!";
//    }
// 
//
//    //Push into review container.
//
//    //review_history.push_back(Reviews);
//}
//void Book::delete_review(Reviews review){
//    //TODO: Iterate through review history and delete the selected review based on parameters given
//}
//void Book::print_reviews(vector<Reviews> review_history) {
//    //TODO: Print all reviews with name, rating, and the feedback.
////    for (int i = 0; i < review_history.size; i++) {
////    }
//}
//void Book::print_filteredReviews(vector<Reviews> review_history, int rating) {
//    //TODO: Print all review from selected rating.  with name and the feedback.
//}
//
