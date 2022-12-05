#include <fstream>
#include <iostream>
//#include <User.h>
#include "User.h"
#include <vector>
#include <regex>
#include <map>
#include <SFML/Graphics.hpp>
#include "Database.h"

using namespace std;

ifstream fin("User.json");
ofstream fout("User.json", ios_base::app);

class AccessManager {
public:
    User activeUser;
    bool loggedIn = false;

    bool SignUp(string username, string password) {
        //Accepts upper case/ lower case/ underscores / numbers. 6-16 characters
        regex usernameRequirement = regex("^[A-Za-z0-9_]{6,16}$");
        //Minimum 6 and maximum 16 characters, at least one uppercase letter, one lowercase letter,
        // one number and one special character
        regex passwordRequirement = regex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\\d)(?=.*[@$!%*?&])[A-Za-z\\d@$!%*?&]{6,16}$");
        if (!regex_search(username, usernameRequirement) || !regex_search(password, passwordRequirement)) {
            return false;
        }
        activeUser = User(username, password);
        return true;
    }


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

    void logOut() {
        activeUser = User();
        loggedIn = false;
    }

    //returns the numbers of the accountts in the file
    int accounts_number() {
        return readData().getMemberNames().size();
    }
};


