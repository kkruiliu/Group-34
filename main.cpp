#include "AccessManager.h"
#include "Book.h"
#include "Button.h"
#include "textBox.h"
#include "User.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <list> 

using namespace std;

sf::Font loadFont(string file) {
    sf::Font font;
    file = "Front_End/" + file;

    if (!font.loadFromFile(file))
    {
        cout << "Error loading file" << endl;
    }

    return font;
}

sf::Texture loadTexture(string file) {
    sf::Texture texture;
    file = "Front_End/" + file;

    if (!texture.loadFromFile(file)) {
        cout << "Error loading file" << endl;
    }

    return texture;
}

void setTitle(sf::RenderWindow& window) {
    //Draw title bar
    sf::RectangleShape titleBar(sf::Vector2f(1920, 160));
    titleBar.setFillColor(sf::Color(200, 200, 200));

    titleBar.setOutlineThickness(3.f);
    titleBar.setOutlineColor(sf::Color(90, 90, 90));
    titleBar.setPosition(0, 0);
    window.draw(titleBar);

    //Draw main title

    sf::Font font = loadFont("Montserrat-Bold.ttf");

    //Draw title
    sf::Text title;

    title.setFont(font);

    title.setString("Books Without Boundaries");
    title.setCharacterSize(60);

    //Draw Books Without Boundaries title
    sf::Texture texture1 = loadTexture("Title.png");
    sf::Sprite bwbTitle(texture1);
    bwbTitle.setPosition(0, 0);
    bwbTitle.scale(sf::Vector2f(1.00f, 1.00f));
    window.draw(bwbTitle);

    //UFBWB LOGO
    sf::Texture texture2 = loadTexture("BWBUFLogo.png");
    sf::Sprite BWBUF(texture2);
    //Second Image POS
    BWBUF.setPosition(1600, 80);
    BWBUF.scale(sf::Vector2f(1.00f, 1.00f));
    window.draw(BWBUF);

    title.setFillColor(sf::Color(128, 0, 32));
    title.setPosition(250, 35);

    // window.draw(title);

}

void setLoginBox(sf::RenderWindow& window, sf::RectangleShape& usernameBox, sf::RectangleShape& passwordBox) {
    sf::RectangleShape loginBox(sf::Vector2f(500, 350));
    loginBox.setFillColor(sf::Color(200, 200, 200));
    loginBox.setOutlineThickness(3.f);
    loginBox.setOutlineColor(sf::Color(90, 90, 90));
    loginBox.setPosition(710, 600);
    window.draw(loginBox);

    usernameBox.setFillColor(sf::Color::White);
    usernameBox.setOutlineThickness(2.f);
    usernameBox.setOutlineColor(sf::Color(90, 90, 90));
    usernameBox.setPosition(900, 640);
    window.draw(usernameBox);

    passwordBox.setFillColor(sf::Color::White);
    passwordBox.setOutlineThickness(2.f);
    passwordBox.setOutlineColor(sf::Color(90, 90, 90));
    passwordBox.setPosition(900, 740);
    window.draw(passwordBox);

    sf::Font upFont = loadFont("times new roman.ttf");

    //Draw username string
    sf::Text username;

    username.setFont(upFont);
    username.setString("Username:");
    username.setCharacterSize(35);
    username.setFillColor(sf::Color::Black);
    username.setPosition(720, 640);

    window.draw(username);

    sf::Text password;

    password.setFont(upFont);
    password.setString("Password:");
    password.setCharacterSize(35);
    password.setFillColor(sf::Color::Black);
    password.setPosition(720, 740);

    window.draw(password);

}

