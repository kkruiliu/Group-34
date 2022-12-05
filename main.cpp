#include "AccessManager.h"
#include "Button.h"
#include "textBox.h"
#include "User.h"
#include <SFML/Graphics.hpp>
#include <iostream>

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

    title.setFillColor(sf::Color(128, 0, 32));
    title.setPosition(250, 35);

    window.draw(title);
    
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
    welcomeText.setPosition(sf::Vector2f(10, 200));
    welcomeText.setFillColor(sf::Color::Blue);
    welcomeText.setString("Welcome, " + control.activeUser.getUsername());

    window.draw(welcomeText);
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
    errorMessage.setPosition(x,y);

    //error message box
    if (!status) {
        errorBox.setFillColor(sf::Color(255, 228, 228));
        errorBox.setOutlineColor(sf::Color::Red);
    }

    //confirmation message
    else {
        errorBox.setFillColor(sf::Color(144,238, 144));
        errorBox.setOutlineColor(sf::Color::Green);
    }

    window.draw(errorBox);
    window.draw(errorMessage);
}

int main(int argc, char const** argv){
    AccessManager control;

    //booleans to check which window to load
    bool mainWinOpen = true;
    bool createAccWinOpen = false;
    bool loginWinOpen = false;
    bool setVerification; //checks whether verification box should be displayed
    bool setVerificationLog = false; //checks whether login was successful
    bool accCreated = false; //checks whether an account was properly created
    bool enteredClickCA = false; 
    bool enteredClickL = false;
    bool loggedIn;

    auto window = sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "Books Without Boundaries" );

    //user input font
    sf::Text output;
    sf::Font outFont = loadFont("times new roman.ttf");
    output.setFont(outFont);

    //set position for any additional text boxes
    sf::Vector2f posB;

    //string for any error or confirmation messages
    string errorMessage;

/* MAIN WINDOW TEXTURES AND FONTS*/
    sf::Texture texture = loadTexture("BWB logo.png");
    sf::Sprite logo(texture);
    logo.setPosition(690, 170);
    logo.scale(sf::Vector2f(0.75f, 0.75f));

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
    signOut.setPosition(sf::Vector2f(1750, 50));


/*MAIN SFML FUNCTION WITH WINDOW*/
    while (window.isOpen()){

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

            }

            else if (passVeriBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                userText.setSelected(false);
                passText.setSelected(false);
                passVeriText.setSelected(true);
            }
        }


        while (window.pollEvent(event)){
            switch (event.type) {
                // "close requested" event: we close the window
            case sf::Event::Closed:
                window.close();

                //check if username or password is being typed
            case sf::Event::TextEntered:
                userText.typedOn(event);
                passText.typedOn(event);
                passVeriText.typedOn(event);
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
                }

                if (loginWinOpen) {
                    if (signOut.isMouseTouching(window)) {
                        signOut.setBgColor(sf::Color(200, 200, 200));
                    }

                    else {
                        signOut.setBgColor(sf::Color(220, 220, 220));
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

            LoadMainWindow(window, usernameBox, passwordBox);
            userText.drawTo(window);
            passText.drawTo(window);
            createAcc.drawTo(window);
            loginB.drawTo(window);
            window.draw(logo);

            posB = { 650, 970 };

            if (enteredClickL && !setVerificationLog) {
                DrawErrorMessage(window, posB, false, "Username or password is incorrect");
            }
        }

        if (createAccWinOpen) {
            enteredClickL = false;

            LoadCreateAccWindow(window, usernameBox, passwordBox, passVeriBox);
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
            LoadLoginWindow(window, control);
            signOut.drawTo(window);
        }

        window.display();
    }

    return 0;
}


