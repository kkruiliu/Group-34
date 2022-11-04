
#include <fstream>
#include <iostream>
#include <User.h>
#include <vector>
#include <map>

using namespace std;

ifstream fin("User.json");
ofstream fout("User.json", ios_base::app);

class AcessManager {
private:
    vector <string> usernames; //all the usernames of the existing accounts
    vector <string> passwords; //all the passwords of the existing accounts
    vector <string> id_;
public:
    void SignUp() {
        string username, password, id;
        cout << "\nCreate a new account:\n";
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        cout << "id";
        cin >> id;
        //Sets the given username and passwords as the eUsername and ePassword

        fout << username << " " << password << " " << id << "\n";
    }

    void LoginIn() {

        //The username and the password that the user entered
        string username, password, id;

        //See if the user is loggedin or not
        bool loggedin = false;

        create_vectors();

        cout << "\nLogin In your account:\n";
        cout << "Username: ";
        cin >> username;
        cout << "Password: ";
        cin >> password;
        cout << "id";
        cin >> id;
        int size = accounts_number(); //the number of the accounts

        //searches for a account that has the username, that the user entered
        for (int i = 0; i < size; ++i) {
            if (username == usernames[i]) {
                if (password == passwords[i]) {
                    if (id == id_[i]) {
                        cout << "Welcome, " + username;
                        loggedin = true;
                        break;
                    }
                }
            }
        }
        if (!loggedin) {
            cout << "The Username or the Password that you have entered are wrong! Please try again.";
        }
    }
    //creates the usernames and the passwords vectors
    void create_vectors() {
        string username, password, id;
        while (fin >> username && fin >> password && fin >> id) {
            insert_username(username); //insert the username read from the file into the vector
            insert_password(password);
            insert_id(id);
        }
    }
    //returns the numbers of the accountts in the file
    int accounts_number() {
        return usernames.size();
    }

    //inserts a new element in the usernames vector
    void insert_username(string username) {
        usernames.push_back(username);
    }

    //inserts a new element in the passwords vector
    void insert_password(string password) {
        passwords.push_back(password);
    }

    void insert_id(string id) {
        id_.push_back(id);
    }
};