void setCreateAccBox(sf::RenderWindow& window, sf::RectangleShape& usernameBox, sf::RectangleShape& passwordBox,
    sf::RectangleShape& passwordVeriBox) {
    sf::RectangleShape loginBox(sf::Vector2f(500, 400));
    loginBox.setFillColor(sf::Color(200, 200, 200));
    loginBox.setOutlineThickness(3.f);
    loginBox.setOutlineColor(sf::Color(90, 90, 90));
    loginBox.setPosition(710, 400);
    window.draw(loginBox);

    usernameBox.setFillColor(sf::Color::White);
    usernameBox.setOutlineThickness(2.f);
    usernameBox.setOutlineColor(sf::Color(90, 90, 90));
    usernameBox.setPosition(900, 440);
    window.draw(usernameBox);

    passwordBox.setFillColor(sf::Color::White);
    passwordBox.setOutlineThickness(2.f);
    passwordBox.setOutlineColor(sf::Color(90, 90, 90));
    passwordBox.setPosition(900, 540);
    window.draw(passwordBox);

    passwordVeriBox.setFillColor(sf::Color::White);
    passwordVeriBox.setOutlineThickness(2.f);
    passwordVeriBox.setOutlineColor(sf::Color(90, 90, 90));
    passwordVeriBox.setPosition(900, 640);
    window.draw(passwordVeriBox);

    sf::Font upFont = loadFont("times new roman.ttf");

    //Draw username string
    sf::Text username;

    username.setFont(upFont);
    username.setString("Username:");
    username.setCharacterSize(35);
    username.setFillColor(sf::Color::Black);
    username.setPosition(720, 440);

    window.draw(username);

    sf::Text password;

    password.setFont(upFont);
    password.setString("Password:");
    password.setCharacterSize(35);
    password.setFillColor(sf::Color::Black);
    password.setPosition(720, 540);

    window.draw(password);

    sf::Text passwordVeri;
    passwordVeri.setFont(upFont);
    passwordVeri.setString("Confirm\nPassword:");
    passwordVeri.setCharacterSize(35);
    passwordVeri.setFillColor(sf::Color::Black);
    passwordVeri.setPosition(720, 620);

    window.draw(passwordVeri);
}

void ShowBooks(sf::RenderWindow& window) {
    Book currBook;

    sf::Font outFont = loadFont("times new roman.ttf");

    bool available;
    sf::Text BookList;
    sf::Text BookData;
    sf::Text TextAvailability;
    BookList.setFont(outFont);
    BookList.setCharacterSize(30);
    BookList.setFillColor(sf::Color::Black);

    TextAvailability.setFont(outFont);
    TextAvailability.setCharacterSize(30);

    float y_pos = 350;
    float prevBook = 0;

    vector<Book> bookDisplay = currBook.getBookCollection();

    for (int i = 0; i < bookDisplay.size(); i++) {
        available = bookDisplay[i].availability;

        BookList.setString(to_string(i + 1) + " : " + bookDisplay[i].name + " - " + bookDisplay[i].author + "\n     Year: " + bookDisplay[i].year + "  | Rating: " + bookDisplay[i].rating);

        if (available) {
            TextAvailability.setString("Available");
            TextAvailability.setFillColor(sf::Color(0, 100, 0));
        }

        else {
            TextAvailability.setString("Not Available");
            TextAvailability.setFillColor(sf::Color::Red);

        }


        BookList.setPosition(sf::Vector2f(100, y_pos));
        TextAvailability.setPosition(sf::Vector2f((110 + BookList.getGlobalBounds().width), y_pos));
        window.draw(BookList);
        window.draw(TextAvailability);

        prevBook = BookList.getGlobalBounds().height;
        y_pos += 15 + prevBook;

    }
}

void LoadMainWindow(sf::RenderWindow& window, sf::RectangleShape& usernameBox, sf::RectangleShape& passwordBox) {

    setTitle(window);

    setLoginBox(window, usernameBox, passwordBox);
}

void LoadCreateAccWindow(sf::RenderWindow& window, sf::RectangleShape& usernameBox, sf::RectangleShape& passwordBox,
    sf::RectangleShape& passwordVeriBox) {

    setTitle(window);

    setCreateAccBox(window, usernameBox, passwordBox, passwordVeriBox);

}

