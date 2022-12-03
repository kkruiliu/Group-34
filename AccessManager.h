#include <fstream>
#include <iostream>
//#include <User.h>
#include "User.h"
#include <vector>
#include <regex>
#include <map>
#include <SFML/Graphics.hpp>

using namespace std;

ifstream fin("User.json");
ofstream fout("User.json", ios_base::app);

class AccessManager {

private:
    vector <string> usernames; //all the usernames of the existing accounts
    vector <string> passwords; //all the passwords of the existing accounts
    vector <string> id_;
public:
    void SignUp(sf::RenderWindow& window, sf::Font& font, string username, string password) {
        //TODO: Randomly Generate ID

        bool validCredentials = false;

        //error box if there is an issue
        sf::RectangleShape errorBox(sf::Vector2f(500, 100));
        errorBox.setFillColor(sf::Color(255, 228, 228));
        errorBox.setOutlineThickness(3.f);
        errorBox.setOutlineColor(sf::Color::Red);
        errorBox.setPosition(410, 160);

        sf::Text errorMessage;
        errorMessage.setFont(font);
        errorMessage.setCharacterSize(20);
        errorMessage.setFillColor(sf::Color::Black);
        errorMessage.setPosition(410, 160);
        
        while (!validCredentials) {

            //Accepts upper case/ lower case/ underscores / numbers. 6-16 characters
            regex usernameRequirement("^[A-Za-z0-9_]{6,16}+$");
            bool  validUsername = regex_search(username,usernameRequirement);
            //Minimum 6 and maximum 16 characters, at least one uppercase letter, one lowercase letter,
            // one number and one special character
            regex passwordRequirement("^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)(?=.*[@$!%*?&])[A-Za-z\d@$!%*?&]{6,16}$");
            bool  validPassword = regex_search(password,passwordRequirement);
            if (!validUsername) {

                window.draw(errorBox);
                errorMessage.setString("Username does not meet the minimum requirements.\n Please try again using the proper username specifications");
                window.draw(errorMessage);
            }
            if (!validPassword) {

                window.draw(errorBox);
                errorMessage.setString("Password does not meet the minimum requirements.\n Please try again using the proper password specifications");
                window.draw(errorMessage);
            }
            //if (validUsername && validPassword) {
                validCredentials = true;
                insert_username(username);
                insert_password(password);
            //}
        }

        //TODO: After Creating account. Need to take in profile details such as name.
        //TODO: Create accountDetails() function
        //AccountDetails();

        //Sets the given username and passwords as the eUsername and ePassword
        //fout << username << " " << password << " " << id << "\n";
    }
    void AccountDetails (){
        //This will take in the name of the user to create the user object associated with that username and password.

    }


    void LoginIn() {
        //The username and the password that the user entered
        string username, password, id;

        //See if the user is loggedin or not
        bool loggedIn = false;

        //create_vectors();

        cout << "\nSign in. Use your BWOB account:\n" << endl;

        while (!loggedIn) {
            cout << "Username: " << endl;
            cin >> username;
            cout << "Password: " << endl;
            cin >> password;
            cout << "ID: " << endl;
            cin >> id;
            int size = accounts_number(); //the number of the accounts

            //searches for an account that has the username, that the user entered
            for (int i = 0; i < size; ++i) {
                if (username == usernames[i]) {
                    if (password == passwords[i]) {
                        if (id == id_[i]) {
                            cout << "Welcome, " + username;
                            loggedIn = true;
                        }
                    }
                }
            }
            if (!loggedIn) {
                cout << "The Username or the Password that you have entered are wrong!\nPlease try again." << endl;
            }
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


