#include "AccessManager.h"
#include "User.h"
#include <iostream>

using namespace std;

int main(){
    //AcessManager control;

    //control.SignUp();
    //control.LoginIn();

    User user1("john224");
    cout << "(1) INITIAL STATE" << endl;
    user1.print();
    user1.returnBook();
    cout << "(2) BOOK RETURN" << endl;
    user1.print();
    user1.checkoutBook("502");
    cout << "(3) BOOK CHECKOUT" << endl;
    user1.print();

    return 0;
}