void LoadLoginWindow(sf::RenderWindow& window, AccessManager& control) {
    setTitle(window);

    sf::Font font = loadFont("Montserrat-Bold.ttf");
    sf::Text welcomeText;

    welcomeText.setFont(font);
    welcomeText.setCharacterSize(45);
    welcomeText.setPosition(sf::Vector2f(30, 200));
    welcomeText.setFillColor(sf::Color::White);
    welcomeText.setString("Welcome, " + control.activeUser.getUsername());


    window.draw(welcomeText);
}

void LoadCheckOutWindow(sf::RenderWindow& window) {
    setTitle(window);

    sf::Font font = loadFont("Montserrat-Bold.ttf");
    sf::Font outFont = loadFont("times new roman.ttf");
    sf::Text welcomeText;

    welcomeText.setFont(font);
    welcomeText.setCharacterSize(45);
    welcomeText.setPosition(sf::Vector2f(10, 200));
    welcomeText.setFillColor(sf::Color::Blue);
    welcomeText.setString("Book Checkout List");

    sf::RectangleShape checkOutBox(sf::Vector2f(1200, 600));
    checkOutBox.setFillColor(sf::Color::White);
    checkOutBox.setOutlineThickness(3.f);
    checkOutBox.setOutlineColor(sf::Color(90, 90, 90));
    checkOutBox.setPosition(50, 325);

    window.draw(welcomeText);
    window.draw(checkOutBox);

    ShowBooks(window);
}

void LoadCheckOutWindowHis(sf::RenderWindow& window, AccessManager& control) {
    setTitle(window);

    sf::Font font = loadFont("Montserrat-Bold.ttf");
    sf::Text welcomeText;

    welcomeText.setFont(font);
    welcomeText.setCharacterSize(45);
    welcomeText.setPosition(sf::Vector2f(10, 200));
    welcomeText.setFillColor(sf::Color::Blue);
    welcomeText.setString(control.activeUser.getUsername() + "'s checkout history");

    window.draw(welcomeText);
}

void LoadReturnWin(sf::RenderWindow& window, AccessManager& control) {
    setTitle(window);

    sf::Font font = loadFont("Montserrat-Bold.ttf");
    sf::Text welcomeText;

    welcomeText.setFont(font);
    welcomeText.setCharacterSize(45);
    welcomeText.setPosition(sf::Vector2f(10, 200));
    welcomeText.setFillColor(sf::Color::Blue);

    welcomeText.setString("Return A Book");

    window.draw(welcomeText);
}
void LoadActiveCheckout(sf::RenderWindow& window, sf::RectangleShape& checkOutBox) {
    setTitle(window);

    sf::Font font = loadFont("times new roman.ttf");
    sf::Text checkConf;
    checkConf.setFont(font);
    checkConf.setCharacterSize(40);
    checkConf.setPosition(sf::Vector2f(425, 200));
    checkConf.setFillColor(sf::Color::Black);
    checkConf.setString("Enter the number of the book you would like to check out.");

    window.draw(checkConf);

    checkOutBox.setFillColor(sf::Color::White);
    checkOutBox.setOutlineThickness(2.f);
    checkOutBox.setOutlineColor(sf::Color(90, 90, 90));
    checkOutBox.setPosition(900, 450);
    window.draw(checkOutBox);
}

bool VerifyCreateAcc(sf::RenderWindow& window, AccessManager& control, textBox& userText, textBox& passText,
    textBox& passVeriText, string& errorMessage) {

    string username = userText.getText();
    string password = passText.getText();
    string passwordVeri = passVeriText.getText();


    sf::Font font = loadFont("times new roman.ttf");


    if (password != passwordVeri) {
        errorMessage = "Passwords do not match. Please try again.";
        return false;
    }

    else {
        string signUpMessage = control.SignUp(username, password);
        if (signUpMessage != "Successfully created account!") {
            errorMessage = signUpMessage;
            return false;
        }

        else
            return true;

    }
}

bool VerifyLogin(sf::RenderWindow& window, AccessManager& control, textBox& username, textBox& password) {
    string user = username.getText();
    string pass = password.getText();

    control.logIn(user, pass);

    return control.loggedIn;
}

