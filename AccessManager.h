#include <fstream>
#include <iostream>
#include "User.h"
#include <vector>
#include <regex>
#include <map>
#include <SFML/Graphics.hpp>
#include "Database.h"

using namespace std;

class AccessManager {
public:
    User activeUser;
    bool loggedIn = false;

    //Takes in a username and password, verifies they meet requirements, if so adds a user to the database and returns successful string
    string SignUp(string username, string password) {
        //Accepts upper case/ lower case/ underscores / numbers. 6-16 characters
        regex usernameRequirement = regex("^[A-Za-z0-9_]{6,16}$");
        //Minimum 6 and maximum 16 characters, at least one uppercase letter, one lowercase letter,
        // one number and one special character
        regex passwordRequirement = regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{6,16}$");
        if (!regex_search(username, usernameRequirement)) {
            return "Username does not meet the requirements. Please try again.";
        }
        if (!regex_search(password, passwordRequirement)) {
            return "Password does not meet the requirements. Please try again.";
        }
        Json::Value data = readData();
        for (auto const& user : data["users"].getMemberNames()) {
            if (username == user)
                return "Username already exists. Please try again.";
        }
        activeUser = User(username, password);
        return "Successfully created account!";
    }

    //Checks if the username and password combo is correct from database, then sets the active user if it was correct
    void logIn(string username, string password) {
        Json::Value data = readData();
        bool validUser = false;
        for (auto const& user : data["users"].getMemberNames()) {
            if (username == user)
                validUser = true;
        }
        if (validUser) {
            if (data["users"][username]["password"].asString() == password) {
                loggedIn = true;
                activeUser = User(username);
            }
        }
    }

    //Logs the active user out
    void logOut() {
        activeUser = User();
        loggedIn = false;
    }

    //returns the numbers of the accounts in the file
    int accounts_number() {
        return readData().getMemberNames().size();
    }
};


