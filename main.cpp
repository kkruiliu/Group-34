#include "AccessManager.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;

void setTitle(sf::RenderWindow& window) {
    //Draw title bar
    sf::RectangleShape titleBar(sf::Vector2f(1920, 160));
    titleBar.setFillColor(sf::Color(200, 200, 200));

    titleBar.setOutlineThickness(3.f);
    titleBar.setOutlineColor(sf::Color(90, 90, 90));
    titleBar.setPosition(0, 0);
    window.draw(titleBar);

    //Draw main title
    sf::Font font;
    if (!font.loadFromFile("Front_End/Montserrat-Bold.ttf"))
    {
        cout << "Error loading file" << endl;
    }

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

    sf::Font upFont;
    if (!upFont.loadFromFile("Front_End/times new roman.ttf"))
    {
        cout << "Error loading file" << endl;
    }

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

int main(int argc, char const** argv){


    auto window = sf::RenderWindow(sf::VideoMode({ 1920u, 1080u }), "Books Without Boundaries" );
    string input;
    sf::Text output;
    sf::RectangleShape usernameBox(sf::Vector2f(275, 50));
    sf::RectangleShape passwordBox(sf::Vector2f(275, 50));

    while (window.isOpen())
    {

        window.clear(sf::Color(220, 220, 220));

        LoadMainWindow(window, usernameBox, passwordBox);

        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
                window.close();

                if (event.type == sf::Event::TextEntered) {
                       input += event.text.unicode;
                       output.setString(input);
                }


        }

        window.draw(output);

        window.display();
    }

    AcessManager control;
    control.SignUp();
    control.LoginIn();

    return 0;
}