void DrawErrorMessage(sf::RenderWindow& window, sf::Vector2f posB, bool status, string message) {
    sf::Font outFont = loadFont("times new roman.ttf");

    //error box if there is an issue
    sf::RectangleShape errorBox(sf::Vector2f(650, 50));
    errorBox.setOutlineThickness(3.f);
    errorBox.setPosition(posB);

    sf::Text errorMessage;
    errorMessage.setFont(outFont);
    errorMessage.setCharacterSize(20);
    errorMessage.setFillColor(sf::Color::Black);
    errorMessage.setString(message);
    //put message in the middle of the error box
    float x = (posB.x + errorBox.getGlobalBounds().width / 2) - (errorMessage.getGlobalBounds().width / 2);
    float y = -10 + (posB.y + errorBox.getGlobalBounds().height / 2) - (errorMessage.getGlobalBounds().height / 2);
    errorMessage.setPosition(x, y);

    //error message box
    if (!status) {
        errorBox.setFillColor(sf::Color(255, 228, 228));
        errorBox.setOutlineColor(sf::Color::Red);
    }

    //confirmation message
    else {
        errorBox.setFillColor(sf::Color(144, 238, 144));
        errorBox.setOutlineColor(sf::Color::Green);
    }

    window.draw(errorBox);
    window.draw(errorMessage);
}

