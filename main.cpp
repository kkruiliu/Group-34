#include "AccessManager.h"
#include "User.h"
#include "textBox.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

sf::Font loadFont(string file) {
    sf::Font font;

    if (!font.loadFromFile(file))
    {
        cout << "Error loading file" << endl;
    }

    return font;
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

    sf::Font font = loadFont("Front_End/Montserrat-Bold.ttf");

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

    sf::RectangleShape createAccBox(sf::Vector2f(200, 50));
    createAccBox.setFillColor(sf::Color(220, 220, 220));
    createAccBox.setOutlineThickness(2.f);
    createAccBox.setOutlineColor(sf::Color(90, 90, 90));
    createAccBox.setPosition(750, 840);
    window.draw(createAccBox);

    sf::RectangleShape loginBBox(sf::Vector2f(200, 50));
    loginBBox.setFillColor(sf::Color(220, 220, 220));
    loginBBox.setOutlineThickness(2.f);
    loginBBox.setOutlineColor(sf::Color(90, 90, 90));
    loginBBox.setPosition(970, 840);
    window.draw(loginBBox);

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

    sf::Font upFont = loadFont("Front_End/times new roman.ttf");

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

    sf::Text createAcc;

    createAcc.setFont(upFont);
    createAcc.setString("Create Account");
    createAcc.setCharacterSize(25);
    createAcc.setFillColor(sf::Color::Black);
    createAcc.setPosition(765, 847);

    window.draw(createAcc);

    sf::Text login;

    login.setFont(upFont);
    login.setString("Login");
    login.setCharacterSize(25);
    login.setFillColor(sf::Color::Black);
    login.setPosition(1035, 847);

    window.draw(login);

}

void LoadMainWindow(sf::RenderWindow& window, sf::RectangleShape& usernameBox, sf::RectangleShape& passwordBox) {

    setTitle(window);

    setLoginBox(window, usernameBox, passwordBox);
}

void LeftMouseClick(sf::RenderWindow& window, sf::RectangleShape& usernameBox, 
    sf::RectangleShape& passwordBox, sf::Event& event, sf::Text& outputText) {

    string input;
    auto mousePos = sf::Mouse::getPosition(window);
    
    if (usernameBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
      
    }

    else if (passwordBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
        
        
    }

   
}

int main(int argc, char const** argv){

    auto window = sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "Books Without Boundaries" );

    //user input 
    sf::Text output;
    sf::Font outFont = loadFont("Front_End/times new roman.ttf");
    output.setFont(outFont);

    sf::RectangleShape usernameBox(sf::Vector2f(275, 50));
    sf::RectangleShape passwordBox(sf::Vector2f(275, 50));

    textBox userText(false);
    textBox passText(false);

    userText.setFont(outFont);
    passText.setFont(outFont);
    userText.setPosition(sf::Vector2f(905, 647));
    passText.setPosition(sf::Vector2f(905, 747));

    while (window.isOpen()){

        sf::Event event;
        auto mousePos = sf::Mouse::getPosition(window);

        //check if user clicks on text boxes
        if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
            if (usernameBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                passText.setSelected(false);
                userText.setSelected(true);
            }

            else if (passwordBox.getGlobalBounds().contains(mousePos.x, mousePos.y)) {
                userText.setSelected(false);
                passText.setSelected(true);

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
                
            }
        }

        window.clear(sf::Color(220, 220, 220));

        LoadMainWindow(window, usernameBox, passwordBox);
        userText.drawTo(window);
        passText.drawTo(window);

        window.display();
    }

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


