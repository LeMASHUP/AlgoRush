#include "SFML/Graphics.hpp"
#include "SFPhysics.h"
#include "BlockManager.h"

#include <iostream>
#include <string>
#include <windows.h>
#include <cstdio>

#include "Character.h"
#include "Level1.h"
#include "Level2.h"

#pragma execution_character_set( "utf-8" )

int main()
{
    SetConsoleOutputCP(65001);

    int showsquare = 0;
    int posx = 25;
    int posy = 200;

    int state = 1;
    bool levelCreated = false;

    srand(time(0));

    Vector2f gravity(0, 1.0);
    sfp::World world(gravity);

    sf::Clock clock;
    sf::Time lastTime = clock.getElapsedTime();

    sf::RenderWindow window(sf::VideoMode(1600, 920), "AlgoRush");
    window.setFramerateLimit(60);

    sf::Event event;

    //Création d'un carré
    sf::RectangleShape square(sf::Vector2f(100, 100));
    square.setFillColor(sf::Color::Green);
    square.setPosition(50, 50);

    sf::RectangleShape square3(sf::Vector2f(100, 100));
    square3.setFillColor(sf::Color::Red);
    square3.setPosition(200, 50);

    std::vector<sf::RectangleShape> squares;

    //Creation of levels and character
    //Level1 level1(&world);
    //Level2 level2(&world);
    Character character;
    BlockManager BlockManager(&world);

    while (window.isOpen()) {
        /*
        switch (state)
        {
        case 1:
        {
            if (levelCreated == false)
            {
                level2.RemovePhysics(&world);
                level1.AddPhysics(&world);
                world.AddPhysicsBody(character);
                levelCreated = true;
                break;
            }
        }
        case 2:
        {
            if (levelCreated == false)
            {
                level1.RemovePhysics(&world);
                level2.AddPhysics(&world);
                world.AddPhysicsBody(character);
                levelCreated = true;
                break;
            }
        }
        default:
            break;
        }
        */

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {

                window.close();
            }

            if (event.key.code == sf::Keyboard::D) character.forward();
            if (event.key.code == sf::Keyboard::Q) character.backward();
            if (event.key.code == sf::Keyboard::Z) character.jumpForward();
            if (event.key.code == sf::Keyboard::Space) character.jump();

            BlockManager.update(&event);
        }

        sf::Time currentTime = clock.getElapsedTime();
        unsigned long elapsedMs = (currentTime - lastTime).asMilliseconds();

        if (elapsedMs > 0) {
            lastTime = currentTime;
            world.UpdatePhysics(elapsedMs);
            window.clear(sf::Color::Black);
           /* if (state == 1)
            {
                level1.DrawLevel(&window);
                window.draw(character);
            }
            else if (state == 2)
            {
                level2.DrawLevel(&window);
                window.draw(character);
            }
            */
            BlockManager.draw(&window);
            world.VisualizeAllBounds(window);
            window.display();
        }
    }

    return 0;
}