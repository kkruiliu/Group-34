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

void LoadMainWindow(sf::RenderWindow& window, sf::RectangleShape& usernameBox, sf::RectangleShape& passwordBox) {

    setTitle(window);

    setLoginBox(window, usernameBox, passwordBox);
}

int main(int argc, char const** argv){

    auto window = sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "Books Without Boundaries" );

    sf::Texture texture = loadTexture("BWB logo.png");
    sf::Sprite logo(texture);
    logo.setPosition(690, 170);
    logo.scale(sf::Vector2f(0.75f, 0.75f));

    //user input 
    sf::Text output;
    sf::Font outFont = loadFont("times new roman.ttf");
    output.setFont(outFont);

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
                break;
            
            case sf::Event::MouseMoved:
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
            case sf::Event::MouseButtonPressed:
                if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

                    if (createAcc.isMouseTouching(window)) {
                        cout << "Create Account Pressed" << endl;
                    }

                    else if (loginB.isMouseTouching(window)) {
                        cout << "Login Button Pressed" << endl;
                    }
                }
            }

        }

        window.clear(sf::Color(220, 220, 220));

        LoadMainWindow(window, usernameBox, passwordBox);
        userText.drawTo(window);
        passText.drawTo(window);
        createAcc.drawTo(window);
        loginB.drawTo(window);
        window.draw(logo);

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


