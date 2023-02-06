#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include <windows.h>

#include <iostream>
#include <string>
#include <cstdio>

#pragma execution_character_set( "utf-8" )

int main()
{
    int showsquare = 0;

    int posx = 25;
    int posy = 200;

    SetConsoleOutputCP(65001);
    srand(time(0));
    
    Vector2f gravity(0, 1.0);
    sfp::World world(gravity);

    sf::Clock clock;
    sf::Time lastTime = clock.getElapsedTime();

    sf::RenderWindow window(sf::VideoMode(800, 600), "AlgoRush v0.1 (Square Testing)");

    sf::Event event;

    //Création d'un carré
    sf::RectangleShape square(sf::Vector2f(100, 100));
    square.setFillColor(sf::Color::Green);
    square.setPosition(50, 50);

    sf::RectangleShape square3(sf::Vector2f(100, 100));
    square3.setFillColor(sf::Color::Red);
    square3.setPosition(200, 50);

    std::vector<sf::RectangleShape> squares;

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::MouseButtonPressed && square.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
            {
                sf::RectangleShape square2(sf::Vector2f(50, 50));
                square2.setFillColor(sf::Color::Green);
                square2.setPosition(posx, posy);
                squares.push_back(square2);
                posx += 60;
                std::cout << "Hello World!" << std::endl;
            }

            if (event.type == sf::Event::MouseButtonPressed && square3.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y))
            { 
                sf::RectangleShape square4(sf::Vector2f(50, 50));
                square4.setFillColor(sf::Color::Red);
                square4.setPosition(posx, posy);
                squares.push_back(square4);
                posx += 60;
                std::cout << "Hello World2!" << std::endl;
            }

            if (posx > 790) {
                posx = 25;
                posy += 60;
            }
        }

        window.clear();
        window.draw(square);
        window.draw(square3);
        for (const auto& s : squares)
            window.draw(s);
        window.display();
    }

    return 0;
}