int main(int argc, char const** argv) {
    AccessManager control;

    //booleans to check which window to load
    bool mainWinOpen = true;
    bool createAccWinOpen = false;
    bool loginWinOpen = false;
    bool checkOutBook = false;
    bool ViewHistroy = false;
    bool activeCheckout = false;

    bool setVerification; //checks whether verification box should be displayed
    bool setVerificationLog = false; //checks whether login was successful
    bool accCreated = false; //checks whether an account was properly created
    bool enteredClickCA = false;
    bool enteredClickL = false;
    bool loggedIn;
    //Booleans for checkout
    bool checkIfCheckedOut = false;
    bool verifyCheck = false;
    bool ReturnWin = false; 
    bool isReturnDone = false; 

    auto window = sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "Books Without Boundaries");

    //user input font
    sf::Text output;
    sf::Font outFont = loadFont("times new roman.ttf");
    output.setFont(outFont);

    //set position for any additional text boxes
    sf::Vector2f posB;

    //string for any error or confirmation messages
    string errorMessage;

    /* MAIN WINDOW TEXTURES AND FONTS*/
        /*sf::Texture texture = loadTexture("BWB logo.png");
        sf::Sprite logo(texture);
        logo.setPosition(690, 170);
        logo.scale(sf::Vector2f(0.75f, 0.75f));*/

        //Draw Background
    sf::Texture texture2 = loadTexture("background.png");
    sf::Sprite background(texture2);
    background.setPosition(0, 163);
    background.scale(sf::Vector2f(1.00f, 1.00f));


    //username and password text creation
    sf::RectangleShape usernameBox(sf::Vector2f(275, 50));
    sf::RectangleShape passwordBox(sf::Vector2f(275, 50));

    textBox userText(false);
    textBox passText(false);

    userText.setFont(outFont);
    passText.setFont(outFont);
    userText.setPosition(sf::Vector2f(905, 647));
    passText.setPosition(sf::Vector2f(905, 747));

    //create account and login button creation
    Button createAcc("Create Account", { 200, 50 }, 25);
    Button loginB("Login", { 200,50 }, 25);
    createAcc.setFont(outFont);
    createAcc.setPosition(sf::Vector2f(750, 840));
    loginB.setFont(outFont);
    loginB.setPosition(sf::Vector2f(970, 840));

    /*CREATE ACCOUNT WINDOW TEXTURES AND FONTS*/
    sf::RectangleShape passVeriBox(sf::Vector2f(275, 50));
    textBox passVeriText(false);

    passVeriText.setFont(outFont);
    passVeriText.setPosition(sf::Vector2f(905, 647));

    Button createAcc2("Create Account", { 200, 50 }, 25);
    createAcc2.setFont(outFont);
    createAcc2.setPosition(sf::Vector2f(850, 740));

    Button verifyUser("Ok", { 50, 25 }, 25);
    verifyUser.setFont(outFont);
    verifyUser.setPosition(sf::Vector2f(850, 200));

    //Username and password requirements
    sf::Text requirements;
    requirements.setFont(outFont);
    requirements.setString("*Username requires minimum 6 and maximum 16 characters.Supports lowercase letters, uppercase letters, numbers, and underscores.\n*Password requires minimum 6 and maximum 16 characters, at least one uppercase letter, one lowercase letter, one number and one special character");
    requirements.setCharacterSize(20);
    requirements.setFillColor(sf::Color::Black);
    requirements.setPosition(410, 850);

    /*LOGIN WINDOOW TEXTURES AND FONTS*/
    Button signOut("Log Out", { 100, 30 }, 25);
    signOut.setFont(outFont);
    signOut.setPosition(sf::Vector2f(15, 300));

    Button RentBook("Check out a book now", { 400, 70 }, 40);
    RentBook.setFont(outFont);
    RentBook.setPosition(sf::Vector2f(400, 700));

    Button CheckHistroy("View your checkout history", { 500, 70 }, 40);
    CheckHistroy.setFont(outFont);
    CheckHistroy.setPosition(sf::Vector2f(1200, 700));

    Button back("Back", { 100, 30 }, 25);
    back.setFont(outFont);
    back.setPosition(sf::Vector2f(10, 980));

    Button checkOut("Check Out", { 150, 30 }, 25);
    checkOut.setFont(outFont);
    checkOut.setPosition(sf::Vector2f(900, 980));

    //Button for checkout on active checkout page
    Button checkOutB("Check Out", { 400, 50 }, 40);
    checkOutB.setFont(outFont);
    checkOutB.setPosition(sf::Vector2f(725, 550));
    checkOutB.setClicked(false);

    Button returnAbook("Return A Book", { 450, 50 }, 40);
    returnAbook.setFont(outFont);
    returnAbook.setPosition(sf::Vector2f(800, 500));

    Button returnAction("Return This Book", { 400, 50 }, 40);
    returnAction.setFont(outFont);
    returnAction.setPosition(sf::Vector2f(500, 500));

    //textbox for checkout
    sf::RectangleShape checkOutBox(sf::Vector2f(75, 50));
    textBox checkText(false);
    checkText.setFont(outFont);
    checkText.setPosition(sf::Vector2f(925, 450));


    /*MAIN SFML FUNCTION WITH WINDOW*/
    while (window.isOpen()) {
        vector<Book> allBooks = Book::getBookCollection();

        sf::Event event;
        auto mousePos = sf::Mouse::getPosition(window);

        //check if user clicks on text boxes
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (usernameBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                passText.setSelected(false);
                passVeriText.setSelected(false);
                userText.setSelected(true);
            }

            else if (passwordBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                userText.setSelected(false);
                passVeriText.setSelected(false);
                passText.setSelected(true);
                checkText.setSelected(false);
            }

            else if (passVeriBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                userText.setSelected(false);
                passText.setSelected(false);
                passVeriText.setSelected(true);
                checkText.setSelected(false);
            }

            else if (checkOutBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                userText.setSelected(false);
                passText.setSelected(false);
                passVeriText.setSelected(false);
                checkText.setSelected(true);
            }
        }


        while (window.pollEvent(event)) {
            switch (event.type) {
                // "close requested" event: we close the window
            case sf::Event::Closed:
                window.close();

                //check if username or password is being typed
            case sf::Event::TextEntered:
                userText.typedOn(event);
                passText.typedOn(event);
                passVeriText.typedOn(event);
                checkText.typedOn(event);
                break;

            case sf::Event::MouseMoved:
                if (mainWinOpen) {
                    if (createAcc.isMouseTouching(window)) {
                        createAcc.setBgColor(sf::Color(200, 200, 200));
                    }

                    else if (loginB.isMouseTouching(window)) {
                        loginB.setBgColor(sf::Color(200, 200, 200));
                    }

                    else {
                        createAcc.setBgColor(sf::Color(220, 220, 220));
                        loginB.setBgColor(sf::Color(220, 220, 220));
                    }
                }

                if (createAccWinOpen) {
                    if (createAcc2.isMouseTouching(window)) {
                        createAcc2.setBgColor(sf::Color(200, 200, 200));
                    }

                    else {
                        createAcc2.setBgColor(sf::Color(220, 220, 200));
                    }

                    if (back.isMouseTouching(window)) {
                        back.setBgColor(sf::Color(200, 200, 200));
                    }

                    else {
                        back.setBgColor(sf::Color(220, 220, 220));
                    }
                }

                if (loginWinOpen) {
                    if (signOut.isMouseTouching(window)) {
                        signOut.setBgColor(sf::Color(200, 200, 200));
                    }

                    else {
                        signOut.setBgColor(sf::Color(220, 220, 220));
                    }
                    if (RentBook.isMouseTouching(window)) {
                        RentBook.setBgColor(sf::Color(200, 200, 200));
                    }

                    else {
                        RentBook.setBgColor(sf::Color(220, 220, 220));
                    }
                    if (CheckHistroy.isMouseTouching(window)) {
                        CheckHistroy.setBgColor(sf::Color(200, 200, 200));
                    }

                    else {
                        CheckHistroy.setBgColor(sf::Color(220, 220, 220));

                    }
                    if (returnAbook.isMouseTouching(window)) {

                        returnAbook.setBgColor(sf::Color(200, 200, 200));

                    }
                    else {
                        returnAbook.setBgColor(sf::Color(220, 220, 220));
                    }
                }

                if (checkOutBook) {
                    if (back.isMouseTouching(window)) {
                        back.setBgColor(sf::Color(200, 200, 200));
                    }

                    else {
                        back.setBgColor(sf::Color(220, 220, 220));
                    }

                    if (checkOut.isMouseTouching(window)) {
                        checkOut.setBgColor(sf::Color(200, 200, 200));
                    }

                    else {
                        checkOut.setBgColor(sf::Color(220, 220, 220));
                    }

                }

                if (ViewHistroy) {
                    if (back.isMouseTouching(window)) {
                        back.setBgColor(sf::Color(200, 200, 200));
                    }

                    else {
                        back.setBgColor(sf::Color(220, 220, 220));
                    }
                }
                if (ReturnWin) {
                    if (returnAction.isMouseTouching(window)) {
                        returnAction.setBgColor(sf::Color(200, 200, 200));
                    }
                    else {
                        returnAction.setBgColor(sf::Color(220, 220, 220));
                    }
                }

                if (activeCheckout) {
                    if (back.isMouseTouching(window)) {
                        back.setBgColor(sf::Color(200, 200, 200));
                    }

                    else {
                        back.setBgColor(sf::Color(220, 220, 220));
                    }

                    if (checkOutB.isMouseTouching(window)) {
                        checkOutB.setBgColor(sf::Color(200, 200, 200));
                    }

                    else {
                        checkOutB.setBgColor(sf::Color(220, 220, 220));
                    }
                }

            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                    if (mainWinOpen) {
                        if (createAcc.isMouseTouching(window)) {
                            createAccWinOpen = true;
                            loginWinOpen = false;
                            mainWinOpen = false;

                            userText.clear();
                            passText.clear();
                            passVeriText.clear();

                            userText.setPosition(sf::Vector2f(905, 447));
                            passText.setPosition(sf::Vector2f(905, 547));
                        }

                        //HAVE TO VERIFY BEFORE GOING TO LOGIN PAGE
                        else if (loginB.isMouseTouching(window)) {
                            loginB.setClicked(true);
                        }
                    }

                    if (createAccWinOpen) {
                        if (createAcc2.isMouseTouching(window)) {
                            setVerification = true;
                            createAcc2.setClicked(true);
                        }

                        if (back.isMouseTouching(window)) {
                            mainWinOpen = true;
                            createAccWinOpen = false;
                        }

                    }

                    if (loginWinOpen) {
                        if (signOut.isMouseTouching(window)) {
                            control.logOut();
                            loginWinOpen = false;
                            mainWinOpen = true;

                            userText.clear();
                            passText.clear();

                            signOut.setClicked(true);
                        }
                        if (RentBook.isMouseTouching(window)) {
                            loginWinOpen = false;
                            checkOutBook = true;
                            RentBook.setClicked(true);
                        }
                        if (CheckHistroy.isMouseTouching(window)) {
                            loginWinOpen = false;
                            ViewHistroy = true;
                            CheckHistroy.setClicked(true);

                        }
                        if (returnAbook.isMouseTouching(window)) {
                            loginWinOpen = false;
                            ReturnWin = true;
                            returnAbook.setClicked(true);
                        }
                    }

                    if (checkOutBook) {
                        if (back.isMouseTouching(window)) {
                            loginWinOpen = true;
                            checkOutBook = false;
                        }

                        if (checkOut.isMouseTouching(window)) {
                            checkOutBook = false;
                            activeCheckout = true;
                        }
                    }

                    if (ViewHistroy) {
                        if (back.isMouseTouching(window)) {
                            loginWinOpen = true;
                            ViewHistroy = false;
                        }
                    }

                    if (ReturnWin) {
                        if (back.isMouseTouching(window)) {
                            loginWinOpen = true;
                            ReturnWin = false;
                        }
                        if (returnAction.isMouseTouching(window)) {
                            loginWinOpen = false;
                            isReturnDone = true;
                            returnAction.setClicked(true);
                        }
                    }

                    if (activeCheckout) {
                        if (back.isMouseTouching(window)) {
                            checkOutBook = true;
                            activeCheckout = false;
                        }

                        if (checkOutB.isMouseTouching(window)) {
                            checkOutB.setClicked(true);
                        }
                    }
                }
            }

        }

        window.clear(sf::Color(220, 220, 220));


        if (loginB.getClicked()) {
            enteredClickL = true;
            setVerificationLog = VerifyLogin(window, control, userText, passText);

            if (setVerificationLog) {
                loginWinOpen = true;
                createAccWinOpen = false;
                mainWinOpen = false;
            }

            loginB.setClicked(false);
        }

        if (mainWinOpen) {
            userText.setPosition(sf::Vector2f(905, 647));
            passText.setPosition(sf::Vector2f(905, 747));

            window.draw(background);
            LoadMainWindow(window, usernameBox, passwordBox);
            userText.drawTo(window);
            passText.drawTo(window);
            createAcc.drawTo(window);
            loginB.drawTo(window);
            //window.draw(logo);

            posB = { 650, 970 };

            if (enteredClickL && !setVerificationLog) {
                DrawErrorMessage(window, posB, false, "Username or password is incorrect");
            }
        }

        if (createAccWinOpen) {
            enteredClickL = false;

            LoadCreateAccWindow(window, usernameBox, passwordBox, passVeriBox);
            back.drawTo(window);
            userText.drawTo(window);
            passText.drawTo(window);
            passVeriText.drawTo(window);
            createAcc2.drawTo(window);
            window.draw(requirements);


            posB = { 650, 300 };

            if (createAcc2.getClicked()) {
                enteredClickCA = true;

                accCreated = VerifyCreateAcc(window, control, userText, passText, passVeriText, errorMessage);

                if (!accCreated) {
                    setVerification = false;
                }

                else {
                    //Go back to the main window. 
                    loginWinOpen = false;
                    createAccWinOpen = false;
                    mainWinOpen = true;
                    accCreated = false;
                    userText.clear();
                    passText.clear();

                    setVerification = true;
                }

                createAcc2.setClicked(false);
            }

            if (enteredClickCA) {
                if (!setVerification)
                    DrawErrorMessage(window, posB, false, errorMessage);

            }

        }

        if (loginWinOpen) {
            //sf::Texture texture_login = loadTexture("UF.png"); 
            //sf::Sprite logo_login(texture_login); 

            sf::Texture texture_login = loadTexture("LoginWindow.png");
            sf::Sprite logo_login(texture_login);
            logo_login.setPosition(0, 163);
            logo_login.scale(sf::Vector2f(1.00f, 1.00f));

            window.draw(logo_login);
            LoadLoginWindow(window, control);

            signOut.drawTo(window);
            RentBook.drawTo(window);
            CheckHistroy.drawTo(window);
            returnAbook.drawTo(window); 
        }


        if (checkOutBook) {
            //First Image being loaded...
            sf::Texture texture_checkout = loadTexture("Library.png");
            sf::Sprite logo_checkout(texture_checkout);
            //First Image POS
            logo_checkout.setPosition(1400, 160);
            logo_checkout.scale(sf::Vector2f(1.00f, 1.00f));

            LoadCheckOutWindow(window);
            window.draw(logo_checkout);
            back.drawTo(window);
            checkOut.drawTo(window);
        }

        if (ViewHistroy) {
            sf::Texture texture_checkoutHis = loadTexture("UF.png");
            sf::Sprite logo_checkoutHis(texture_checkoutHis);
            logo_checkoutHis.setPosition(1430, 170);
            logo_checkoutHis.scale(sf::Vector2f(1.00f, 1.00f));

            float y_pos = 450;
            float prevBook = 0;
            sf::Text userHistory;

            userHistory.setFont(outFont);
            userHistory.setCharacterSize(35);
            userHistory.setFillColor(sf::Color::Black);
            userHistory.setPosition(720, 640);

            LoadCheckOutWindowHis(window, control);
            window.draw(logo_checkoutHis);
            back.drawTo(window);

            vector<string> dispHis = control.activeUser.getCheckoutHistory();

            for (int i = 0; i < dispHis.size(); i++) {
                userHistory.setString(to_string(i + 1) + " : " + Book(dispHis[i]).name + "      " + Book(dispHis[i]).author);
                userHistory.setPosition(sf::Vector2f(400, y_pos));


                window.draw(userHistory);

                prevBook = userHistory.getGlobalBounds().height;
                y_pos += 15 + prevBook;

            }

        }

        if (activeCheckout) {
            LoadActiveCheckout(window, checkOutBox);
            checkText.drawTo(window);
            checkOutB.drawTo(window);
            back.drawTo(window);

            posB = { 600, 300 };

            if (checkOutB.getClicked()) {
                string bookChecked = checkText.getText();

                int bookNum = stoi(bookChecked);

                checkIfCheckedOut = true;

                if (bookNum <= allBooks.size() && bookNum > 0) {
                    verifyCheck = control.activeUser.checkoutBook(allBooks[bookNum - 1].isbn);
                }

                else {
                    verifyCheck = false;
                }

                checkOutB.setClicked(false);
            }

            if (checkIfCheckedOut && verifyCheck) {
                DrawErrorMessage(window, posB, true, "Book successfully checked out!");
            }

            else if (checkIfCheckedOut && !verifyCheck) {
                DrawErrorMessage(window, posB, false, "This book is not available.");
            }

        }

        if(ReturnWin) {
            sf::Texture texture_return = loadTexture("Library.png");
            sf::Sprite logo_return(texture_return);
            sf::Text text;
            text.setFont(outFont);
            text.setCharacterSize(35);
            text.setFillColor(sf::Color::Black);
            text.setPosition(200, 300);

            string getIsbn = control.activeUser.getCurrentCheckout();
            logo_return.setPosition(1400, 160);
            logo_return.scale(sf::Vector2f(1.00f, 1.00f));

            if (getIsbn != "-1") {
                text.setString("Your current checkout book: \n " + Book(getIsbn).name);
            }
            else {
                text.setString("You don't have anything currently checked out.");
            }

            if (isReturnDone) {
                control.activeUser.returnBook();
                text.setString("Successfully returned the book, Have a great day!");
            }

            LoadReturnWin(window, control);
            returnAction.drawTo(window);
            window.draw(text);
            window.draw(logo_return);
            back.drawTo(window);

        }

        window.display();
    }

    return 0;
}


